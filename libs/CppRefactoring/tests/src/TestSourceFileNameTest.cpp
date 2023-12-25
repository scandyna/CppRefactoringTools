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


TEST_CASE("fromClassName")
{
  auto className = ClassName::fromString("MyClass");

  auto fileName = TestSourceFileName::fromClassName(className);

  REQUIRE( fileName.toString() == "MyClassTest.cpp" );
}
