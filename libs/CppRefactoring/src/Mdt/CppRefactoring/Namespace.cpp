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

}} // namespace Mdt{ namespace CppRefactoring{
