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
#include "Mdt/CppRefactoring/TestName.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/IncludeStatement.h"
#include "Mdt/CppRefactoring/IncludeStatementBloc.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

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

    /*! \brief Construct a content from given test name and class name
     */
    TestSourceFileContent(const TestName & name, const ClassName & className) noexcept
     : mTestName(name),
       mClassName(className)
    {
      mIncludeStatementBloc.appendStatement( IncludeStatement::fromFileBaseName( className.toString() ) );
    }

    /*! \brief Set the top comment bloc
     */
    void setTopCommentBloc(const TopCommentBloc & bloc) noexcept;

    /*! \brief Set the namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Check if a namespace has been set
     */
    bool hasNamespace() const noexcept
    {
      return mNamespace.has_value();
    }

    /*! \brief Check if this content has a top comment bloc
     */
    bool hasTopCommentBloc() const noexcept
    {
      return mTopCommentBloc.has_value();
    }

    /*! \brief Add an include statement
     */
    void addIncludeStatement(const IncludeStatement & statement) noexcept;

    /*! \brief Get the include statement bloc
     */
    const IncludeStatementBloc & includeStatementBloc() const noexcept
    {
      return mIncludeStatementBloc;
    }

    /*! \brief Get the string representation of this content
     */
    QString toString() const noexcept;

   private:

    QString getTopCommentBlocStringIf() const noexcept;
    QString getUsingNamespaceIf() const noexcept;

    TestName mTestName;
    ClassName mClassName;
    std::optional<TopCommentBloc> mTopCommentBloc;
    IncludeStatementBloc mIncludeStatementBloc;
    std::optional<Namespace> mNamespace;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TEST_SOURCE_FILE_CONTENT_H
