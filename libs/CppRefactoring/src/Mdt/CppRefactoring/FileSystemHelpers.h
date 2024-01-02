// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_HELPERS_H
#define MDT_CPP_REFACTORING_FILE_SYSTEM_HELPERS_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Check if a path refers to an existing directory
   *
   * \todo Make shure to test empty path and path without dir sep, see QDir for why !
   * \note relative path is accepted
   */
  MDT_CPPREFACTORING_EXPORT
  bool isValidPathToExistingDirectory(const QString & path) noexcept;

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_HELPERS_H
