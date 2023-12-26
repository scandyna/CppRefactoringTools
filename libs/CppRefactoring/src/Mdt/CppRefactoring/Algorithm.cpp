// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "Algorithm.h"
#include <QLatin1Char>

namespace Mdt{ namespace CppRefactoring{

void appendCamelCaseCharToSnakeCaseUpperString(QChar previous, QChar current, QString & out) noexcept
{
  if( previous.isLower() && current.isUpper() ){
    out.append( QLatin1Char('_') );
  }
  out.append( current.toUpper() );
}

QString snakeCaseUpperStringFromCamelCaseString(const QString & camelString) noexcept
{
  QString result;

  if( camelString.isEmpty() ){
    return result;
  }
  result.append( camelString.at(0).toUpper() );

  const auto f = [&result](QChar previous, QChar current){
    appendCamelCaseCharToSnakeCaseUpperString(previous, current, result);
  };

  forEachAdjacentPair(camelString.cbegin(), camelString.cend(), f);

  return result;
}

}} // namespace Mdt{ namespace CppRefactoring{
