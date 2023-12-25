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
  auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

  REQUIRE( ns.partList().size() == 2 );
  REQUIRE( ns.partList().at(0) == "Mdt" );
  REQUIRE( ns.partList().at(1) == "CppRefactoring" );
}

TEST_CASE("toColonSeparatedString")
{
  auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

  REQUIRE( ns.toColonSeparatedString() == "Mdt::CppRefactoring" );
}

TEST_CASE("toDirectoryRelativePath")
{
  auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

  REQUIRE( ns.toDirectoryRelativePath() == "Mdt/CppRefactoring" );
}
