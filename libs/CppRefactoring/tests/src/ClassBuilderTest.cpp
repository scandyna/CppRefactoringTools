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
#include "Mdt/CppRefactoring/ClassBuilder.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("makeClassName")
{
  ClassName name = ClassBuilder::makeClassName("MyClass");

  REQUIRE( name.toString() == "MyClass" );
}

TEST_CASE("makeClass")
{
  ClassEditorData data;

  data.className = "MyClass";

  Class c = ClassBuilder::makeClass(data);

  REQUIRE( c.name().toString() == "MyClass" );
}
