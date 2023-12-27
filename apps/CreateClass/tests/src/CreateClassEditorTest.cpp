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
