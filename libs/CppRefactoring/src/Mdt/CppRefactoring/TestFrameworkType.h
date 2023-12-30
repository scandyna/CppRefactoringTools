// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_FRAMEWORK_TYPE_H
#define MDT_CPP_REFACTORING_TEST_FRAMEWORK_TYPE_H

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Test framework type
   */
  enum class TestFrameworkType
  {
    Catch2
    // QtTestLib
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_FRAMEWORK_TYPE_H
