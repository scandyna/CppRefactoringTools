// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_VALIDATION_ERROR_H
#define MDT_CPP_REFACTORING_CLASS_VALIDATION_ERROR_H

#include "Mdt/CppRefactoring/QRuntimeError.h"
#include "mdt_cpprefactoring_export.h"

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Error thrown when (editor) data validation fails
   */
  class MDT_CPPREFACTORING_EXPORT ClassValidationError : public QRuntimeError
  {
   public:

    /*! \brief Constructor
     */
    explicit
    ClassValidationError(const QString & text)
     : QRuntimeError(text)
    {
    }
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_VALIDATION_ERROR_H
