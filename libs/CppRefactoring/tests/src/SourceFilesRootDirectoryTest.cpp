// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/SourceFilesRootDirectory.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>
#include <QFileInfo>

using namespace Mdt::CppRefactoring;


TEST_CASE("fromExistingPath")
{
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );

  auto directory = SourceFilesRootDirectory::fromExistingPath( dir.path() );

  QFileInfo fi( directory.absolutePath() );

  REQUIRE( fi.exists() );
  REQUIRE( fi.isDir() );
  REQUIRE( fi.isAbsolute() );
}

TEST_CASE("fromUncheckedPath")
{
  auto directory = SourceFilesRootDirectory::fromUncheckedPath("/tmp");

  REQUIRE( directory.absolutePath() == "/tmp" );
}
