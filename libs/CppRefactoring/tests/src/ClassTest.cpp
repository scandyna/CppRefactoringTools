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
#include "Mdt/CppRefactoring/Class.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromName")
{
  auto name = ClassName::fromString("MyClass");

  Class c = Class::fromName(name);

  REQUIRE( c.name().toString() == "MyClass" );
  REQUIRE( c.headerFileName().toString() == "MyClass.h" );
  REQUIRE( c.sourceFileName().toString() == "MyClass.cpp" );
}
