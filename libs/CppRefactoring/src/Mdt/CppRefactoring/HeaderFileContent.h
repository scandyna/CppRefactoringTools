// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_HEADER_FILE_CONTENT_H
#define MDT_CPP_REFACTORING_HEADER_FILE_CONTENT_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/IncludeGuard.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Content of a header file
   */
  class MDT_CPPREFACTORING_EXPORT HeaderFileContent
  {
   public:

    HeaderFileContent() = delete;

    /*! \brief Construct a content from given class name
     */
    HeaderFileContent(const ClassName & name) noexcept
     : mIncludeGuard(name)
    {
    }

    /*! \brief Check if the top comment bloc is present
     */
    bool hasTopCommentBloc() const noexcept
    {
      return mTopCommentBloc.has_value();
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

    QString getBeginNamespaceStringIf() const;
    QString getEndNamespaceStringIf() const;

    std::optional<TopCommentBloc> mTopCommentBloc;
    IncludeGuard mIncludeGuard;
    std::optional<Namespace> mNamespace;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_HEADER_FILE_CONTENT_H
