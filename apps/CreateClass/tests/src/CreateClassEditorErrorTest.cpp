// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "CreateClassEditor.h"
#include <QTemporaryDir>

using namespace Mdt::CppRefactoring;


TEST_CASE("setLibraryBaseNameFromNamespace")
{
  CreateClassEditor editor;

  SECTION("empty namespace string")
  {
    editor.setNamespace("");

    REQUIRE_THROWS_AS( editor.setLibraryBaseNameFromNamespace(), ClassValidationError );
  }
}

TEST_CASE("refresh_Invalid_fileSystemStructure")
{
  CreateClassEditor editor;
  editor.setClassName("MyClass");

  editor.setSourceFilesRootDirectoryAbsolutePath("/some/probably/invalid/path/hope/src");
  editor.setTestSourceFilesDirectoryAbsolutePath("/some/probably/invalid/path/hope/tests/src");

  REQUIRE_THROWS_AS( editor.refresh() , FileSystemValidationError);
}

TEST_CASE("CreateClass_fileSystemStructureMissing")
{
  CreateClassEditor editor;
  editor.setClassName("MyClass");

  REQUIRE_THROWS_AS( editor.createClass(CreateClassFileOverwriteBehavior::Fail) , FileSystemValidationError);
}
