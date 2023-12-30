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
#include "Mdt/CppRefactoring/TestName.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("isValidString")
{
  SECTION("empty name is not valid")
  {
    REQUIRE( !TestName::isValidString("") );
    REQUIRE( !TestName::isValidString(" ") );
    REQUIRE( !TestName::isValidString("   ") );
  }

  SECTION("valid name")
  {
    REQUIRE( TestName::isValidString("MyClass") );
  }
}

TEST_CASE("fromBaseNameString")
{
  auto name = TestName::fromBaseNameString(" MyClass ");

  REQUIRE( name.toString() == "MyClassTest" );
}

TEST_CASE("fromClassName")
{
  auto name = TestName::fromClassName( ClassName::fromString("MyClass") );

  REQUIRE( name.toString() == "MyClassTest" );
}
