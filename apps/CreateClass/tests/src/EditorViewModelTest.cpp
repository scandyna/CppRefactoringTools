// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "EditorViewModel.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/FileSystemBuilder.h"
#include "Mdt/CppRefactoring/ClassBuilder.h"
#include <QTemporaryDir>

using namespace Mdt::CppRefactoring;


TEST_CASE("FileSystemStructure")
{
  QTemporaryDir sourcesTempDir;
  QTemporaryDir testSourcesTempDir;
  REQUIRE( sourcesTempDir.isValid() );
  REQUIRE( testSourcesTempDir.isValid() );

  EditorViewModel model;

  SECTION("No file system structure - empty paths are returned")
  {
    REQUIRE( model.headerFilesRootDirectoryAbsolutePath().isEmpty() );
    REQUIRE( model.sourceFilesRootDirectoryAbsolutePath().isEmpty() );
    REQUIRE( model.testSourceFilesDirectoryAbsolutePath().isEmpty() );
    REQUIRE( model.getHeaderFileAbsolutePath().isEmpty() );
    REQUIRE( model.getSourceFileAbsolutePath().isEmpty() );
    REQUIRE( model.getTestSourceFileAbsolutePath().isEmpty() );
  }

  SECTION("With file system structure")
  {
    FileSystemEditorData data;
    data.sourceFilesRootDirectoryAbsolutePath = sourcesTempDir.path();
    data.testSourceFilesDirectoryAbsolutePath = testSourcesTempDir.path();

    model.setFileSystemStructure( FileSystemBuilder::makeStructure(data) );

    REQUIRE( !model.headerFilesRootDirectoryAbsolutePath().isEmpty() );
    REQUIRE( !model.sourceFilesRootDirectoryAbsolutePath().isEmpty() );
    REQUIRE( !model.testSourceFilesDirectoryAbsolutePath().isEmpty() );
  }

  SECTION("with class")
  {
    FileSystemEditorData fssData;
    fssData.sourceFilesRootDirectoryAbsolutePath = sourcesTempDir.path();
    fssData.testSourceFilesDirectoryAbsolutePath = testSourcesTempDir.path();

    ClassEditorData classData;
    classData.className = "MyClass";
    classData.testFrameworkData.type = TestFrameworkType::Catch2;

    model.setFileSystemStructure( FileSystemBuilder::makeStructure(fssData) );
    model.setClass( ClassBuilder::makeClass(classData) );

    REQUIRE( !model.getHeaderFileAbsolutePath().isEmpty() );
    REQUIRE( !model.getSourceFileAbsolutePath().isEmpty() );
    REQUIRE( !model.getTestSourceFileAbsolutePath().isEmpty() );
  }
}
