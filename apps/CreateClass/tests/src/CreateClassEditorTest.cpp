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
#include "CreateClassEditor.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("EditoHasNoValidClassByDefault")
{
  CreateClassEditor editor;

  REQUIRE( !editor.hasValidClass() );
}

TEST_CASE("setClassName")
{
  CreateClassEditor editor;

  editor.setClassName(" MyClass ");

  REQUIRE( editor.editorData().className == " MyClass " );
  // REQUIRE( editor.editorData().testFrameworkData.testBaseName == " MyClass " );

  editor.refresh();

  REQUIRE( editor.hasValidClass() );
  REQUIRE( editor.validClass().name().toString() == "MyClass" );
}

TEST_CASE("setNamespace")
{
  CreateClassEditor editor;

  editor.setNamespace("Mdt");

  REQUIRE( editor.editorData().namespaceStr == "Mdt" );
}

TEST_CASE("setTopCommentBloc")
{
  CreateClassEditor editor;

  editor.setTopCommentBloc("// Top");

  REQUIRE( editor.editorData().topCommentBloc == "// Top" );
}

TEST_CASE("setUseLibraryExport")
{
  CreateClassEditor editor;

  SECTION("by default no library export")
  {
    REQUIRE( !editor.editorData().useLibraryExport );
  }

  SECTION("use library export")
  {
    editor.setUseLibraryExport(true);

    REQUIRE( editor.editorData().useLibraryExport );
  }
}

TEST_CASE("setLibraryBaseName")
{
  CreateClassEditor editor;

  editor.setLibraryBaseName("Mdt_CppRefactoring");

  REQUIRE( editor.editorData().libraryBaseName == "Mdt_CppRefactoring" );
}

TEST_CASE("setLibraryBaseNameFromNamespace")
{
  CreateClassEditor editor;

  editor.setNamespace("Mdt::CppRefactoring");
  editor.setLibraryBaseNameFromNamespace();

  REQUIRE( editor.editorData().libraryBaseName == "Mdt_CppRefactoring" );
}

TEST_CASE("setTestFrameworkType")
{
  CreateClassEditor editor;

  editor.setTestFrameworkType(TestFrameworkType::Catch2);

  REQUIRE( *editor.editorData().testFrameworkData.type == TestFrameworkType::Catch2 );
}

TEST_CASE("setTestSourceFileAdditionalIncludes")
{
  CreateClassEditor editor;

  editor.setTestSourceFileAdditionalIncludes({"Catch2QString.h"});

  REQUIRE( editor.editorData().testFrameworkData.sourceFileAdditionalIncludes == QStringList{"Catch2QString.h"} );
}

TEST_CASE("Catch2_test")
{
  CreateClassEditor editor;
  editor.setClassName("MyClass");
  editor.setTestFrameworkType(TestFrameworkType::Catch2);

  editor.refresh();

  REQUIRE( editor.hasValidClass() );
  REQUIRE( editor.validClass().hasTest() );
}
