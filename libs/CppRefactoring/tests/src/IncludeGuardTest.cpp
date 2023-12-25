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
#include "Mdt/CppRefactoring/IncludeGuard.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("toBeginString")
{
  auto name = ClassName::fromString("MyClass");
  IncludeGuard guard(name);
  QString expectedString;

  SECTION("No namespace")
  {
    expectedString =
     "#ifndef MY_CLASS_H\n"
     "#define MY_CLASS_H\n";

    REQUIRE( guard.toBeginString() == expectedString );
  }

  SECTION("In Mdt namespace")
  {
    expectedString =
     "#ifndef MDT_MY_CLASS_H\n"
     "#define MDT_MY_CLASS_H\n";

    guard.setNamespace( Namespace::fromColonSeparatedString("Mdt") );

    REQUIRE( guard.toBeginString() == expectedString );
  }
}

TEST_CASE("toEndString")
{
  auto name = ClassName::fromString("MyClass");
  IncludeGuard guard(name);
  QString expectedString;

  SECTION("No namespace")
  {
    expectedString =
     "#endif // #ifndef MY_CLASS_H\n";

    REQUIRE( guard.toEndString() == expectedString );
  }

  SECTION("In Mdt namespace")
  {
    expectedString =
     "#endif // #ifndef MDT_MY_CLASS_H\n";

    guard.setNamespace( Namespace::fromColonSeparatedString("Mdt") );

    REQUIRE( guard.toEndString() == expectedString );
  }
}
