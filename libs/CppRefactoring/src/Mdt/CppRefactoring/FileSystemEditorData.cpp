// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileSystemEditorData.h"

namespace Mdt{ namespace CppRefactoring{

bool FileSystemEditorData::seemsComplete() const noexcept
{
  if( sourceFilesRootDirectoryAbsolutePath.trimmed().isEmpty() ){
    return false;
  }
  if( testSourceFilesDirectoryAbsolutePath.trimmed().isEmpty() ){
    return false;
  }

  return true;
}

}} // namespace Mdt{ namespace CppRefactoring{
