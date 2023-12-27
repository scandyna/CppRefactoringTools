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
#include "Mdt/CppRefactoring/LibraryExport.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("fromLibraryName")
{
  auto libraryExport = LibraryExport::fromLibraryBaseName("Mdt_CppRefactoring");

  REQUIRE( libraryExport.libraryBaseName() == "Mdt_CppRefactoring" );
}

TEST_CASE("toUsageMacroString")
{
  auto libraryExport = LibraryExport::fromLibraryBaseName("Mdt_CppRefactoring");

  REQUIRE( libraryExport.toUsageMacroString() == "MDT_CPPREFACTORING_EXPORT" );
}

TEST_CASE("toIncludeStatement")
{
  auto libraryExport = LibraryExport::fromLibraryBaseName("Mdt_CppRefactoring");

  REQUIRE( libraryExport.toIncludeStatement().toString() == "#include \"mdt_cpprefactoring_export.h\"" );
}
