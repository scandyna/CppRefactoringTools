// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "IncludeStatement.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>
#include <QDir>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

void IncludeStatement::setSystemInclude(bool s) noexcept
{
  mIsSystemInclude = s;
}

QString IncludeStatement::fileRelativePath() const noexcept
{
  if(mDirectoryRelativePath){
    return mDirectoryRelativePath->toString() % QLatin1Char('/') % mFileName;
  }
  return mFileName;
}

QString IncludeStatement::toString() const noexcept
{
  return QLatin1String("#include ") % getBeginQuote()
         % getDirectoryRelativePathStringIf()
         % mFileName % getEndQuote();
}

IncludeStatement IncludeStatement::fromFileBaseName(const QString & name) noexcept
{
  QString bName = name.trimmed();
  assert( !bName.isEmpty() );

  return IncludeStatement( bName % QLatin1String(".h") );
}

IncludeStatement IncludeStatement::fromNamespaceAndFileBaseName(const Namespace & ns, const QString & name) noexcept
{
  QString bName = name.trimmed();
  assert( !bName.isEmpty() );

  return IncludeStatement( bName % QLatin1String(".h"), ns.toDirectoryRelativePath() );
}

IncludeStatement IncludeStatement::from_q_char_sequence(const QString & sequence) noexcept
{
  const QString cSequence = sequence.trimmed();
  assert( !cSequence.isEmpty() );

  return fromFileInfo(cSequence);
}

IncludeStatement IncludeStatement::systemIncludeFrom_h_char_sequence(const QString & sequence) noexcept
{
  const QString cSequence = sequence.trimmed();
  assert( !cSequence.isEmpty() );

  IncludeStatement statement = fromFileInfo(cSequence);
  statement.setSystemInclude(true);

  return statement;
}

IncludeStatement IncludeStatement::fromFileInfo(const QFileInfo & fi) noexcept
{
  const QString dirPath = fi.path();

  if( dirPath.isEmpty() || ( dirPath == QLatin1Char('.') ) ){
    return IncludeStatement( fi.fileName() );
  }

  return IncludeStatement( fi.fileName(), DirectoryRelativePath::fromString(dirPath) );
}

IncludeStatement::IncludeStatement(const QString & fileName) noexcept
 : mFileName(fileName)
{
  assert( !mFileName.trimmed().isEmpty() );
}

IncludeStatement::IncludeStatement(const QString & fileName, const DirectoryRelativePath & path) noexcept
 : mFileName(fileName),
   mDirectoryRelativePath(path)
{
  assert( !mFileName.trimmed().isEmpty() );
}

QChar IncludeStatement::getBeginQuote() const noexcept
{
  if(mIsSystemInclude){
    return QLatin1Char('<');
  }
  return QLatin1Char('"');
}

QChar IncludeStatement::getEndQuote() const noexcept
{
  if(mIsSystemInclude){
    return QLatin1Char('>');
  }
  return QLatin1Char('"');
}

QString IncludeStatement::getDirectoryRelativePathStringIf() const noexcept
{
  if(!mDirectoryRelativePath){
    return QString();
  }
  return mDirectoryRelativePath->toString() % QLatin1Char('/');
}

}} // namespace Mdt{ namespace CppRefactoring{
