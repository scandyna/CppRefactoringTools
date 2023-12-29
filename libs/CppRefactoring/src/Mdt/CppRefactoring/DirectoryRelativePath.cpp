// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "DirectoryRelativePath.h"
#include <QFileInfo>
#include <QDir>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

QString DirectoryRelativePath::toString() const noexcept
{
  return mPath;
}

bool DirectoryRelativePath::isValidString(const QString & path) noexcept
{
  const QString cPath = path.trimmed();

  if( cPath.isEmpty() ){
    return false;
  }
  QFileInfo fi(cPath);

  if( fi.isAbsolute() ){
    return false;
  }

  // isDir() seems to require an existing path
  // if( !fi.isDir() ){
  //   return false;
  // }

  return true;
}

DirectoryRelativePath DirectoryRelativePath::fromString(const QString & path) noexcept
{
  const QString cPath = path.trimmed();
  assert( isValidString(cPath) );

  return DirectoryRelativePath( QDir::cleanPath(cPath) );
}

DirectoryRelativePath::DirectoryRelativePath(const QString & path) noexcept
 : mPath(path)
{
  assert( isValidString(mPath) );
}

}} // namespace Mdt{ namespace CppRefactoring{
