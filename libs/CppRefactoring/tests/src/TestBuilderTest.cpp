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
#include "Mdt/CppRefactoring/TestBuilder.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("makeCatch2TestSourceFileContent")
{
  TestFrameworkEditorData data;
  data.type = TestFrameworkType::Catch2;
  auto className = ClassName::fromString("MyClass");
  auto testName = TestName::fromClassName(className);

  data.sourceFileAdditionalIncludes = QStringList{"Catch2QString.h"};
  data.sourceFileAdditionalSystemIncludes = QStringList{"QString"};

  auto content = TestBuilder::makeCatch2TestSourceFileContent(testName, className, data);

  REQUIRE( content.includeStatementBloc().containsFileRelativePath("MyClass.h") );
  REQUIRE( content.includeStatementBloc().containsFileRelativePath("catch2/catch.hpp") );
  REQUIRE( content.includeStatementBloc().containsFileRelativePath("Catch2QString.h") );
  REQUIRE( content.includeStatementBloc().containsFileRelativePath("QString") );
}

TEST_CASE("makeCatch2Test")
{
  TestFrameworkEditorData data;
  data.type = TestFrameworkType::Catch2;
  auto className = ClassName::fromString("MyClass");

  SECTION("only name")
  {
    Test test = TestBuilder::makeCatch2Test(data, className);

    REQUIRE( test.name().toString() == "MyClassTest" );
    REQUIRE( test.testSourceFileContent().includeStatementBloc().containsFileRelativePath("catch2/catch.hpp") );
  }

  SECTION("sourceFileAdditionalIncludes")
  {
    data.sourceFileAdditionalIncludes = QStringList{"Catch2QString.h"};

    Test test = TestBuilder::makeCatch2Test(data, className);

    REQUIRE( test.name().toString() == "MyClassTest" );
    REQUIRE( test.testSourceFileContent().includeStatementBloc().containsFileRelativePath("catch2/catch.hpp") );
    REQUIRE( test.testSourceFileContent().includeStatementBloc().containsFileRelativePath("Catch2QString.h") );
  }

  SECTION("sourceFileAdditionalSystemIncludes")
  {
    data.sourceFileAdditionalSystemIncludes = QStringList{"QString"};

    Test test = TestBuilder::makeCatch2Test(data, className);

    REQUIRE( test.name().toString() == "MyClassTest" );
    REQUIRE( test.testSourceFileContent().includeStatementBloc().containsFileRelativePath("catch2/catch.hpp") );
    REQUIRE( test.testSourceFileContent().includeStatementBloc().containsFileRelativePath("QString") );
  }
}

TEST_CASE("makeTest")
{
  TestFrameworkEditorData data;
  auto className = ClassName::fromString("MyClass");

  SECTION("Catch2 test")
  {
    data.type = TestFrameworkType::Catch2;

    Test test = TestBuilder::makeTest(data, className);

    REQUIRE( test.name().toString() == "MyClassTest" );
  }
}
