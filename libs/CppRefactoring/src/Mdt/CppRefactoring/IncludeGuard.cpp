// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "IncludeGuard.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

namespace Mdt{ namespace CppRefactoring{

void IncludeGuard::setNamespace(const Namespace & ns) noexcept
{
  mNamespace = ns;
}

QString IncludeGuard::toBeginString() const noexcept
{
  return QLatin1String("#ifndef ") % formatClassName()
         % QLatin1String("#define ") % formatClassName();
}

QString IncludeGuard::toEndString() const noexcept
{
  return QLatin1String("#endif // #ifndef ") % formatClassName();
}

QString IncludeGuard::formatNamespace() const noexcept
{
  if( !mNamespace.has_value() ){
    return QString();
  }

  return mNamespace->partList().join( QLatin1Char('_') ) % QLatin1Char('_');
}

QString IncludeGuard::formatClassName() const noexcept
{
  return formatNamespace() % mClassName.toString() % QLatin1String("_H\n");
}

}} // namespace Mdt{ namespace CppRefactoring{
