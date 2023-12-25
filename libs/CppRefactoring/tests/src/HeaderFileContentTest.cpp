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
#include "Mdt/CppRefactoring/HeaderFileContent.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("TopCommentBloc")
{
  auto name = ClassName::fromString("MyClass");
  HeaderFileContent content(name);

  SECTION("no top comment bloc by default")
  {
    REQUIRE( !content.hasTopCommentBloc() );
  }

  SECTION("set a top comment bloc")
  {
    content.setTopCommentBloc( TopCommentBloc::fromString("// Top") );

    REQUIRE( content.hasTopCommentBloc() );
  }
}

TEST_CASE("toString")
{
  auto name = ClassName::fromString("MyClass");
  HeaderFileContent content(name);
  QString expectedResult;

  SECTION("No top comment bloc")
  {
    expectedResult =
      "#ifndef MY_CLASS_H\n"
      "#define MY_CLASS_H\n"
      "\n"
      "#endif // #ifndef MY_CLASS_H\n";

    REQUIRE( content.toString() == expectedResult );
  }

  SECTION("With top comment bloc")
  {
    content.setTopCommentBloc( TopCommentBloc::fromString("// Top") );

    expectedResult =
      "// Top\n"
      "#ifndef MY_CLASS_H\n"
      "#define MY_CLASS_H\n"
      "\n"
      "#endif // #ifndef MY_CLASS_H\n";

    REQUIRE( content.toString() == expectedResult );
  }
}
