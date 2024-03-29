// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileSystemBuilder.h"
#include "SourceFilesRootDirectory.h"
#include "TestSourceFilesDirectory.h"
#include "FileSystemValidation.h"

namespace Mdt{ namespace CppRefactoring{

FileSystemStructure FileSystemBuilder::makeStructure(const FileSystemEditorData & data)
{
  FileSystemValidation::validateSourceFilesRootDirectoryPath(data.sourceFilesRootDirectoryAbsolutePath);
  FileSystemValidation::validateTestSourceFilesRootDirectoryPath(data.testSourceFilesDirectoryAbsolutePath);

  auto sourcesDir = SourceFilesRootDirectory::fromExistingPath(data.sourceFilesRootDirectoryAbsolutePath);
  auto testSourcesDir = TestSourceFilesDirectory::fromExistingPath(data.testSourceFilesDirectoryAbsolutePath);

  return FileSystemStructure(sourcesDir, testSourcesDir);
}

}} // namespace Mdt{ namespace CppRefactoring{
