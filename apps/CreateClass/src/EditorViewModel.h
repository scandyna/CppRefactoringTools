// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef EDITOR_VIEW_MODEL_H
#define EDITOR_VIEW_MODEL_H

#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/ClassFileSystemStructure.h"
#include "Mdt/CppRefactoring/Class.h"
#include <QString>
#include <optional>

/*! \brief Represents data to display in the editor UI
 *
 */
class EditorViewModel
{
 public:

  /*! \brief Create an empty model
   */
  EditorViewModel() noexcept = default;

  /*! \brief Set the file system structure
   */
  void setFileSystemStructure(const Mdt::CppRefactoring::FileSystemStructure & fileSystemStructure) noexcept;

  /*! \brief Set the class
   */
  void setClass(const Mdt::CppRefactoring::Class & c) noexcept;

  /*! \brief Get the absolute path to the source files directory
   */
  QString sourceFilesRootDirectoryAbsolutePath() const noexcept;

  /*! \brief Get the absolute path to the header files directory
   */
  QString headerFilesRootDirectoryAbsolutePath() const noexcept;

  /*! \brief Get the absolute path to the tests source files directory
    */
  QString testSourceFilesDirectoryAbsolutePath() const noexcept;

  /*! \brief Get the absolute path to the source file
   */
  QString getSourceFileAbsolutePath() const noexcept;

  /*! \brief Get the absolute path to the header file
   */
  QString getHeaderFileAbsolutePath() const noexcept;

  /*! \brief Get the absolute path to the test source file
   */
  QString getTestSourceFileAbsolutePath() const noexcept;

 private:

  std::optional<Mdt::CppRefactoring::ClassFileSystemStructure> mFileSystemStructure;
  std::optional<Mdt::CppRefactoring::Class> mClass;
};

#endif // #ifndef EDITOR_VIEW_MODEL_H
