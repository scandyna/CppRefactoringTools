// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "ClassFileSystemStructure.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>
#include <QDir>

namespace Mdt{ namespace CppRefactoring{

ClassFileSystemStructure::ClassFileSystemStructure(const FileSystemStructure & fss) noexcept
 : mFileSystemStructure(fss)
{
}

QString ClassFileSystemStructure::getSourceFileAbsolutePath(const Class & c) const noexcept
{
  QString path = mFileSystemStructure.sourceFilesRootDirectoryAbsolutePath()
               % QLatin1Char('/') % getNamespaceRelativePathIf(c)
               % QLatin1Char('/') % c.sourceFileName().toString();

  return QDir::cleanPath(path);
}

QString ClassFileSystemStructure::getHeaderFileAbsolutePath(const Class & c) const noexcept
{
  QString path = mFileSystemStructure.sourceFilesRootDirectoryAbsolutePath()
               % QLatin1Char('/') % getNamespaceRelativePathIf(c)
               % QLatin1Char('/') % c.headerFileName().toString();

  return QDir::cleanPath(path);
}

QString ClassFileSystemStructure::getTestSourceFileAbsolutePath(const Class & c) const noexcept
{
  QString path;

  if( !c.hasTest() ){
    return path;
  }

  path = mFileSystemStructure.testSourceFilesDirectoryAbsolutePath()
       % QLatin1Char('/') % c.testSourceFileName().toString();

  return QDir::cleanPath(path);
}

QString ClassFileSystemStructure::getNamespaceRelativePathIf(const Class & c) noexcept
{
  if( !c.isInNamespace() ){
    return QString();
  }
  return c.ns().toDirectoryRelativePath().toString();
}

}} // namespace Mdt{ namespace CppRefactoring{
