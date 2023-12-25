// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_INCLUDE_GUARD_H
#define MDT_CPP_REFACTORING_INCLUDE_GUARD_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Include guard
   */
  class MDT_CPPREFACTORING_EXPORT IncludeGuard
  {
   public:

    IncludeGuard() = delete;

    /*! \brief Construct an include guard from given class name
     */
    IncludeGuard(const ClassName & name) noexcept
     : mClassName(name)
    {
    }

    /*! \brief Set the namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Get the begin string representation
     */
    QString toBeginString() const noexcept;

    /*! \brief Get the end string representation
     */
    QString toEndString() const noexcept;

   private:

    QString formatNamespace() const noexcept;
    QString formatClassName() const noexcept;

    ClassName mClassName;
    std::optional<Namespace> mNamespace;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_INCLUDE_GUARD_H
