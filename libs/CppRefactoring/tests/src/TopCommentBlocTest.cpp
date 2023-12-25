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
#include "Mdt/CppRefactoring/TopCommentBloc.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromString")
{
  const QString blocStr = "// SPDX\n/* Project CR bloc */\n";

  auto bloc = TopCommentBloc::fromString(blocStr);

  REQUIRE( bloc.toString() == blocStr );
}
