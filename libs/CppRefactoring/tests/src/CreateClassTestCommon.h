// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef CREATE_CLASS_TEST_COMMON_H
#define CREATE_CLASS_TEST_COMMON_H

#include "Mdt/CppRefactoring/SourceFilesRootDirectory.h"
#include "Mdt/CppRefactoring/TestSourceFilesDirectory.h"
#include <QTemporaryDir>

using namespace Mdt::CppRefactoring;

FileSystemStructure fileSystemStructureFromSourcesAndTestDirs(const QTemporaryDir & sourcesDir, const QTemporaryDir & testsDir)
{
  auto sourceFilesRootDirectory = SourceFilesRootDirectory::fromExistingPath( sourcesDir.path() );
  auto testSourceFilesDirectory = TestSourceFilesDirectory::fromExistingPath( testsDir.path() );

  return FileSystemStructure(sourceFilesRootDirectory, testSourceFilesDirectory);
}

#endif // #ifndef CREATE_CLASS_TEST_COMMON_H
