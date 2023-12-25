// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "CreateClassEditor.h"
#include "Mdt/CppRefactoring/ClassBuilder.h"
#include <cassert>

using namespace Mdt::CppRefactoring;


CreateClassEditor::CreateClassEditor(QObject* parent) noexcept
 : QObject(parent)
{
}

const Class & CreateClassEditor::validClass() const noexcept
{
  assert( hasValidClass() );

  return *mClass;
}

void CreateClassEditor::setClassName(const QString & name)
{
  mEditorData.className = name;

  /// \todo If name is valid, should change state to enable possible functions
}

void CreateClassEditor::setNamespace(const QString& ns)
{
  mEditorData.namespaceStr = ns;
}

void CreateClassEditor::setTopCommentBloc(const QString& bloc)
{
  mEditorData.topCommentBloc = bloc;
}

void CreateClassEditor::refresh() noexcept
{
  mClass = ClassBuilder::makeClass(mEditorData);

  emit classUpdated(*mClass);
}
