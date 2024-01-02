// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileSystemHelpers.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>
#include <QTemporaryFile>

using namespace Mdt::CppRefactoring;


TEST_CASE("isValidPathToExistingDirectory")
{
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );
  QTemporaryFile file;
  REQUIRE( file.open() );

  SECTION("empty path is not valid")
  {
    REQUIRE( !isValidPathToExistingDirectory("") );
    REQUIRE( !isValidPathToExistingDirectory(" ") );
    REQUIRE( !isValidPathToExistingDirectory("  ") );
  }

  SECTION("path to non existing entity")
  {
    REQUIRE( !isValidPathToExistingDirectory("some/arbitrary/path/that/p/ro/bably/not/exists") );
  }

  SECTION("a file is not a directory")
  {
    REQUIRE( !isValidPathToExistingDirectory( file.fileName() ) );
  }

  SECTION("path to an existing directory")
  {
    REQUIRE( isValidPathToExistingDirectory( dir.path() ) );
  }
}
