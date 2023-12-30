// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_NAME_H
#define MDT_CPP_REFACTORING_TEST_NAME_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Name of a test
   */
  class MDT_CPPREFACTORING_EXPORT TestName
  {
   public:

    TestName() = delete;

    /*! \brief Get the string representation of this name
     */
    const QString & toString() const noexcept
    {
      return mName;
    }

    /*! \brief Check if given name is valid for a test name
     *
     * \todo implement real rules
     */
    static
    bool isValidString(const QString & name) noexcept;

    /*! \brief Create a test name from base name string
     *
     * \pre \a name must be a vlaid string
     * \sa isValidString()
     */
    static
    TestName fromBaseNameString(const QString & name) noexcept;

    /*! \brief Create a test name from given class name
     */
    static
    TestName fromClassName(const ClassName & name) noexcept;

   private:

    TestName(const QString & name) noexcept;

    QString mName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_NAME_H
