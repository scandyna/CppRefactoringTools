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


TEST_CASE("setLibraryBaseNameFromNamespace")
{
  CreateClassEditor editor;

  SECTION("empty namespace string")
  {
    editor.setNamespace("");

    REQUIRE_THROWS_AS( editor.setLibraryBaseNameFromNamespace(), ClassValidationError );
  }
}
