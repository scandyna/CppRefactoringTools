// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "CreateClassEditor.h"
#include "EditorViewModel.h"
#include "Mdt/CppRefactoring/Class.h"
#include "Mdt/CppRefactoring/HeaderFileContent.h"
#include "Mdt/CppRefactoring/SourceFileContent.h"
#include "Mdt/CppRefactoring/TestSourceFileContent.h"
#include "Mdt/CppRefactoring/QRuntimeError.h"

/// #include "Mdt/CppRefactoring/CreateClassResponse.h"
#include "Mdt/CppRefactoring/CreateClass.h"

#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QStringList>

/*! \brief Main window
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:

  /*! \brief Constructor
   */
  explicit
  MainWindow(QWidget *parent = nullptr) noexcept;

 public slots:

  void updateEditorUi(const Mdt::CppRefactoring::Class & c) noexcept;
  void updateHeaderFileContentUi(const Mdt::CppRefactoring::HeaderFileContent & content) noexcept;
  void updateSourceFileContentUi(const Mdt::CppRefactoring::SourceFileContent & content) noexcept;
  void clearTestSourceFileContentUi() noexcept;
  void updateTestSourceFileContentUi(const Mdt::CppRefactoring::TestSourceFileContent & content) noexcept;
  void updateFileSystemStructureUi(const EditorViewModel & model) noexcept;

 private slots:

  void setLibraryBaseNameFromNamespace() noexcept;
  void selectTopCommentBlocTemplateFile() noexcept;
  void selectSourceFilesRootDirectory() noexcept;
  void selectTestSourceFilesDirectory() noexcept;
  void refresh() noexcept;
  void createClass() noexcept;

 private:

  void setupEditorUi() noexcept;

  bool askConfirmationToOverwriteFile(const Mdt::CppRefactoring::CreateClassResponse & response) noexcept;
  void displaySuccessMessage(const Mdt::CppRefactoring::Class & c, const Mdt::CppRefactoring::CreateClassResponse & resonse) noexcept;
  void displayErrorMessage(const Mdt::CppRefactoring::QRuntimeError & error) noexcept;

  static
  QString getFilePathListFromResponse(const Mdt::CppRefactoring::CreateClassResponse & response) noexcept;

  CreateClassEditor mEditor;
  Ui::MainWindow mUi;
};

#endif // #ifndef MAIN_WINDOW_H
