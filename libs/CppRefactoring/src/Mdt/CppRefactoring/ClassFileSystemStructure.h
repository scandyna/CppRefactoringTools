// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_FILE_SYSTEM_STRUCTURE_H
#define MDT_CPP_REFACTORING_CLASS_FILE_SYSTEM_STRUCTURE_H

#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/Class.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Helper class to get the file locations for a class
   */
  class MDT_CPPREFACTORING_EXPORT ClassFileSystemStructure
  {
   public:

    ClassFileSystemStructure() = delete;

    /*! \brief Construct a file system structure
     */
    explicit
    ClassFileSystemStructure(const FileSystemStructure & fss) noexcept;

    /*! \brief Get the file system structure
     */
    const FileSystemStructure & fileSystemStructure() const noexcept
    {
      return mFileSystemStructure;
    }

    /*! \brief Get the absolute path to the source file
     */
    QString getSourceFileAbsolutePath(const Class & c) const noexcept;

    /*! \brief Get the absolute path to the header file
     */
    QString getHeaderFileAbsolutePath(const Class & c) const noexcept;

    /*! \brief Get the absolute path to the test source file
     */
    QString getTestSourceFileAbsolutePath(const Class & c) const noexcept;

   private:

    static
    QString getNamespaceRelativePathIf(const Class & c) noexcept;

    FileSystemStructure mFileSystemStructure;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_FILE_SYSTEM_STRUCTURE_H
