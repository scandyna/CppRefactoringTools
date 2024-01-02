// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileSystemBuilder.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>

using namespace Mdt::CppRefactoring;


TEST_CASE("makeFileSystemStructure")
{
  QTemporaryDir sourcesTempDir;
  QTemporaryDir testSourcesTempDir;
  REQUIRE( sourcesTempDir.isValid() );
  REQUIRE( testSourcesTempDir.isValid() );

  FileSystemEditorData data;
  data.sourceFilesRootDirectoryAbsolutePath = sourcesTempDir.path();
  data.testSourceFilesDirectoryAbsolutePath = testSourcesTempDir.path();

  FileSystemStructure fss = FileSystemBuilder::makeStructure(data);

  const QString sourcesDirAbsolutePath = sourcesTempDir.path();
  const QString testSourcesDirAbsolutePath = testSourcesTempDir.path();

  REQUIRE( fss.sourceFilesRootDirectoryAbsolutePath() == sourcesDirAbsolutePath );
  REQUIRE( fss.headerFilesRootDirectoryAbsolutePath() == sourcesDirAbsolutePath );
  REQUIRE( fss.testSourceFilesDirectoryAbsolutePath() == testSourcesDirAbsolutePath );
}
