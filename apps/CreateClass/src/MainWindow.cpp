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
}

void MainWindow::setupEditorUi() noexcept
{
  connect(mUi.classNameEdit, &QLineEdit::textEdited, &mEditor, &CreateClassEditor::setClassName);
  connect(mUi.action_Update, &QAction::triggered, &mEditor, &CreateClassEditor::refresh);
  connect(&mEditor, &CreateClassEditor::classUpdated, this, &MainWindow::updateEditorUi);
}
