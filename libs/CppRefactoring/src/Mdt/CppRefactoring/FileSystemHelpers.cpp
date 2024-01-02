// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileSystemHelpers.h"
#include <QFileInfo>

namespace Mdt{ namespace CppRefactoring{

bool isValidPathToExistingDirectory(const QString & path) noexcept
{
  const QString cPath = path.trimmed();

  if( cPath.isEmpty() ){
    return false;
  }

  QFileInfo fi(cPath);
  if( !fi.exists() ){
    return false;
  }
  if( !fi.isDir() ){
    return false;
  }

  return true;
}

}} // namespace Mdt{ namespace CppRefactoring{
