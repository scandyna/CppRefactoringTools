// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "MainWindow.h"
#include <QAction>
#include <QLineEdit>
#include <QMessageBox>
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

using namespace Mdt::CppRefactoring;


MainWindow::MainWindow(QWidget* parent) noexcept
 : QMainWindow(parent)
{
  mUi.setupUi(this);
  setupEditorUi();
}

void MainWindow::updateEditorUi(const Class & c) noexcept
{
  mUi.classNameEdit->setText( c.name().toString() );
  mUi.headerFileNameEdit->setText( c.headerFileName().toString() );
  mUi.sourceFileNameEdit->setText( c.sourceFileName().toString() );

  if( c.isInNamespace() ){
    mUi.namespaceEdit->setText( c.ns().toColonSeparatedString() );
    mUi.sourceRelativePathEdit->setText( c.ns().toDirectoryRelativePathString() );
  }else{
    mUi.namespaceEdit->clear();
    mUi.sourceRelativePathEdit->clear();
  }

  updateHeaderFileContentUi( c.headerFileContent() );
  updateSourceFileContentUi( c.sourceFileContent() );

  if( c.hasTest() ){
    mUi.testSourceFileNameEdit->setText( c.testSourceFileName().toString() );
    updateTestSourceFileContentUi( c.testSourceFileContent() );
  }else{
    mUi.testSourceFileNameEdit->clear();
    clearTestSourceFileContentUi();
  }
}

void MainWindow::updateHeaderFileContentUi(const HeaderFileContent & content) noexcept
{
  mUi.headerFileEdit->setPlainText( content.toString() );
}

void MainWindow::updateSourceFileContentUi(const SourceFileContent & content) noexcept
{
  mUi.sourceFileEdit->setPlainText( content.toString() );
}

void MainWindow::clearTestSourceFileContentUi() noexcept
{
  mUi.testSourceFileEdit->clear();
}

void MainWindow::updateTestSourceFileContentUi(const TestSourceFileContent & content) noexcept
{
  mUi.testSourceFileEdit->setPlainText( content.toString() );
}

void MainWindow::updateFileSystemStructureUi(const EditorViewModel & model) noexcept
{
  mUi.sourceRootDirectoryPathEdit->setText( model.sourceFilesRootDirectoryAbsolutePath() );
  mUi.TestDirectoryPathEdit->setText( model.testSourceFilesDirectoryAbsolutePath() );
  mUi.headerFilePathEdit->setText( model.getHeaderFileAbsolutePath() );
  mUi.sourceFilePathEdit->setText( model.getSourceFileAbsolutePath() );
  mUi.textSourceFilePathEdit->setText( model.getTestSourceFileAbsolutePath() );
}

void MainWindow::createClass() noexcept
{
  try{
    CreateClassResponse response = mEditor.createClass(CreateClassFileOverwriteBehavior::AskConfirmation);
    if(response.isSuccess){
      displaySuccessMessage(mEditor.validClass(), response);
      return;
    }
    if( response.isAskingToOverwriteFile() ){
      bool overwrite = askConfirmationToOverwriteFile(response);
      if(!overwrite){
        return;
      }
      response = mEditor.createClass(CreateClassFileOverwriteBehavior::Overwrite);
      // Errors throws exception
      assert(response.isSuccess);
      displaySuccessMessage(mEditor.validClass(), response);
      return;
    }
  }catch(const QRuntimeError & error){
    displayErrorMessage(mEditor.validClass(), error);
  }
}

