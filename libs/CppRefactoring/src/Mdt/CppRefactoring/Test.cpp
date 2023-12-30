// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "Test.h"

namespace Mdt{ namespace CppRefactoring{

void Test::setTopCommentBloc(const TopCommentBloc & bloc) noexcept
{
  mTestSourceFileContent.setTopCommentBloc(bloc);
}

void Test::setNamespace(const Namespace & ns) noexcept
{
  mTestSourceFileContent.setNamespace(ns);
}

void Test::setTestSourceFileContent(const TestSourceFileContent & content) noexcept
{
  mTestSourceFileContent = content;
}

Test Test::fromClassName(const ClassName & name) noexcept
{
  return Test( TestName::fromClassName(name), name );
}

Test::Test(const TestName & name, const ClassName & className) noexcept
 : mName(name),
   mTestSourceFileName( TestSourceFileName::fromTestName(name) ),
   mTestSourceFileContent(name, className)
{
}

}} // namespace Mdt{ namespace CppRefactoring{
