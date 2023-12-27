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
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

QString IncludeStatement::toString() const noexcept
{
  return QLatin1String("#include \"") % mFileBaseName % QLatin1String(".h\"");
}

IncludeStatement IncludeStatement::fromFileBaseName(const QString & name) noexcept
{
  QString bName = name.trimmed();
  assert( !bName.isEmpty() );

  return IncludeStatement(bName);
}

IncludeStatement::IncludeStatement(const QString & fileBaseName) noexcept
 : mFileBaseName(fileBaseName)
{
  assert( !mFileBaseName.trimmed().isEmpty() );
}

}} // namespace Mdt{ namespace CppRefactoring{
