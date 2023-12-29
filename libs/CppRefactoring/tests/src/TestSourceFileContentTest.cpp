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
#include "Mdt/CppRefactoring/TestSourceFileContent.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("toString")
{
  auto name = ClassName::fromString("MyClass");
  TestSourceFileContent content(name);
  QString expectedResult;

  SECTION("Minimal (no comment bloc, no namepsace)")
  {
    expectedResult =
      "#include \"MyClass.h\"\n";

    REQUIRE( content.toString() == expectedResult );
  }

  SECTION("Top comment bloc")
  {
    content.setTopCommentBloc( TopCommentBloc::fromString("// Top") );

    expectedResult =
      "// Top\n"
      "#include \"MyClass.h\"\n";

    REQUIRE( content.toString() == expectedResult );
  }

  SECTION("with namespace")
  {
    content.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );

    expectedResult =
      "#include \"Mdt/CppRefactoring/MyClass.h\"\n"
      "\n"
      "using namespace Mdt::CppRefactoring;\n";

    REQUIRE( content.toString() == expectedResult );
  }
}
