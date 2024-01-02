// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileSystemEditorData.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("seemsComplete")
{
  FileSystemEditorData data;

  SECTION("By default its not complete")
  {
    REQUIRE( !data.seemsComplete() );
  }

  SECTION("only white spaces")
  {
    data.sourceFilesRootDirectoryAbsolutePath = " ";
    data.testSourceFilesDirectoryAbsolutePath = " ";

    REQUIRE( !data.seemsComplete() );
  }

  SECTION("only source files is not compete")
  {
    data.sourceFilesRootDirectoryAbsolutePath = "src";

    REQUIRE( !data.seemsComplete() );
  }

  SECTION("only test source file is not complete")
  {
    data.testSourceFilesDirectoryAbsolutePath = "tests/src";

    REQUIRE( !data.seemsComplete() );
  }

  SECTION("all mandatory fields ok")
  {
    data.sourceFilesRootDirectoryAbsolutePath = "src";
    data.testSourceFilesDirectoryAbsolutePath = "tests/src";

    REQUIRE( data.seemsComplete() );
  }
}
