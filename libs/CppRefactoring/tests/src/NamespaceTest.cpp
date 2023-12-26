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

TEST_CASE("toBeginString")
{
  SECTION("Mdt")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt");

    REQUIRE( ns.toBeginString() == "namespace Mdt{" );
  }

  SECTION("Mdt::CppRefactoring")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

    REQUIRE( ns.toBeginString() == "namespace Mdt{ namespace CppRefactoring{" );
  }
}

TEST_CASE("toEndString")
{
  SECTION("Mdt")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt");

    REQUIRE( ns.toEndString() == "} // namespace Mdt{" );
  }

  SECTION("Mdt::CppRefactoring")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

    REQUIRE( ns.toEndString() == "}} // namespace Mdt{ namespace CppRefactoring{" );
  }
}

TEST_CASE("toUsingString")
{
  SECTION("Mdt")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt");

    REQUIRE( ns.toUsingString() == "using namespace Mdt;" );
  }

  SECTION("Mdt::CppRefactoring")
  {
    auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");

    REQUIRE( ns.toUsingString() == "using namespace Mdt::CppRefactoring;" );
  }
}
