// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "HeaderFileContent.h"
#include <QLatin1Char>
#include <QLatin1String>
#include <QStringBuilder>

namespace Mdt{ namespace CppRefactoring{

void HeaderFileContent::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mTopCommentBloc = bloc;
}

void HeaderFileContent::setNamespace(const Namespace & ns) noexcept
{
  mIncludeGuard.setNamespace(ns);
  mNamespace = ns;
  mClassDeclaration.setIndentationCharCount(2);
}

void HeaderFileContent::setLibraryExport(const LibraryExport & libraryExport) noexcept
{
  mLibraryExport = libraryExport;
  mClassDeclaration.setLibraryExport(libraryExport);
  /// \todo Shoud not add if alreay present, but replace
  mIncludeStatementBloc.appendStatement( libraryExport.toIncludeStatement() );
}

QString HeaderFileContent::toString() const noexcept
{
  QString str;

  if( hasTopCommentBloc() ){
    str += mTopCommentBloc->toString() % QLatin1Char('\n');
  }

  str += mIncludeGuard.toBeginString()
      % QLatin1Char('\n')
      % getIncludeBlocStringIf()
      % getBeginNamespaceStringIf()
      % mClassDeclaration.toString()
      % QLatin1Char('\n')
      % QLatin1Char('\n')
      % getEndNamespaceStringIf()
      % mIncludeGuard.toEndString();

  return str;
}

QString HeaderFileContent::getBeginNamespaceStringIf() const noexcept
{
  if(mNamespace){
    return mNamespace->toBeginString() % QLatin1String("\n\n");
  }
  return QString();
}

QString HeaderFileContent::getEndNamespaceStringIf() const noexcept
{
  if(mNamespace){
   return mNamespace->toEndString() % QLatin1String("\n\n");
  }
  return QString();
}

QString HeaderFileContent::getIncludeBlocStringIf() const noexcept
{
  if( mIncludeStatementBloc.isEmpty() ){
    return QString();
  }

  return mIncludeStatementBloc.toString() % QLatin1String("\n\n");
}

}} // namespace Mdt{ namespace CppRefactoring{
