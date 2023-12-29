// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "TestSourceFileContent.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

namespace Mdt{ namespace CppRefactoring{

void TestSourceFileContent::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mTopCommentBloc = bloc;
}

void TestSourceFileContent::setNamespace(const Namespace & ns) noexcept
{
  mNamespace = ns;

  auto inc = IncludeStatement::fromNamespaceAndFileBaseName( ns, mClassName.toString() );
  mIncludeStatementBloc.updateOrAppendStatementByFileName(inc);
}

QString TestSourceFileContent::toString() const noexcept
{
  return getTopCommentBlocStringIf()
         % mIncludeStatementBloc.toString() % QLatin1Char('\n')
         % getUsingNamespaceIf();
}

QString TestSourceFileContent::getTopCommentBlocStringIf() const noexcept
{
  if(!mTopCommentBloc){
    return QString();
  }
  return mTopCommentBloc->toString() % QLatin1Char('\n');
}

QString TestSourceFileContent::getUsingNamespaceIf() const noexcept
{
  if(!mNamespace){
    return QString();
  }
  return QLatin1Char('\n') % mNamespace->toUsingString() % QLatin1Char('\n');
}

}} // namespace Mdt{ namespace CppRefactoring{
