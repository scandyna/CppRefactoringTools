// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_SOURCE_FILE_CONTENT_H
#define MDT_CPP_REFACTORING_SOURCE_FILE_CONTENT_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/IncludeStatementBloc.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Content of a source file
   */
  class MDT_CPPREFACTORING_EXPORT SourceFileContent
  {
   public:

    SourceFileContent() = delete;

    /*! \brief Construct a content from given class name
     */
    SourceFileContent(const ClassName & name) noexcept
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
    QString getBeginNamespaceStringIf() const noexcept;
    QString getEndNamespaceStringIf() const noexcept;

    std::optional<TopCommentBloc> mTopCommentBloc;
    IncludeStatementBloc mIncludeStatementBloc;
    std::optional<Namespace> mNamespace;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_SOURCE_FILE_CONTENT_H
