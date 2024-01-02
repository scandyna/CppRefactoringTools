// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_SOURCE_FILES_ROOT_DIRECTORY_H
#define MDT_CPP_REFACTORING_SOURCE_FILES_ROOT_DIRECTORY_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Source files root directory
   */
  class MDT_CPPREFACTORING_EXPORT SourceFilesRootDirectory
  {
   public:

    SourceFilesRootDirectory() = delete;

    /*! \brief Get the absolute path to this directory
     */
    QString absolutePath() const noexcept
    {
      return mAbsolutePath;
    }

    /*! \brief Check if given path is valid
     *
     * Returns true if given path refers to an existing directory.
     * \sa isValidPathToExistingDirectory()
     */
    static
    bool isValidExistingPath(const QString & path) noexcept;

    /*! \brief Create a directory from existing path
     *
     * \pre \a path must be valid and refer to and existing path
     * \sa isValidExistingPath()
     */
    static
    SourceFilesRootDirectory fromExistingPath(const QString & path) noexcept;

    /*! \brief Create a directory object from given unchecked class
     *
     * \warning This method should only be used for tests.
     * absolutePath() will return the given \a path .
     *
     * \sa fromExistingPath()
     *
     * \pre \a path must not be empty
     */
    static
    SourceFilesRootDirectory fromUncheckedPath(const QString & path) noexcept;

   private:

    SourceFilesRootDirectory(const QString & path) noexcept;

    QString mAbsolutePath;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_SOURCE_FILES_ROOT_DIRECTORY_H
