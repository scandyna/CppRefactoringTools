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
#include "Mdt/CppRefactoring/ClassName.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("isValidString")
{
  SECTION("empty name is not valid")
  {
    REQUIRE( !ClassName::isValidString("") );
    REQUIRE( !ClassName::isValidString(" ") );
    REQUIRE( !ClassName::isValidString("   ") );
  }

  SECTION("valid name")
  {
    REQUIRE( ClassName::isValidString("MyClass") );
  }
}

TEST_CASE("fromString")
{
  auto name = ClassName::fromString(" MyClass ");

  REQUIRE( name.toString() == "MyClass" );
}
