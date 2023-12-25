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
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

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
