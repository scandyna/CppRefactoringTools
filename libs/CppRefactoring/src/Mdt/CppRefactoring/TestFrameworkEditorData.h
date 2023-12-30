// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_FRAMEWORK_EDITOR_DATA_H
#define MDT_CPP_REFACTORING_TEST_FRAMEWORK_EDITOR_DATA_H

#include "Mdt/CppRefactoring/TestFrameworkType.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <QStringList>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Editor data for test framework
   *
   * \todo Rename TestEditorData
   *
   * Holds probably incomplete and invalid data.
   * At some point, validation happens and a valid TestFramework is created.
   *
   * \sa TestFramework
   * \sa TestFrameworkBuilder
   */
  struct TestFrameworkEditorData
  {
    std::optional<TestFrameworkType> type;

    /*! \brief Base name of the test
     */
    // QString testBaseName;

    /*! \brief Additional headers
     *
     * Given the additional header like:
     * \code
     * Catch2QString.h
     * Mdt/Algorithm.h
     * \endcode
     */
    QStringList sourceFileAdditionalIncludes;

    /*! \brief Additional system headers
     *
     * Given the additional header like:
     * \code
     * boost/algorithm/hex.hpp
     * QString
     * \endcode
     */
    QStringList sourceFileAdditionalSystemIncludes;

    /*! \brief
     */
    bool isNull() const noexcept
    {
      return !type.has_value();
    }
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_FRAMEWORK_EDITOR_DATA_H
