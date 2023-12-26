// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Namespace.h"
#include <QLatin1String>
#include <QLatin1Char>
#include <QStringBuilder>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

QString Namespace::toBeginString() const noexcept
{
  QString result;

  auto it = mPartList.cbegin();
  const auto end = mPartList.cend();

  if(it == end){
    return result;
  }

  result.append( QLatin1String("namespace ") % *it % QLatin1String("{") );

  ++it;
  while(it != end){
    result.append( QLatin1String(" namespace ") % *it % QLatin1String("{") );
    ++it;
  }

  return result;
}

QString Namespace::toEndString() const noexcept
{
  QString result( mPartList.size(), QLatin1Char('}') );

  result += QLatin1String(" // ") % toBeginString();

  return result;
}

QString Namespace::toUsingString() const noexcept
{
  return QLatin1String("using namespace ") % toColonSeparatedString() % QLatin1Char(';');
}

bool Namespace::isValidColonSeparatedString(const QString & str) noexcept
{
  const QString nsStr = str.trimmed();

  if( nsStr.isEmpty() ){
    return false;
  }

  return true;
}

Namespace Namespace::fromColonSeparatedString(const QString& str) noexcept
{
  const QString nsStr = str.trimmed();

  assert( isValidColonSeparatedString(nsStr) );

  return Namespace( nsStr.split(QLatin1String("::"), QString::SkipEmptyParts, Qt::CaseSensitive) );
}

Namespace::Namespace(const QStringList & partList) noexcept
 : mPartList(partList)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
