// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_BLOC_H
#define MDT_CPP_REFACTORING_INCLUDE_STATEMENT_BLOC_H

#include "Mdt/CppRefactoring/IncludeStatement.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <vector>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Bloc of include statements
   */
  class MDT_CPPREFACTORING_EXPORT IncludeStatementBloc
  {
   public:

    /*! \brief Check if this bloc is empty
     */
    bool isEmpty() const noexcept
    {
      return mList.empty();
    }

    /*! \brief Add a statement to this bloc
     */
    void appendStatement(const IncludeStatement & statement) noexcept;

    /*! \brief Get the string representation of this bloc
     */
    QString toString() const noexcept;

   private:

    std::vector<IncludeStatement> mList;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_BLOC_H
