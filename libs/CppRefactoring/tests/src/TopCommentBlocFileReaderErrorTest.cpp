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
#include <QTemporaryDir>
#include <QTemporaryFile>

using namespace Mdt::CppRefactoring;


TEST_CASE("fromTemplateFile")
{
  SECTION("non existing path")
  {
    REQUIRE_THROWS_AS( TopCommentBlocFileReader::fromTemplateFile("/path/to/probably/non/existing/file.txt"), TopCommentBlocFileReadError );
  }

  SECTION("path refers to a directory")
  {
    QTemporaryDir dir;
    REQUIRE( dir.isValid() );

    REQUIRE_THROWS_AS( TopCommentBlocFileReader::fromTemplateFile( dir.path() ), TopCommentBlocFileReadError );
  }

  SECTION("Empty file")
  {
    QTemporaryFile file;
    REQUIRE( file.open() );
    file.close();

    REQUIRE_THROWS_AS( TopCommentBlocFileReader::fromTemplateFile( file.fileName() ), TopCommentBlocFileReadError );
  }
}
