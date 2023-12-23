// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "SourceFileName.h"
#include <QStringBuilder>
#include <QLatin1String>

namespace Mdt{ namespace CppRefactoring{

SourceFileName SourceFileName::fromClassName(const ClassName & name) noexcept
{
  return SourceFileName(name);
}

SourceFileName::SourceFileName(const ClassName & className) noexcept
 : mName( className.toString() % QLatin1String(".cpp") )
{
}

}} // namespace Mdt{ namespace CppRefactoring{
