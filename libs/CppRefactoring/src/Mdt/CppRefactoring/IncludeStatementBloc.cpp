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

namespace Mdt{ namespace CppRefactoring{

void IncludeStatementBloc::appendStatement(const IncludeStatement & statement) noexcept
{
  mList.push_back(statement);
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
