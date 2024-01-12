// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "LibraryExport.h"
#include <QLatin1String>
#include <QStringBuilder>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

IncludeStatement LibraryExport::toIncludeStatement() const noexcept
{
  const QString fileBaseName = mLibraryBaseName % QLatin1String("_export");

  return IncludeStatement::fromFileBaseName( fileBaseName.toLower() );
}

QString LibraryExport::toUsageMacroString() const noexcept
{
  return mLibraryBaseName.toUpper() % QLatin1String("_EXPORT");
}

bool LibraryExport::isValidLibraryBaseName(const QString & name) noexcept
{
  QString bName = name.trimmed();

  if( bName.isEmpty() ){
    return false;
  }

  return true;
}

LibraryExport LibraryExport::fromLibraryBaseName(const QString & name) noexcept
{
  assert( isValidLibraryBaseName(name) );

  return LibraryExport( name.trimmed() );
}

LibraryExport::LibraryExport(const QString & libraryBaseName) noexcept
 : mLibraryBaseName(libraryBaseName)
{
  assert( !mLibraryBaseName.isEmpty() );
}

}} // namespace Mdt{ namespace CppRefactoring{
