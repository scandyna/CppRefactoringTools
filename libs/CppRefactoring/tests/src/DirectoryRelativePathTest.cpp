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
#include "Mdt/CppRefactoring/DirectoryRelativePath.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("isValidString")
{
  SECTION("empty")
  {
    REQUIRE( !DirectoryRelativePath::isValidString("") );
  }

  SECTION("Mdt")
  {
    REQUIRE( DirectoryRelativePath::isValidString("Mdt") );
  }

  SECTION("/Mdt")
  {
    REQUIRE( !DirectoryRelativePath::isValidString("/Mdt") );
  }
}

TEST_CASE("fromString")
{
  SECTION("Mdt")
  {
    auto path = DirectoryRelativePath::fromString("Mdt");

    REQUIRE( path.toString() == "Mdt" );
  }

  SECTION("Mdt/")
  {
    auto path = DirectoryRelativePath::fromString("Mdt/");

    REQUIRE( path.toString() == "Mdt" );
  }

  SECTION("Mdt/CppRefactoring")
  {
    auto path = DirectoryRelativePath::fromString("Mdt/CppRefactoring");

    REQUIRE( path.toString() == "Mdt/CppRefactoring" );
  }
}
