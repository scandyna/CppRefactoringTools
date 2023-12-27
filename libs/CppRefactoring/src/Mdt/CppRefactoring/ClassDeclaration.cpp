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

void ClassDeclaration::setLibraryExport(const LibraryExport & libraryExport) noexcept
{
  mLibraryExport = libraryExport;
}

QString ClassDeclaration::toString() const noexcept
{
  return getIndentationString() % QLatin1String("class ") % getLibraryExportMacroIf() % mClassName.toString() % QLatin1Char('\n')
         % getIndentationString() % QLatin1String("{\n")
         % getIndentationString() % QLatin1String("};");
}

QString ClassDeclaration::getIndentationString() const noexcept
{
  return QString( mIndentationCharCount, QLatin1Char(' ') );
}

QString ClassDeclaration::getLibraryExportMacroIf() const noexcept
{
  if(mLibraryExport){
    return mLibraryExport->toUsageMacroString() % QLatin1Char(' ');
  }
  return QString();
}

}} // namespace Mdt{ namespace CppRefactoring{
