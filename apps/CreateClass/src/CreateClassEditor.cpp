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
#include "Mdt/CppRefactoring/Namespace.h"
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
  // mEditorData.testFrameworkData.testBaseName = name;

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

void CreateClassEditor::setUseLibraryExport(bool use) noexcept
{
  mEditorData.useLibraryExport = use;
}

void CreateClassEditor::setLibraryBaseName(const QString& name) noexcept
{
  mEditorData.libraryBaseName = name;
}

/// \todo Really just a sandbox
void CreateClassEditor::setLibraryBaseNameFromNamespace() noexcept
{
  auto ns = Namespace::fromColonSeparatedString(mEditorData.namespaceStr);

  mEditorData.libraryBaseName = ns.partList().join( QLatin1Char('_') );

  emit libraryBaseNameGenerated(mEditorData.libraryBaseName);
}

void CreateClassEditor::setTestFrameworkType(Mdt::CppRefactoring::TestFrameworkType type) noexcept
{
  mEditorData.testFrameworkData.type = type;
}

void CreateClassEditor::setTestSourceFileAdditionalIncludes(const QStringList& headers) noexcept
{
  mEditorData.testFrameworkData.sourceFileAdditionalIncludes = headers;
}

void CreateClassEditor::setTestSourceFileAdditionalSystemIncludes(const QStringList & headers) noexcept
{
  mEditorData.testFrameworkData.sourceFileAdditionalSystemIncludes = headers;
}

void CreateClassEditor::refresh() noexcept
{
  mClass = ClassBuilder::makeClass(mEditorData);

  emit classUpdated(*mClass);
}
