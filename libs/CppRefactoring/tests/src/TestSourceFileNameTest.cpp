// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "Mdt/CppRefactoring/TestSourceFileName.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromTestName")
{
  auto testName = TestName::fromBaseNameString("MyClass");

  auto fileName = TestSourceFileName::fromTestName(testName);

  REQUIRE( fileName.toString() == "MyClassTest.cpp" );
}
