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
#include "Mdt/CppRefactoring/Class.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromName")
{
  auto name = ClassName::fromString("MyClass");

  Class c = Class::fromName(name);

  REQUIRE( c.name().toString() == "MyClass" );
  REQUIRE( c.headerFileName().toString() == "MyClass.h" );
  REQUIRE( c.sourceFileName().toString() == "MyClass.cpp" );
  // REQUIRE( c.testSourceFileName().toString() == "MyClassTest.cpp" );
}

TEST_CASE("Namespace")
{
  auto name = ClassName::fromString("MyClass");
  Class c = Class::fromName(name);

  SECTION("by default a class is not in a namespace")
  {
    REQUIRE( !c.isInNamespace() );
  }

  SECTION("put class into a namespace")
  {
    c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );

    REQUIRE( c.isInNamespace() );
    REQUIRE( c.ns().toColonSeparatedString() == "Mdt::CppRefactoring" );
  }
}

TEST_CASE("headerFileContent_TopCommentBloc")
{
  auto name = ClassName::fromString("MyClass");
  Class c = Class::fromName(name);

  SECTION("By default no top comment bloc")
  {
    REQUIRE( !c.headerFileContent().hasTopCommentBloc() );
  }

  SECTION("set a top comment bloc")
  {
    c.setTopCommentBloc( TopCommentBloc::fromString("// Top") );

    REQUIRE( c.headerFileContent().hasTopCommentBloc() );
  }
}

TEST_CASE("setTest")
{
  auto name = ClassName::fromString("MyClass");

  Class c = Class::fromName(name);
  c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );
  c.setTopCommentBloc( TopCommentBloc::fromString("// Top") );

  Test test = Test::fromClassName(name);

  c.setTest(test);

  REQUIRE( c.hasTest() );
  REQUIRE( c.testSourceFileName().toString() == "MyClassTest.cpp" );
  REQUIRE( c.testSourceFileContent().hasNamespace() );
  REQUIRE( c.testSourceFileContent().hasTopCommentBloc() );
}

TEST_CASE("setTest_thenAttributes")
{
  auto name = ClassName::fromString("MyClass");
  Class c = Class::fromName(name);

  Test test = Test::fromClassName(name);
  c.setTest(test);
  REQUIRE( c.hasTest() );

  c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );
  c.setTopCommentBloc( TopCommentBloc::fromString("// Top") );
  REQUIRE( c.testSourceFileContent().hasNamespace() );
  REQUIRE( c.testSourceFileContent().hasTopCommentBloc() );
}
