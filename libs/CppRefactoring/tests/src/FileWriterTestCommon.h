// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef FILE_WRITER_TEST_COMMON_H
#define FILE_WRITER_TEST_COMMON_H

#include "Mdt/CppRefactoring/FileWriter.h"
#include <QTemporaryFile>
#include <QTemporaryDir>
#include <QDir>
#include <QString>
#include <QFile>
#include <QTextStream>

using namespace Mdt::CppRefactoring;

inline
QString makeFilePath(const QTemporaryDir & root, const QString & relativePath)
{
  return QDir::cleanPath( root.path() + '/' + relativePath );
}

inline
bool isExistingFile(const QString & path)
{
  return FileWriter::checkIsExistingFile(path) == CheckIsExistingFileResponse::IsExistingFile;
}

inline
QString readTextFile(const QString & path)
{
  QFile file(path);
  if(!file.open(QIODevice::ReadOnly | QIODevice::Text) ){
    return "<error>";
  }

  QTextStream ts(&file);

  return ts.readAll();
}

#endif // #ifndef FILE_WRITER_TEST_COMMON_H
