// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "IncludeStatementBloc.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>
#include <algorithm>

namespace Mdt{ namespace CppRefactoring{

template<typename It>
It findIncludeStatementInBlocByFileRelativePathString(It first, It last, const QString & path) noexcept
{
  const auto pred = [&path](const IncludeStatement & currentStatement){
    return currentStatement.fileRelativePath() == path;
  };

  return std::find_if(first, last, pred);
}

template<typename It>
It findIncludeStatementInBloc(It first, It last, const IncludeStatement & statement) noexcept
{
  return findIncludeStatementInBlocByFileRelativePathString( first, last, statement.fileRelativePath() );
}

template<typename It>
It findIncludeStatementByNameInBloc(It first, It last, const IncludeStatement & statement) noexcept
{
  const auto pred = [&statement](const IncludeStatement & currentStatement){
    return currentStatement.fileName() == statement.fileName();
  };

  return std::find_if(first, last, pred);
}


bool IncludeStatementBloc::containsFileRelativePath(const QString & path) const noexcept
{
  const auto it = findIncludeStatementInBlocByFileRelativePathString(mList.cbegin(), mList.cend(), path);

  return it != mList.cend();
}

void IncludeStatementBloc::appendStatement(const IncludeStatement & statement) noexcept
{
  mList.push_back(statement);
}

void IncludeStatementBloc::updateOrAppendStatement(const IncludeStatement & statement) noexcept
{
  const auto it = findIncludeStatementInBloc(mList.begin(), mList.end(), statement);
  if( it == mList.end() ){
    appendStatement(statement);
  }else{
    *it = statement;
  }
}

void IncludeStatementBloc::updateOrAppendStatementByFileName(const IncludeStatement & statement) noexcept
{
  const auto it = findIncludeStatementByNameInBloc(mList.begin(), mList.end(), statement);
  if( it == mList.end() ){
    appendStatement(statement);
  }else{
    *it = statement;
  }
}

QString IncludeStatementBloc::toString() const noexcept
{
  QString result;

  auto it = mList.cbegin();
  const auto end = mList.cend();

  if(it == end){
    return result;
  }

  result = it->toString();

  ++it;
  while(it != end){
    result += QLatin1Char('\n') % it->toString();
    ++it;
  }

  return result;
}

}} // namespace Mdt{ namespace CppRefactoring{
