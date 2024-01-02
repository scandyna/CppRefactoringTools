// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_EDITOR_DATA_H
#define MDT_CPP_REFACTORING_FILE_SYSTEM_EDITOR_DATA_H

#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief File system editor data
   *
   * \sa FileSystemStructure
   * \sa FileSystemBuilder
   */
  struct MDT_CPPREFACTORING_EXPORT FileSystemEditorData
  {
    QString sourceFilesRootDirectoryAbsolutePath;
    QString testSourceFilesDirectoryAbsolutePath;

    /*! \brief Check if this data seems complete
     *
     * Retruns true if all mandatory fileds have some value.
     * The validity of the data is not checked here.
     */
    bool seemsComplete() const noexcept;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_EDITOR_DATA_H
