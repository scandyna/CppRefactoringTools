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
#include "Mdt/CppRefactoring/ClassDeclaration.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("toString")
{
  ClassDeclaration cd( ClassName::fromString("MyClass") );

  SECTION("No indentation")
  {
    QString expectedResult =
      "class MyClass\n"
      "{\n"
      "};";

    REQUIRE( cd.toString() == expectedResult );
  }

  SECTION("2 char indentation")
  {
    QString expectedResult =
      "  class MyClass\n"
      "  {\n"
      "  };";

    cd.setIndentationCharCount(2);

    REQUIRE( cd.toString() == expectedResult );
  }

  SECTION("library export")
  {
    auto libraryExport = LibraryExport::fromLibraryBaseName("Mdt_CppRefactoring");
    cd.setLibraryExport(libraryExport);

    QString expectedResult =
      "class MDT_CPPREFACTORING_EXPORT MyClass\n"
      "{\n"
      "};";

    REQUIRE( cd.toString() == expectedResult );
  }
}
