// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TEST_SOURCE_FILE_CONTENT_H
#define MDT_CPP_REFACTORING_TEST_SOURCE_FILE_CONTENT_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/IncludeStatementBloc.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Test framework type
   */
  enum class TestFrameworkType
  {
    Catch2
    // QtTestLib
  };

  /*! \brief Editor data for test framework
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

  /*! \brief
   */
  class TestFramework
  {
   public:

    TestFramework() = delete;

   private:

    /// TestSourceFileContent mTestSourceFileContent;
    /// TestHeaderFileContent mTestHeaderFileContent;
  };

  /*! \brief
   */
  class TestFrameworkBuilder
  {
   public:

    TestFramework makeCatch2Framework(const TestFrameworkEditorData & data);

    TestFramework makeQtTestlibFramework(const TestFrameworkEditorData & data);
  };

  /*! \brief
   */
  class Catch2Test
  {
  };

  /*! \brief Content of a test source file
   *
   * \note TestSourceFileContent has no notion of any test framework.
   * It handles the content of the file.
   * For more elaborated test content,
   * see Catch2Test and QtTest.
   * Both uses TestSourceFileContent.
   * QtTest also uses TestHeaderFileContent.
   */
  class MDT_CPPREFACTORING_EXPORT TestSourceFileContent
  {
   public:

    TestSourceFileContent() = delete;

    /*! \brief Construct a content from given class name
     */
    TestSourceFileContent(const ClassName & name) noexcept
     : mClassName(name)
    {
      mIncludeStatementBloc.appendStatement( IncludeStatement::fromFileBaseName( name.toString() ) );
    }

    /*! \brief Set the top comment bloc
     */
    void setTopCommentBloc(const TopCommentBloc & bloc) noexcept;

    /*! \brief Set the namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Get the string representation of this content
     */
    QString toString() const noexcept;

   private:

    QString getTopCommentBlocStringIf() const noexcept;
    QString getUsingNamespaceIf() const noexcept;

    ClassName mClassName;
    std::optional<TopCommentBloc> mTopCommentBloc;
    IncludeStatementBloc mIncludeStatementBloc;
    std::optional<Namespace> mNamespace;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_SOURCE_FILE_CONTENT_H
