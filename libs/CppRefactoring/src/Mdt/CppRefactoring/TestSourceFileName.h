// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_SOURCE_FILE_NAME_H
#define MDT_CPP_REFACTORING_TEST_SOURCE_FILE_NAME_H

#include "Mdt/CppRefactoring/TestName.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Represents a test source file name
   */
  class MDT_CPPREFACTORING_EXPORT TestSourceFileName
  {
   public:

    TestSourceFileName() = delete;

    /*! \brief Get the string representation of this file name
     */
    const QString & toString() const noexcept
    {
      return mName;
    }

    /*! \brief Create a file name from given test name
     */
    static
    TestSourceFileName fromTestName(const TestName & name) noexcept;

   private:

    TestSourceFileName(const TestName & testName) noexcept;

    QString mName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_SOURCE_FILE_NAME_H
