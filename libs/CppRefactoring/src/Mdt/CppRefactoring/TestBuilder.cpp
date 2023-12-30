// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "TestBuilder.h"
#include "TestName.h"
#include <stdexcept>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

TestSourceFileContent TestBuilder::makeCatch2TestSourceFileContent(const TestName & testName, const ClassName & className, const TestFrameworkEditorData & data)
{
  assert( !data.isNull() );
  assert( data.type.has_value() );
  assert(*data.type == TestFrameworkType::Catch2);

  TestSourceFileContent content(testName, className);

  content.addIncludeStatement( IncludeStatement::from_q_char_sequence( QLatin1String("catch2/catch.hpp") ) );

  for(const QString & includeFile : data.sourceFileAdditionalIncludes){
    content.addIncludeStatement( IncludeStatement::from_q_char_sequence(includeFile) );
  }

  for(const QString & includeFile : data.sourceFileAdditionalSystemIncludes){
    content.addIncludeStatement( IncludeStatement::systemIncludeFrom_h_char_sequence(includeFile) );
  }

  return content;
}

Test TestBuilder::makeCatch2Test(const TestFrameworkEditorData & data, const ClassName & className)
{
  assert( !data.isNull() );
  assert( data.type.has_value() );
  assert(*data.type == TestFrameworkType::Catch2);

  /// \todo validation

  auto testName = TestName::fromClassName(className);
  Test test = Test::fromClassName(className);
  test.setTestSourceFileContent( makeCatch2TestSourceFileContent(testName, className, data) );

  return test;
}

Test TestBuilder::makeTest(const TestFrameworkEditorData & data, const ClassName & className)
{
  assert( !data.isNull() );

  /// \todo validation

  switch(*data.type){
    case TestFrameworkType::Catch2:
      return makeCatch2Test(data, className);
  }

  /// \todo better translatable message
  throw std::runtime_error("unexpected test framework");
}

}} // namespace Mdt{ namespace CppRefactoring{
