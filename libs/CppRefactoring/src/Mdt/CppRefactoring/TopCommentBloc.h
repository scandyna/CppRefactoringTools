// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_H
#define MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Top comment bloc
   */
  class MDT_CPPREFACTORING_EXPORT TopCommentBloc
  {
   public:

    TopCommentBloc() = delete;

    /*! \brief Get the string representation of this bloc
     */
    QString toString() const noexcept
    {
      return mStr;
    }

    /*! \brief Create a top comment bloc from given string
     *
     * \pre \a str must not be empty
     */
    static
    TopCommentBloc fromString(const QString & str) noexcept;

   private:

    TopCommentBloc(const QString & str) noexcept;

    QString mStr;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_H
