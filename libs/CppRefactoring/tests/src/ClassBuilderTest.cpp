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

  SECTION("No namespace")
  {
    data.className = "MyClass";

    Class c = ClassBuilder::makeClass(data);

    REQUIRE( c.name().toString() == "MyClass" );
    REQUIRE( !c.isInNamespace() );
    REQUIRE( !c.headerFileContent().hasTopCommentBloc() );
  }

  SECTION("In Mdt::CppRefactoring namespace")
  {
    data.className = "MyClass";
    data.namespaceStr = "Mdt::CppRefactoring";

    Class c = ClassBuilder::makeClass(data);

    REQUIRE( c.name().toString() == "MyClass" );
    REQUIRE( c.ns().toColonSeparatedString() == "Mdt::CppRefactoring" );
  }

  SECTION("Top comment bloc")
  {
    data.className = "MyClass";
    data.topCommentBloc = "// Top";

    Class c = ClassBuilder::makeClass(data);

    REQUIRE( c.headerFileContent().hasTopCommentBloc() );
  }

  SECTION("library export")
  {
    data.className = "MyClass";
    data.useLibraryExport = true;
    data.libraryBaseName = "Mdt_CppRefactoring";

    Class c = ClassBuilder::makeClass(data);

    REQUIRE( c.headerFileContent().hasLibraryExport() );
  }

  SECTION("with Catch2 test")
  {
    data.className = "MyClass";
    data.testFrameworkData.type = TestFrameworkType::Catch2;
    data.testFrameworkData.sourceFileAdditionalIncludes = QStringList{"Catch2QString.h"};

    Class c = ClassBuilder::makeClass(data);

    REQUIRE( c.hasTest() );
  }
}
