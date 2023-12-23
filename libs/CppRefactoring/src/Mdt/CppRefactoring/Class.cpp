// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Class.h"

namespace Mdt{ namespace CppRefactoring{

Class Class::fromName(const ClassName & name) noexcept
{
  return Class(name);
}

Class::Class(const ClassName & name) noexcept
 : mName(name),
   mHeaderFileName( HeaderFileName::fromClassName(name) ),
   mSourceFileName( SourceFileName::fromClassName(name) )
{
}

}} // namespace Mdt{ namespace CppRefactoring{
