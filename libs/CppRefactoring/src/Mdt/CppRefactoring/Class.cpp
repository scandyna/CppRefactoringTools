// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Class.h"
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

void Class::setNamespace(const Namespace & ns) noexcept
{
  mNamespace = ns;
  mHeaderFileContent.setNamespace(ns);
  mSourceFileContent.setNamespace(ns);
  if( hasTest() ){
    mTest->setNamespace(ns);
  }
}

const Namespace & Class::ns() const noexcept
{
  assert( isInNamespace() );

  return *mNamespace;
}

void Class::setTest(const Test & test) noexcept
{
  mTest = test;
  if(mNamespace){
    mTest->setNamespace(*mNamespace);
  }
  if(mTopCommentBloc){
    mTest->setTopCommentBloc(*mTopCommentBloc);
  }
}

void Class::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mHeaderFileContent.setTopCommentBloc(bloc);
  mSourceFileContent.setTopCommentBloc(bloc);
  mTopCommentBloc = bloc;
  if( hasTest() ){
    mTest->setTopCommentBloc(bloc);
  }
}

void Class::setLibraryExport(const LibraryExport & libraryExport) noexcept
{
  mHeaderFileContent.setLibraryExport(libraryExport);
}

Class Class::fromName(const ClassName & name) noexcept
{
  return Class(name);
}

Class::Class(const ClassName & name) noexcept
 : mName(name),
   mHeaderFileName( HeaderFileName::fromClassName(name) ),
   mSourceFileName( SourceFileName::fromClassName(name) ),
   // mTestSourceFileName( TestSourceFileName::fromClassName(name) ),
   mHeaderFileContent(name),
   mSourceFileContent(name)
   // mTestSourceFileContent(name)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
