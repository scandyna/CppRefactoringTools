// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>

using namespace Mdt::CppRefactoring;


TEST_CASE("construct")
{
  QTemporaryDir sourcesTempDir;
  QTemporaryDir testSourcesTempDir;
  REQUIRE( sourcesTempDir.isValid() );
  REQUIRE( testSourcesTempDir.isValid() );

  auto sourcesDir = SourceFilesRootDirectory::fromExistingPath( sourcesTempDir.path() );
  auto testSourcesDir = TestSourceFilesDirectory::fromExistingPath( testSourcesTempDir.path() );

  FileSystemStructure fss(sourcesDir, testSourcesDir);

  const QString sourcesDirAbsolutePath = sourcesTempDir.path();
  const QString testSourcesDirAbsolutePath = testSourcesTempDir.path();

  REQUIRE( fss.sourceFilesRootDirectoryAbsolutePath() == sourcesDirAbsolutePath );
  REQUIRE( fss.headerFilesRootDirectoryAbsolutePath() == sourcesDirAbsolutePath );
  REQUIRE( fss.testSourceFilesDirectoryAbsolutePath() == testSourcesDirAbsolutePath );
}
