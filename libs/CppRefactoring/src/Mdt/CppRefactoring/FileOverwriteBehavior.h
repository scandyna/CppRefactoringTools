// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_OVERWRITE_BEHAVIOR_H
#define MDT_CPP_REFACTORING_FILE_OVERWRITE_BEHAVIOR_H

namespace Mdt{ namespace CppRefactoring{

  /*! \brief File overwrite behavior
   */
  enum class FileOverwriteBehavior
  {
    Fail,
    Overwrite
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_OVERWRITE_BEHAVIOR_H
