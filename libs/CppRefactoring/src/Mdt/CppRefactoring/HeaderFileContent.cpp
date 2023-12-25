// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "HeaderFileContent.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

namespace Mdt{ namespace CppRefactoring{

void HeaderFileContent::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mTopCommentBloc = bloc;
}

QString HeaderFileContent::toString() const noexcept
{
  QString str;

  if( hasTopCommentBloc() ){
    str += mTopCommentBloc->toString() % QLatin1Char('\n');
  }

  str += mIncludeGuard.toBeginString()
      % QLatin1Char('\n')
      % mIncludeGuard.toEndString();

  return str;
}

}} // namespace Mdt{ namespace CppRefactoring{
