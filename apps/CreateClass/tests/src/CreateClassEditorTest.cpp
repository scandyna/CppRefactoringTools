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
#include <QTemporaryDir>

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

TEST_CASE("setSourceFilesRootDirectoryAbsolutePath")
{
  CreateClassEditor editor;

  editor.setSourceFilesRootDirectoryAbsolutePath("/tmp/project/src");

  REQUIRE( editor.fileSystemEditorData().sourceFilesRootDirectoryAbsolutePath == "/tmp/project/src" );
}

TEST_CASE("setTestSourceFilesDirectoryAbsolutePath")
{
  CreateClassEditor editor;

  editor.setTestSourceFilesDirectoryAbsolutePath("/tmp/project/tests/src");

  REQUIRE( editor.fileSystemEditorData().testSourceFilesDirectoryAbsolutePath == "/tmp/project/tests/src" );
}

TEST_CASE("createClass")
{
  QTemporaryDir sourceRootDir;
  QTemporaryDir testSourceRootDir;
  REQUIRE( sourceRootDir.isValid() );
  REQUIRE( testSourceRootDir.isValid() );

  CreateClassEditor editor;
  editor.setClassName("MyClass");
  editor.setNamespace("Mdt::CppRefactoring");
  editor.setTestFrameworkType(TestFrameworkType::Catch2);
  editor.setSourceFilesRootDirectoryAbsolutePath( sourceRootDir.path() );
  editor.setTestSourceFilesDirectoryAbsolutePath( testSourceRootDir.path() );

  CreateClassResponse response = editor.createClass(CreateClassFileOverwriteBehavior::Fail);
  REQUIRE( response.isSuccess );

  response = editor.createClass(CreateClassFileOverwriteBehavior::AskConfirmation);
  REQUIRE( !response.isSuccess );
  REQUIRE( response.isAskingToOverwriteFile() );

  response = editor.createClass(CreateClassFileOverwriteBehavior::Overwrite);
  REQUIRE( response.isSuccess );
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
