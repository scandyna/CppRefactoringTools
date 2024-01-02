// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileSystemStructure.h"

namespace Mdt{ namespace CppRefactoring{

FileSystemStructure::FileSystemStructure(const SourceFilesRootDirectory & sourceFilesRootDirectory,
                                         const TestSourceFilesDirectory & testSourceFilesDirectory) noexcept
 : mSourceFilesRootDirectory(sourceFilesRootDirectory),
   mTestSourceFilesDirectory(testSourceFilesDirectory)
{
}

QString FileSystemStructure::sourceFilesRootDirectoryAbsolutePath() const noexcept
{
  return mSourceFilesRootDirectory.absolutePath();
}

QString FileSystemStructure::headerFilesRootDirectoryAbsolutePath() const noexcept
{
  return sourceFilesRootDirectoryAbsolutePath();
}

QString FileSystemStructure::testSourceFilesDirectoryAbsolutePath() const noexcept
{
  return mTestSourceFilesDirectory.absolutePath();
}

}} // namespace Mdt{ namespace CppRefactoring{
