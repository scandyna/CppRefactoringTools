// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "TestName.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

bool TestName::isValidString(const QString& name) noexcept
{
  const QString cnStr = name.trimmed();

  if( cnStr.isEmpty() ){
    return false;
  }

  return true;
}

TestName TestName::fromBaseNameString(const QString& name) noexcept
{
  const QString cnStr = name.trimmed();

  assert( isValidString(cnStr) );

  return TestName( cnStr % QLatin1String("Test") );
}

TestName TestName::fromClassName(const ClassName & name) noexcept
{
  return fromBaseNameString( name.toString() );
}

TestName::TestName(const QString& name) noexcept
 : mName(name)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
