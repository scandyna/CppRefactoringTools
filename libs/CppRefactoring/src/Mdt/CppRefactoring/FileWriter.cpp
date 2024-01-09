// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "FileWriter.h"
#include <QDir>
#include <QTextStream>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

FileWriter::FileWriter(QObject *parent) noexcept
 : QObject(parent)
{
}

void FileWriter::open(const QString & path, FileOverwriteBehavior overwriteBehavior)
{
  assert( !path.trimmed().isEmpty() );

  QFileInfo fi(path);

  const CheckIsExistingFileResponse response = checkIsExistingFileImpl(fi);

  // QFile does this check, but here we can put our own error message
  if(response == CheckIsExistingFileResponse::IsDirectory){
    const QString msg = tr("can't open file '%1' because it is a directory")
                        .arg(path);
    throw FileWriteError(msg);
  }

  if( (overwriteBehavior == FileOverwriteBehavior::Fail) && (response == CheckIsExistingFileResponse::IsExistingFile) ){
    const QString msg = tr("can't open file '%1' because it exists and overwrit behavior is to fail in that case")
                        .arg(path);
    throw FileWriteError(msg);
  }

  makePath(fi);

  mFile.setFileName( fi.absoluteFilePath() );
  if( !mFile.open(QIODevice::WriteOnly | QIODevice::Text) ){
    const QString msg = tr("can't open file '%1': '%2'")
                        .arg( path, mFile.errorString() );
    throw FileWriteError(msg);
  }
}

void FileWriter::writeContent(const QString & content)
{
  assert( isOpen() );

  QTextStream ts(&mFile);

  ts << content;
}

void FileWriter::close()
{
  mFile.close();
}

CheckIsExistingFileResponse FileWriter::checkIsExistingFile(const QString & path) noexcept
{
  assert( !path.trimmed().isEmpty() );

  QFileInfo fi(path);

  return checkIsExistingFileImpl(fi);
}

CheckIsExistingFileResponse FileWriter::checkIsExistingFileImpl(const QFileInfo & fi) noexcept
{
  if( !fi.exists() ){
    return CheckIsExistingFileResponse::NonExisting;
  }
  if( fi.isDir() ){
    return CheckIsExistingFileResponse::IsDirectory;
  }
  assert( fi.isFile() );

  return CheckIsExistingFileResponse::IsExistingFile;
}

void FileWriter::makePath(const QFileInfo & fi)
{
  const QDir dir = fi.absoluteDir();

  if( !dir.mkpath( dir.path() ) ){
    const QString msg = tr("can't create directory '%1'")
                        .arg( dir.path() );
    throw FileWriteError(msg);
  }
}

}} // namespace Mdt{ namespace CppRefactoring{
