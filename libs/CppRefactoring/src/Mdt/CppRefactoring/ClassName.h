// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_NAME_H
#define MDT_CPP_REFACTORING_CLASS_NAME_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class holds attributes to create or rename a class
   */
  class MDT_CPPREFACTORING_EXPORT ClassName
  {
   public:

    ClassName() = delete;

    /*! \brief Get the string representation of this name
     */
    const QString & toString() const noexcept
    {
      return mName;
    }

    /*! \brief Check if given name is valid for a class name
     *
     * \todo implement real rules
     */
    static
    bool isValidString(const QString & name) noexcept;

    /*! \brief Create a class name from string
     *
     * \pre \a name must be a vlaid string
     * \sa isValidString()
     */
    static
    ClassName fromString(const QString & name) noexcept;

   private:

    ClassName(const QString & name) noexcept;

    QString mName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_NAME_H
