// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "ClassName.h"
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

bool ClassName::isValidString(const QString& name) noexcept
{
  const QString cnStr = name.trimmed();

  if( cnStr.isEmpty() ){
    return false;
  }

  return true;
}

ClassName ClassName::fromString(const QString& name) noexcept
{
  const QString cnStr = name.trimmed();

  assert( isValidString(cnStr) );

  return ClassName(cnStr);
}

ClassName::ClassName(const QString & name) noexcept
 : mName(name)
{
  assert( isValidString(mName) );
}

}} // namespace Mdt{ namespace CppRefactoring{
