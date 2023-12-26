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
#include "Mdt/CppRefactoring/Algorithm.h"
#include <QString>
#include <QStringList>

using namespace Mdt::CppRefactoring;


TEST_CASE("forEachAdjacentPair_StringList")
{
  QStringList inList;
  QStringList result;

  const auto f = [&result](const QString & a, const QString & b){
    result.append(a + b);
  };

  SECTION("empty list")
  {
    forEachAdjacentPair(inList.cbegin(), inList.cend(), f);

    REQUIRE( result.isEmpty() );
  }

  SECTION("A -> empty list")
  {
    inList << "A";

    forEachAdjacentPair(inList.cbegin(), inList.cend(), f);

    REQUIRE( result.isEmpty() );
  }

  SECTION("A,B -> AB")
  {
    inList << "A" << "B";

    forEachAdjacentPair(inList.cbegin(), inList.cend(), f);

    REQUIRE( result == QStringList{"AB"} );
  }

  SECTION("A,B,C -> AB,BC")
  {
    inList << "A" << "B" << "C";

    forEachAdjacentPair(inList.cbegin(), inList.cend(), f);

    REQUIRE( result == QStringList{"AB","BC"} );
  }
}

TEST_CASE("appendCamelCaseCharToSnakeCaseUpperString")
{
  QString result;

  SECTION("m,d -> D")
  {
    appendCamelCaseCharToSnakeCaseUpperString('m', 'd', result);

    REQUIRE( result == "D" );
  }

  SECTION("M,d -> D")
  {
    appendCamelCaseCharToSnakeCaseUpperString('M', 'd', result);

    REQUIRE( result == "D" );
  }

  SECTION("p,R -> _R")
  {
    appendCamelCaseCharToSnakeCaseUpperString('p', 'R', result);

    REQUIRE( result == "_R" );
  }
}

TEST_CASE("snakeCaseUpperStringFromCamelCaseString")
{
  SECTION("empty string")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("").isEmpty() );
  }

  SECTION("m")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("m") == "M" );
  }

  SECTION("M")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("M") == "M" );
  }

  SECTION("Cp")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("Cp") == "CP" );
  }

  SECTION("Cpp")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("Cpp") == "CPP" );
  }

  SECTION("CppR")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("CppR") == "CPP_R" );
  }

  SECTION("pR")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("pR") == "P_R" );
  }

  SECTION("CppRefactoring")
  {
    REQUIRE( snakeCaseUpperStringFromCamelCaseString("CppRefactoring") == "CPP_REFACTORING" );
  }
}
