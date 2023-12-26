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

void HeaderFileContent::setNamespace(const Namespace & ns) noexcept
{
  mIncludeGuard.setNamespace(ns);
  mNamespace = ns;
}

QString HeaderFileContent::toString() const noexcept
{
  QString str;

  if( hasTopCommentBloc() ){
    str += mTopCommentBloc->toString() % QLatin1Char('\n');
  }

  str += mIncludeGuard.toBeginString()
      % QLatin1Char('\n')
      % getBeginNamespaceStringIf()
      % getEndNamespaceStringIf()
      % mIncludeGuard.toEndString();

  return str;
}

QString HeaderFileContent::getBeginNamespaceStringIf() const
{
  if(mNamespace){
    return mNamespace->toBeginString() % QLatin1String("\n\n");
  }
  return QString();
}

QString HeaderFileContent::getEndNamespaceStringIf() const
{
  if(mNamespace){
   return mNamespace->toEndString() % QLatin1String("\n\n");
  }
  return QString();
}

}} // namespace Mdt{ namespace CppRefactoring{
