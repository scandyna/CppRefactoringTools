// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Mdt/CppRefactoring/TopCommentBlocFileReader.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "TopCommentBlocFileReaderTestCommon.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("fromTemplateFile")
{
  QTemporaryFile file;
  REQUIRE( file.open() );

  writeTopCommentBlocFile(file, "// Top");

  TopCommentBloc bloc = TopCommentBlocFileReader::fromTemplateFile( file.fileName() );

  REQUIRE( bloc.toString() == "// Top" );
}
