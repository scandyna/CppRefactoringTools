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
#include "Mdt/CppRefactoring/IncludeStatement.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("fromFileBaseName")
{
  auto is = IncludeStatement::fromFileBaseName("MyClass");

  REQUIRE( is.toString() == "#include \"MyClass.h\"" );
}
