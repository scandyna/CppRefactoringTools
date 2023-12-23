// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_SOURCE_FILE_NAME_H
#define MDT_CPP_REFACTORING_SOURCE_FILE_NAME_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Represents a header file name
   */
  class MDT_CPPREFACTORING_EXPORT SourceFileName
  {
   public:

    SourceFileName() = delete;

    /*! \brief Get the string representation of this file name
     */
    const QString & toString() const noexcept
    {
      return mName;
    }

    /*! \brief Create a file name from given class name
     */
    static
    SourceFileName fromClassName(const ClassName & name) noexcept;

   private:

    SourceFileName(const ClassName & className) noexcept;

    QString mName;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_SOURCE_FILE_NAME_H
