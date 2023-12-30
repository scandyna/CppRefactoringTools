// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_EDITOR_DATA_H
#define MDT_CPP_REFACTORING_CLASS_EDITOR_DATA_H

#include "Mdt/CppRefactoring/TestFrameworkEditorData.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Editor data
   *
   * Holds probably incomplete and invalid data.
   * At some point, validation happens and a valid Class is created.
   *
   * \sa Class
   * \sa ClassBuilder
   */
  struct ClassEditorData
  {
    QString className;
    QString namespaceStr;
    QString topCommentBloc;
    bool useLibraryExport = false;
    QString libraryBaseName;
    TestFrameworkEditorData testFrameworkData;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // MDT_CPP_REFACTORING_CLASS_EDITOR_DATA_H