void MainWindow::setupEditorUi() noexcept
{
  connect(mUi.classNameEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setClassName);
  connect(mUi.namespaceEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setNamespace);
  connect(mUi.action_Update, &QAction::triggered, &mEditor, &CreateClassEditor::refresh);
  connect(mUi.action_Create, &QAction::triggered, this, &MainWindow::createClass);
  connect(&mEditor, &CreateClassEditor::classUpdated, this, &MainWindow::updateEditorUi);

  connect(mUi.cbUseLibraryExport, &QCheckBox::toggled, &mEditor, &CreateClassEditor::setUseLibraryExport);
  connect(mUi.libraryBaseNameEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setLibraryBaseName);
  connect(mUi.pbLibraryNameFromNamespace, &QPushButton::clicked, &mEditor, &CreateClassEditor::setLibraryBaseNameFromNamespace);
  connect(&mEditor, &CreateClassEditor::libraryBaseNameGenerated, mUi.libraryBaseNameEdit, &QLineEdit::setText);

  connect(mUi.sourceRootDirectoryPathEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setSourceFilesRootDirectoryAbsolutePath);
  connect(mUi.TestDirectoryPathEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setTestSourceFilesDirectoryAbsolutePath);
  connect(&mEditor, &CreateClassEditor::fileSystemStructureUpdated, this, &MainWindow::updateFileSystemStructureUi);

  mEditor.setTopCommentBloc(
    QLatin1String(
      "// SPDX-License-Identifier: LGPL-3.0-or-later\n"
      "/****************************************************************************************\n"
      "**\n"
      "** MdtCppRefactoringTools\n"
      "** Tools to help C++ refactoring.\n"
      "**\n"
      "** Copyright (C) 2024-2024 Philippe Steinmann.\n"
      "**\n"
      "*****************************************************************************************/"
    )
  );
  mEditor.setTestFrameworkType(TestFrameworkType::Catch2);
  mEditor.setTestSourceFileAdditionalIncludes({QLatin1String("Catch2QString.h")});
  // mEditor.setTestSourceFileAdditionalSystemIncludes({QLatin1String("cassert")});
}

bool MainWindow::askConfirmationToOverwriteFile(const CreateClassResponse & response) noexcept
{
  QString fileList;
  if(response.isAskingToOverwriteHeaderFile){
    fileList += QLatin1Char('\n') % response.headerFileAbsolutePath;
  }
  if(response.isAskingToOverwriteSourceFile){
    fileList += QLatin1Char('\n') % response.sourceFileAbsolutePath;
  }
  if(response.isAskingToOverwriteTestSourceFile){
    fileList += QLatin1Char('\n') % response.testSourceFileAbsolutePath;
  }

  QMessageBox msgBox(this);
  msgBox.setText(
    tr("Creating a class will overwrite existing files: %1")
    .arg(fileList)
  );
  msgBox.setInformativeText(
    tr("Continue and overwrite those files ?")
  );
  msgBox.setStandardButtons(QMessageBox::Cancel|QMessageBox::No|QMessageBox::Yes);
  msgBox.setDefaultButton(QMessageBox::Cancel);
  msgBox.setIcon(QMessageBox::Question);

  int ret = msgBox.exec();

  return ret == QMessageBox::Yes;
}

void MainWindow::displaySuccessMessage(const Class & c, const CreateClassResponse & resonse) noexcept
{
  QMessageBox msgBox(this);
  msgBox.setText(
    tr("Class %1 successfully created")
    .arg( c.name().toString() )
  );
  msgBox.setInformativeText(
    tr("those files have been created:\n%1")
    .arg( getFilePathListFromResponse(resonse) )
  );
  msgBox.setIcon(QMessageBox::Information);

  msgBox.exec();
}

void MainWindow::displayErrorMessage(const Class & c, const QRuntimeError & error) noexcept
{
  QMessageBox msgBox(this);
  msgBox.setText(
    tr("Failed to create class %1: %2")
    .arg( c.name().toString(), error.text() )
  );
  msgBox.setIcon(QMessageBox::Critical);

  msgBox.exec();
}

QString MainWindow::getFilePathListFromResponse(const CreateClassResponse & response) noexcept
{
  QString list = response.headerFileAbsolutePath + QLatin1Char('\n')
               + response.sourceFileAbsolutePath;

  if( !response.testSourceFileAbsolutePath.isEmpty() ){
    list += QLatin1Char('\n') + response.testSourceFileAbsolutePath;
  }

  return list;
}
