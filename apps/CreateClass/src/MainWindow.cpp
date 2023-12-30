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

void MainWindow::setupEditorUi() noexcept
{
  connect(mUi.classNameEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setClassName);
  connect(mUi.namespaceEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setNamespace);
  connect(mUi.action_Update, &QAction::triggered, &mEditor, &CreateClassEditor::refresh);
  connect(&mEditor, &CreateClassEditor::classUpdated, this, &MainWindow::updateEditorUi);

  connect(mUi.cbUseLibraryExport, &QCheckBox::toggled, &mEditor, &CreateClassEditor::setUseLibraryExport);
  connect(mUi.libraryBaseNameEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setLibraryBaseName);
  connect(mUi.pbLibraryNameFromNamespace, &QPushButton::clicked, &mEditor, &CreateClassEditor::setLibraryBaseNameFromNamespace);
  connect(&mEditor, &CreateClassEditor::libraryBaseNameGenerated, mUi.libraryBaseNameEdit, &QLineEdit::setText);

  mEditor.setTopCommentBloc(
    QLatin1String(
      "// SPDX-License-Identifier: LGPL-3.0-or-later\n"
      "/****************************************************************************************\n"
      "**\n"
      "** MdtCppRefactoringTools\n"
      "** Tools to help C++ refactoring.\n"
      "**\n"
      "** Copyright (C) 2023-2023 Philippe Steinmann.\n"
      "**\n"
      "*****************************************************************************************/"
    )
  );
  mEditor.setTestFrameworkType(TestFrameworkType::Catch2);
  mEditor.setTestSourceFileAdditionalIncludes({QLatin1String("Catch2QString.h")});
  // mEditor.setTestSourceFileAdditionalSystemIncludes({QLatin1String("cassert")});
}
