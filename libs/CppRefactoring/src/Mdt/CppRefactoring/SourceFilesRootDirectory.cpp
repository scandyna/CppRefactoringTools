// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "SourceFilesRootDirectory.h"
#include "FileSystemHelpers.h"
#include <QFileInfo>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

bool SourceFilesRootDirectory::isValidExistingPath(const QString& path) noexcept
{
  return isValidPathToExistingDirectory(path);
}

SourceFilesRootDirectory SourceFilesRootDirectory::fromExistingPath(const QString& path) noexcept
{
  const QString & cPath = path.trimmed();
  assert( isValidExistingPath(cPath) );

  QFileInfo fi(cPath);

  return SourceFilesRootDirectory( fi.absoluteFilePath() );
}

SourceFilesRootDirectory SourceFilesRootDirectory::fromUncheckedPath(const QString & path) noexcept
{
  assert( !path.trimmed().isEmpty() );

  return SourceFilesRootDirectory(path);
}

SourceFilesRootDirectory::SourceFilesRootDirectory(const QString & path) noexcept
 : mAbsolutePath(path)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
