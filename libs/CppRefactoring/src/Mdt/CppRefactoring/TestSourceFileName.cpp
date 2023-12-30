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

TestSourceFileName TestSourceFileName::fromTestName(const TestName & name) noexcept
{
  return TestSourceFileName(name);
}

TestSourceFileName::TestSourceFileName(const TestName & testName) noexcept
 : mName( testName.toString() % QLatin1String(".cpp") )
{
}

}} // namespace Mdt{ namespace CppRefactoring{
