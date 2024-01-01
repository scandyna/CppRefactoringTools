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


TEST_CASE("FileSystemStructure")
{
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
}
