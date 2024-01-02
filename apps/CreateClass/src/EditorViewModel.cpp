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


void EditorViewModel::setFileSystemStructure(const FileSystemStructure& fileSystemStructure) noexcept
{
  mFileSystemStructure = ClassFileSystemStructure(fileSystemStructure);
}

void EditorViewModel::setClass(const Class& c) noexcept
{
  mClass = c;
}

QString EditorViewModel::sourceFilesRootDirectoryAbsolutePath() const noexcept
{
  if(mFileSystemStructure){
    return mFileSystemStructure->fileSystemStructure().sourceFilesRootDirectoryAbsolutePath();
  }
  return QString();
}

QString EditorViewModel::headerFilesRootDirectoryAbsolutePath() const noexcept
{
  if(mFileSystemStructure){
    return mFileSystemStructure->fileSystemStructure().headerFilesRootDirectoryAbsolutePath();
  }
  return QString();
}

QString EditorViewModel::testSourceFilesDirectoryAbsolutePath() const noexcept
{
  if(mFileSystemStructure){
    return mFileSystemStructure->fileSystemStructure().testSourceFilesDirectoryAbsolutePath();
  }
  return QString();
}

QString EditorViewModel::getHeaderFileAbsolutePath() const noexcept
{
  if(!mFileSystemStructure){
    return QString();
  }
  if(!mClass){
    return QString();
  }
  return mFileSystemStructure->getHeaderFileAbsolutePath(*mClass);
}

QString EditorViewModel::getSourceFileAbsolutePath() const noexcept
{
  if(!mFileSystemStructure){
    return QString();
  }
  if(!mClass){
    return QString();
  }
  return mFileSystemStructure->getSourceFileAbsolutePath(*mClass);
}

QString EditorViewModel::getTestSourceFileAbsolutePath() const noexcept
{
  if(!mFileSystemStructure){
    return QString();
  }
  if(!mClass){
    return QString();
  }
  return mFileSystemStructure->getTestSourceFileAbsolutePath(*mClass);
}
