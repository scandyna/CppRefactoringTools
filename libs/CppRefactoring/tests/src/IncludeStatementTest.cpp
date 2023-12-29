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
#include "Mdt/CppRefactoring/IncludeStatement.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("fromFileBaseName")
{
  auto is = IncludeStatement::fromFileBaseName("MyClass");

  REQUIRE( is.fileName() == "MyClass.h" );
  REQUIRE( is.fileRelativePath() == "MyClass.h" );
  REQUIRE( is.toString() == "#include \"MyClass.h\"" );
}

TEST_CASE("fromNamespaceAndFileBaseName")
{
  auto ns = Namespace::fromColonSeparatedString("Mdt::CppRefactoring");
  auto is = IncludeStatement::fromNamespaceAndFileBaseName(ns, "MyClass");

  REQUIRE( is.fileName() == "MyClass.h" );
  REQUIRE( is.fileRelativePath() == "Mdt/CppRefactoring/MyClass.h" );
  REQUIRE( is.toString() == "#include \"Mdt/CppRefactoring/MyClass.h\"" );
}

TEST_CASE("from_q_char_sequence")
{
  SECTION("File.h")
  {
    auto is = IncludeStatement::from_q_char_sequence("File.h");

    REQUIRE( !is.isSystemInclude() );
    REQUIRE( is.fileName() == "File.h" );
    REQUIRE( is.fileRelativePath() == "File.h" );
  }

  SECTION("Mdt/File.h")
  {
    auto is = IncludeStatement::from_q_char_sequence("Mdt/File.h");

    REQUIRE( !is.isSystemInclude() );
    REQUIRE( is.fileName() == "File.h" );
    REQUIRE( is.fileRelativePath() == "Mdt/File.h" );
  }
}

TEST_CASE("systemIncludeFrom_h_char_sequence")
{
  SECTION("QString")
  {
    auto is = IncludeStatement::systemIncludeFrom_h_char_sequence("QString");

    REQUIRE( is.isSystemInclude() );
    REQUIRE( is.fileName() == "QString" );
    REQUIRE( is.fileRelativePath() == "QString" );
    REQUIRE( is.toString() == "#include <QString>" );
  }

  SECTION("boost/algorithm/hex.hpp")
  {
    auto is = IncludeStatement::systemIncludeFrom_h_char_sequence("boost/algorithm/hex.hpp");

    REQUIRE( is.isSystemInclude() );
    REQUIRE( is.fileName() == "hex.hpp" );
    REQUIRE( is.fileRelativePath() == "boost/algorithm/hex.hpp" );
    REQUIRE( is.toString() == "#include <boost/algorithm/hex.hpp>" );
  }
}
