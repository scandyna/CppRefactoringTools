// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileSystemBuilder.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("makeFileSystemStructure")
{
  FileSystemEditorData data;
  data.sourceFilesRootDirectoryAbsolutePath = "/some/probably/non/existing/path/hope/src";
  data.testSourceFilesDirectoryAbsolutePath = "/some/probably/non/existing/path/hope/tests/src";

  REQUIRE_THROWS_AS( FileSystemBuilder::makeStructure(data), FileSystemValidationError );
}
