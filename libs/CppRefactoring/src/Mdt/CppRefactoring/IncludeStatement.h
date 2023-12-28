// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H
#define MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Reprents an include Include
   */
  class MDT_CPPREFACTORING_EXPORT IncludeStatement
  {
   public:

    IncludeStatement() = delete;

    /*! \brief Get the string representation of this statement
     */
    QString toString() const noexcept;

    /*! \brief Get an include statement from given file base name
     *
     * \pre \a name must not be empty
     */
    static
    IncludeStatement fromFileBaseName(const QString & name) noexcept;

    /*! \brief
     *
     * \todo define and implement + What about Qt/QtTest ?
     */
    static
    IncludeStatement fromQtClassName(const QString & name) noexcept;

    /*! \brief
     *
     * \todo define and implement
     */
    static
    IncludeStatement fromStdlibHeaderName(const QString & name) noexcept;

   private:

    IncludeStatement(const QString & fileBaseName) noexcept;

    QString mFileBaseName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H
