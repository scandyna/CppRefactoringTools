// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "TestSourceFileName.h"
#include <QStringBuilder>
#include <QLatin1String>

namespace Mdt{ namespace CppRefactoring{

TestSourceFileName TestSourceFileName::fromClassName(const ClassName & name) noexcept
{
  return TestSourceFileName(name);
}

TestSourceFileName::TestSourceFileName(const ClassName & className) noexcept
 : mName( className.toString() % QLatin1String("Test.cpp") )
{
}

}} // namespace Mdt{ namespace CppRefactoring{
