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
#include "Mdt/CppRefactoring/Namespace.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("isValidColonSeparatedString")
{
  SECTION("an empty string is not valid")
  {
    REQUIRE( !Namespace::isValidColonSeparatedString("") );
  }

  SECTION("A single item is valid")
  {
    REQUIRE( Namespace::isValidColonSeparatedString("Mdt") );
  }

  SECTION("2 items is valid")
  {
    REQUIRE( Namespace::isValidColonSeparatedString("Mdt::CppRefactoring") );
  }
}

TEST_CASE("fromColonSeparatedString")
{
  REQUIRE(false);
}
