// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_H
#define MDT_CPP_REFACTORING_CLASS_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "Mdt/CppRefactoring/HeaderFileName.h"
#include "Mdt/CppRefactoring/SourceFileName.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class holds attributes to create or rename a class
   */
  class MDT_CPPREFACTORING_EXPORT Class
  {
   public:

    Class() = delete;

    /*! \brief Get the name of this class
     */
    const ClassName & name() const noexcept
    {
      return mName;
    }

    /*! \brief Check if this class is in a namespace
     */
    bool isInNamespace() const noexcept
    {
    }

    /*! \brief Put this class into a namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Get the header file name
     */
    const HeaderFileName & headerFileName() const noexcept
    {
      return mHeaderFileName;
    }

    /*! \brief Get the source file name
     */
    const SourceFileName & sourceFileName() const noexcept
    {
      return mSourceFileName;
    }

    /*! \brief Create a class from given name
     *
     * \pre \a name must be valid
     * \sa isValidName()
     */
    static
    Class fromName(const ClassName & name) noexcept;

   private:

    Class(const ClassName & name) noexcept;

    ClassName mName;
    std::optional<Namespace> mNamespace;
    HeaderFileName mHeaderFileName;
    SourceFileName mSourceFileName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // MDT_CPP_REFACTORING_CLASS_H
