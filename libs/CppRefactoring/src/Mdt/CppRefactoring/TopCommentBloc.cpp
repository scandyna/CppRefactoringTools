// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "TopCommentBloc.h"
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

TopCommentBloc TopCommentBloc::fromString(const QString & str) noexcept
{
  assert( !str.trimmed().isEmpty() );

  return TopCommentBloc(str);
}

TopCommentBloc::TopCommentBloc(const QString & str) noexcept
 : mStr(str)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
