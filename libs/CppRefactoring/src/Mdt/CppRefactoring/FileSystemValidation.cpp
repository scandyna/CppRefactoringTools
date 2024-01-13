// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileSystemValidation.h"
#include "SourceFilesRootDirectory.h"
#include "TestSourceFilesDirectory.h"

namespace Mdt{ namespace CppRefactoring{

void FileSystemValidation::validateSourceFilesRootDirectoryPath(const QString & path)
{
  if( !SourceFilesRootDirectory::isValidExistingPath(path) ){
    QString msg = tr("'%1' is not an existing directory")
                  .arg(path);
    throw FileSystemValidationError(msg);
  }
}

void FileSystemValidation::validateTestSourceFilesRootDirectoryPath(const QString & path)
{
  if( !TestSourceFilesDirectory::isValidExistingPath(path) ){
    QString msg = tr("'%1' is not an existing directory")
                  .arg(path);
    throw FileSystemValidationError(msg);
  }
}

}} // namespace Mdt{ namespace CppRefactoring{
