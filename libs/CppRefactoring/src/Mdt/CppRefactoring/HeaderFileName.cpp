// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "HeaderFileName.h"
#include <QStringBuilder>
#include <QLatin1String>

namespace Mdt{ namespace CppRefactoring{

HeaderFileName HeaderFileName::fromClassName(const ClassName & name) noexcept
{
  return HeaderFileName(name);
}

HeaderFileName::HeaderFileName(const ClassName & className) noexcept
 : mName( className.toString() % QLatin1String(".h") )
{
}

}} // namespace Mdt{ namespace CppRefactoring{
