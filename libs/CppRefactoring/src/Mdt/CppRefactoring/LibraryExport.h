// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_LIBRARY_EXPORT_H
#define MDT_CPP_REFACTORING_LIBRARY_EXPORT_H

#include "Mdt/CppRefactoring/IncludeStatement.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Represents a library export macro
   *
   * \sa https://cmake.org/cmake/help/latest/module/GenerateExportHeader.html
   */
  class MDT_CPPREFACTORING_EXPORT LibraryExport
  {
   public:

    LibraryExport() = delete;

    /*! \brief Get the library base name
     *
     */
    QString libraryBaseName() const noexcept
    {
      return mLibraryBaseName;
    }

    /*! \brief Get the include statement
     */
    IncludeStatement toIncludeStatement() const noexcept;

    /*! \brief Get the usage macro string
     */
    QString toUsageMacroString() const noexcept;

    /*! \brief Make an export from given library base name
     *
     * \pre \a name must not be empty
     * \sa libraryBaseName()
     */
    static
    LibraryExport fromLibraryBaseName(const QString & name) noexcept;

   private:

    LibraryExport(const QString & libraryBaseName) noexcept;

    QString mLibraryBaseName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_LIBRARY_EXPORT_H
