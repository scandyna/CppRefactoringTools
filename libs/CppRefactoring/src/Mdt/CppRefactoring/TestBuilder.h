// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_BUILDER_H
#define MDT_CPP_REFACTORING_TEST_BUILDER_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/TestName.h"
#include "Mdt/CppRefactoring/Test.h"
#include "Mdt/CppRefactoring/TestFrameworkEditorData.h"
#include "Mdt/CppRefactoring/TestSourceFileContent.h"
#include "mdt_cpprefactoring_export.h"

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Test builder
   */
  class MDT_CPPREFACTORING_EXPORT TestBuilder
  {
   public:

    /*! \brief Make test source file
     *
     * \todo define + implement exceptions
     *
     * \pre \a data must not be null
     */
    static
    TestSourceFileContent makeCatch2TestSourceFileContent(const TestName & testName, const ClassName & className, const TestFrameworkEditorData & data);

    /*! \brief Make a test based on Catch2 from given data
     *
     * \todo define + implement exceptions
     *
     * \pre \a data must not be null
     * \pre given data test type must be Catch2
     */
    static
    Test makeCatch2Test(const TestFrameworkEditorData & data, const ClassName & className);

    // TestFramework makeQtTestlibTest(const TestFrameworkEditorData & data);

    /*! \brief Make a test based on given data
     *
     * \todo define + implement exceptions
     *
     * \pre \a data must not be null
     */
    static
    Test makeTest(const TestFrameworkEditorData & data, const ClassName & className);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_BUILDER_H
