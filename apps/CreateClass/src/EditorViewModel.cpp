// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "EditorViewModel.h"

using namespace Mdt::CppRefactoring;


void EditorViewModel::setFileSystemStructure(const Mdt::CppRefactoring::FileSystemStructure& fileSystemStructure) noexcept
{
}

QString EditorViewModel::sourceFilesRootDirectoryAbsolutePath() const noexcept
{
  return QString();
}

QString EditorViewModel::headerFilesRootDirectoryAbsolutePath() const noexcept
{
  return QString();
}

QString EditorViewModel::testSourceFilesDirectoryAbsolutePath() const noexcept
{
  return QString();
}

QString EditorViewModel::getHeaderFileAbsolutePath() const noexcept
{
  return QString();
}

QString EditorViewModel::getSourceFileAbsolutePath() const noexcept
{
  return QString();
}

QString EditorViewModel::getTestSourceFileAbsolutePath() const noexcept
{
  return QString();
}
