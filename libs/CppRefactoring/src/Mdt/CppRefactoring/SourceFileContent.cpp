// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "SourceFileContent.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

namespace Mdt{ namespace CppRefactoring{

void SourceFileContent::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mTopCommentBloc = bloc;
}

void SourceFileContent::setNamespace(const Namespace & ns) noexcept
{
  mNamespace = ns;
}

QString SourceFileContent::toString() const noexcept
{
  return getTopCommentBlocStringIf()
         % mIncludeStatementBloc.toString() % QLatin1Char('\n')
         % getBeginNamespaceStringIf()
         % getEndNamespaceStringIf();
}

QString SourceFileContent::getTopCommentBlocStringIf() const noexcept
{
  if(!mTopCommentBloc){
    return QString();
  }
  return mTopCommentBloc->toString() % QLatin1Char('\n');
}

QString SourceFileContent::getBeginNamespaceStringIf() const noexcept
{
  if(mNamespace){
    return QLatin1Char('\n') % mNamespace->toBeginString() % QLatin1String("\n\n");
  }
  return QString();
}

QString SourceFileContent::getEndNamespaceStringIf() const noexcept
{
  if(mNamespace){
   return mNamespace->toEndString() % QLatin1String("\n");
  }
  return QString();
}

}} // namespace Mdt{ namespace CppRefactoring{
