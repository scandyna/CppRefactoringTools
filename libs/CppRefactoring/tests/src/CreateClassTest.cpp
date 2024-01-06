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

FileSystemStructure fileSystemStructureFromSourcesAndTestDirs(const QTemporaryDir & sourcesDir, const QTemporaryDir & testsDir)
{
  auto sourceFilesRootDirectory = SourceFilesRootDirectory::fromExistingPath( sourcesDir.path() );
  auto testSourceFilesDirectory = TestSourceFilesDirectory::fromExistingPath( testsDir.path() );

  return FileSystemStructure(sourceFilesRootDirectory, testSourceFilesDirectory);
}


TEST_CASE("shouldAskOverwriteConfirmation")
{
  CHECK( CreateClass::shouldAskOverwriteConfirmation(CheckIsExistingFileResponse::IsExistingFile, CreateClassFileOverwriteBehavior::AskConfirmation) );
  CHECK( !CreateClass::shouldAskOverwriteConfirmation(CheckIsExistingFileResponse::IsExistingFile, CreateClassFileOverwriteBehavior::Fail) );
  CHECK( !CreateClass::shouldAskOverwriteConfirmation(CheckIsExistingFileResponse::IsDirectory, CreateClassFileOverwriteBehavior::AskConfirmation) );
  CHECK( !CreateClass::shouldAskOverwriteConfirmation(CheckIsExistingFileResponse::NonExisting, CreateClassFileOverwriteBehavior::AskConfirmation) );
}

TEST_CASE("shouldThrowError")
{
  CHECK( CreateClass::shouldThrowError(CheckIsExistingFileResponse::IsDirectory, CreateClassFileOverwriteBehavior::AskConfirmation) );
  CHECK( CreateClass::shouldThrowError(CheckIsExistingFileResponse::IsExistingFile, CreateClassFileOverwriteBehavior::Fail) );
  CHECK( !CreateClass::shouldThrowError(CheckIsExistingFileResponse::IsExistingFile, CreateClassFileOverwriteBehavior::Overwrite) );
  CHECK( !CreateClass::shouldThrowError(CheckIsExistingFileResponse::NonExisting, CreateClassFileOverwriteBehavior::Fail) );
}

TEST_CASE("isOkToWrite")
{
  CHECK( CreateClass::isOkToWrite(CheckIsExistingFileResponse::NonExisting, CreateClassFileOverwriteBehavior::Fail) );
  CHECK( CreateClass::isOkToWrite(CheckIsExistingFileResponse::IsExistingFile, CreateClassFileOverwriteBehavior::Overwrite) );
  CHECK( !CreateClass::isOkToWrite(CheckIsExistingFileResponse::IsDirectory, CreateClassFileOverwriteBehavior::AskConfirmation) );
}

TEST_CASE("execute")
{
  QTemporaryDir sourcesDir;
  QTemporaryDir testSourcesDir;
  REQUIRE( sourcesDir.isValid() );
  REQUIRE( testSourcesDir.isValid() );

  FileSystemStructure fss = fileSystemStructureFromSourcesAndTestDirs(sourcesDir, testSourcesDir);

  const auto className = ClassName::fromString("MyClass");
  auto c = Class::fromName(className);
  c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );
  c.setTest( Test::fromClassName(className) );

  CreateClass useCase;
  CreateClassRequest request{c, fss, CreateClassFileOverwriteBehavior::Fail};

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
