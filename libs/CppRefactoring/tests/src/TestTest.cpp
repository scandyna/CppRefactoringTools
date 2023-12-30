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
#include "Mdt/CppRefactoring/Test.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromName")
{
  auto test = Test::fromClassName( ClassName::fromString("MyClass") );

  REQUIRE( test.name().toString() == "MyClassTest" );
}
