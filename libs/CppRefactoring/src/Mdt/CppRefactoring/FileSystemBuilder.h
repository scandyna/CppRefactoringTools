// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_BUILDER_H
#define MDT_CPP_REFACTORING_FILE_SYSTEM_BUILDER_H

#include "Mdt/CppRefactoring/FileSystemEditorData.h"
#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/FileSystemValidationError.h"
#include "mdt_cpprefactoring_export.h"

namespace Mdt{ namespace CppRefactoring{

  /*! \brief File system builder
   */
  class MDT_CPPREFACTORING_EXPORT FileSystemBuilder
  {
   public:

    /*! \brief Make a file system structure
     *
     * \exception FileSystemValidationError
     */
    static
    FileSystemStructure makeStructure(const FileSystemEditorData & data);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_BUILDER_H
