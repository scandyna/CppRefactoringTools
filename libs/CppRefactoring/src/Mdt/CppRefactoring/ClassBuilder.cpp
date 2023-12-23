// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "ClassBuilder.h"

namespace Mdt{ namespace CppRefactoring{

ClassBuilder::ClassBuilder(QObject *parent) noexcept
 : QObject(parent)
{
}

ClassName ClassBuilder::makeClassName(const QString & name)
{
  /// \todo validation

  return ClassName::fromString(name);
}

Class ClassBuilder::makeClass(const ClassEditorData & editorData)
{
  ClassName name = makeClassName(editorData.className);

  Class c = Class::fromName(name);

  return c;
}

}} // namespace Mdt{ namespace CppRefactoring{
