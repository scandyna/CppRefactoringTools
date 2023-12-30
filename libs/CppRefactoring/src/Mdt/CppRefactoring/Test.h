// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_H
#define MDT_CPP_REFACTORING_TEST_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/TestName.h"
#include "Mdt/CppRefactoring/TestSourceFileName.h"
#include "Mdt/CppRefactoring/TestSourceFileContent.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "mdt_cpprefactoring_export.h"

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Test holds attributes for a test
   */
  class MDT_CPPREFACTORING_EXPORT Test
  {
   public:

    Test() = delete;

    /*! \brief Set the top comment bloc
     */
    void setTopCommentBloc(const TopCommentBloc & bloc) noexcept;

    /*! \brief Set the namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Get the name of this test
     */
    const TestName & name() const noexcept
    {
      return mName;
    }

    /*! \brief Get the test source file name
     */
    const TestSourceFileName & testSourceFileName() const noexcept
    {
      return mTestSourceFileName;
    }

    /*! \brief Set the test source file content
     */
    void setTestSourceFileContent(const TestSourceFileContent & content) noexcept;

    /*! \brief Get the test source file content
     */
    const TestSourceFileContent & testSourceFileContent() const noexcept
    {
      return mTestSourceFileContent;
    }

    /*! \brief Create a test from given class name
     */
    static
    Test fromClassName(const ClassName & name) noexcept;

   private:

    Test(const TestName & name, const ClassName & className) noexcept;

    TestName mName;
    TestSourceFileName mTestSourceFileName;
    TestSourceFileContent mTestSourceFileContent;
    /// TestHeaderFileContent mTestHeaderFileContent;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_H
