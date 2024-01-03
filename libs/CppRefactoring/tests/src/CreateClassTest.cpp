// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/CreateClass.h"
#include "Mdt/CppRefactoring/SourceFilesRootDirectory.h"
#include "Mdt/CppRefactoring/TestSourceFilesDirectory.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>
#include <QFileInfo>

using namespace Mdt::CppRefactoring;

// struct TemporaryFileSystemStructure
// {
//   QTemporaryDir sourceFilesRootTemporaryDir;
//   QTemporaryDir testSourceFilesRootTemporaryDir;
//   SourceFilesRootDirectory sourceFilesRootDirectory;
//   TestSourceFilesDirectory testSourceFilesDirectory;
// 
//   TemporaryFileSystemStructure()
//    : sourceFilesRootDirectory( SourceFilesRootDirectory::fromExistingPath( sourceFilesRootTemporaryDir.path() ) )
//   {
//   }
// };

FileSystemStructure fileSystemStructureFromSourcesAndTestDirs(const QTemporaryDir & sourcesDir, const QTemporaryDir & testsDir)
{
  auto sourceFilesRootDirectory = SourceFilesRootDirectory::fromExistingPath( sourcesDir.path() );
  auto testSourceFilesDirectory = TestSourceFilesDirectory::fromExistingPath( testsDir.path() );

  return FileSystemStructure(sourceFilesRootDirectory, testSourceFilesDirectory);
}


TEST_CASE("execute")
{
  // TemporaryFileSystemStructure tfss;
  // REQUIRE( tfss.sourceFilesRootTemporaryDir.isValid() );
  // REQUIRE( tfss.testSourceFilesRootTemporaryDir.isValid() );

  QTemporaryDir sourcesDir;
  QTemporaryDir testSourcesDir;
  REQUIRE( sourcesDir.isValid() );
  REQUIRE( testSourcesDir.isValid() );

  FileSystemStructure fss = fileSystemStructureFromSourcesAndTestDirs(sourcesDir, testSourcesDir);

  const auto className = ClassName::fromString("MyClass");
  auto c = Class::fromName(className);
  c.setTest( Test::fromClassName(className) );

  CreateClass useCase;
  CreateClassRequest request{c, fss, FileOverwriteBehavior::Fail};

  CreateClassResponse response = useCase.execute(request);

  QFileInfo headerFile = response.headerFileAbsolutePath;
  QFileInfo sourceFile = response.sourceFileAbsolutePath;
  QFileInfo testSourceFile = response.testSourceFileAbsolutePath;

  REQUIRE( headerFile.exists() );
  REQUIRE( headerFile.isFile() );
  REQUIRE( sourceFile.exists() );
  REQUIRE( sourceFile.isFile() );
  REQUIRE( testSourceFile.exists() );
  REQUIRE( testSourceFile.isFile() );
}
