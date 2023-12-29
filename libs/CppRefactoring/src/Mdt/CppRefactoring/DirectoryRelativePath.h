// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_DIRECTORY_RELATIVE_PATH_H
#define MDT_CPP_REFACTORING_DIRECTORY_RELATIVE_PATH_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Relative path to a directory
   */
  class MDT_CPPREFACTORING_EXPORT DirectoryRelativePath
  {
   public:

    DirectoryRelativePath() = delete;

    /*! \brief Get the string representation of this path
     */
    QString toString() const noexcept;

    /*! \brief Check if given string represents a valid relative path to a directory
     */
    static
    bool isValidString(const QString & path) noexcept;

    /*! \brief Construct a path from given string
     *
     * \pre \a path must be valid
     * \sa isValidString()
     */
    static
    DirectoryRelativePath fromString(const QString & path) noexcept;

   private:
 
    DirectoryRelativePath(const QString & path) noexcept;

    QString mPath;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_DIRECTORY_RELATIVE_PATH_H
