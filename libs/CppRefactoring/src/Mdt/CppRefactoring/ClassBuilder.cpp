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
#include "TopCommentBloc.h"
#include "LibraryExport.h"
#include "TestBuilder.h"
#include "ClassValidation.h"

namespace Mdt{ namespace CppRefactoring{

ClassBuilder::ClassBuilder(QObject *parent) noexcept
 : QObject(parent)
{
}

ClassName ClassBuilder::makeClassName(const QString & name)
{
  ClassValidation::validateClassNameString(name);

  return ClassName::fromString(name);
}

Namespace ClassBuilder::makeNamespaceFromColonSeparatedString(const QString & str)
{
  ClassValidation::validateNamespaceColonSeparatedString(str);

  return Namespace::fromColonSeparatedString(str);
}

Class ClassBuilder::makeClass(const ClassEditorData & editorData)
{
  ClassValidation::validateEditorData(editorData);

  ClassName name = makeClassName(editorData.className);

  Class c = Class::fromName(name);

  QString nsStr = editorData.namespaceStr.trimmed();
  if( !nsStr.isEmpty() ){
    c.setNamespace( makeNamespaceFromColonSeparatedString(nsStr) );
  }

  const QString topCommentBloc = editorData.topCommentBloc.trimmed();
  if( !topCommentBloc.isEmpty() ){
    c.setTopCommentBloc( TopCommentBloc::fromString(topCommentBloc) );
  }

  if(editorData.useLibraryExport){
    auto libraryExport = LibraryExport::fromLibraryBaseName(editorData.libraryBaseName);
    c.setLibraryExport(libraryExport);
  }

  if( !editorData.testFrameworkData.isNull() ){
    c.setTest( TestBuilder::makeTest(editorData.testFrameworkData, name) );
  }

  return c;
}

}} // namespace Mdt{ namespace CppRefactoring{
