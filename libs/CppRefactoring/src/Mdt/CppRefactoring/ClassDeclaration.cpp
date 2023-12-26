// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "ClassDeclaration.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

void ClassDeclaration::setIndentationCharCount(int charCount) noexcept
{
  assert(charCount >= 0);
  assert(charCount <= 20);

  mIndentationCharCount = charCount;
}

QString ClassDeclaration::toString() const noexcept
{
  return getIndentationString() % QLatin1String("class ") % mClassName.toString() % QLatin1Char('\n')
         % getIndentationString() % QLatin1String("{\n")
         % getIndentationString() % QLatin1String("};");
}

QString ClassDeclaration::getIndentationString() const noexcept
{
  return QString( mIndentationCharCount, QLatin1Char(' ') );
}

}} // namespace Mdt{ namespace CppRefactoring{
