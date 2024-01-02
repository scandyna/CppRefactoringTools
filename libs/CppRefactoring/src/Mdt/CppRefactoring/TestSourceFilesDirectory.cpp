// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "TestSourceFilesDirectory.h"
#include "FileSystemHelpers.h"
#include <QFileInfo>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

bool TestSourceFilesDirectory::isValidExistingPath(const QString& path) noexcept
{
  return isValidPathToExistingDirectory(path);
}

TestSourceFilesDirectory TestSourceFilesDirectory::fromExistingPath(const QString& path) noexcept
{
  const QString & cPath = path.trimmed();
  assert( isValidExistingPath(cPath) );

  QFileInfo fi(cPath);

  return TestSourceFilesDirectory( fi.absoluteFilePath() );
}

TestSourceFilesDirectory TestSourceFilesDirectory::fromUncheckedPath(const QString & path) noexcept
{
  assert( !path.trimmed().isEmpty() );

  return TestSourceFilesDirectory(path);
}

TestSourceFilesDirectory::TestSourceFilesDirectory(const QString& path) noexcept
 : mAbsolutePath(path)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
