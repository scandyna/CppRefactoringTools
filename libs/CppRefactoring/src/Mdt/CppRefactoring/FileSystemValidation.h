// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_VALIDATION_H
#define MDT_CPP_REFACTORING_FILE_SYSTEM_VALIDATION_H

#include "Mdt/CppRefactoring/FileSystemValidationError.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief File system validation
   */
  class MDT_CPPREFACTORING_EXPORT FileSystemValidation : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Validate given path for a source files root directory
     *
     * \exception FileSystemValidationError
     * \sa SourceFilesRootDirectory::isValidExistingPath()
     */
    static
    void validateSourceFilesRootDirectoryPath(const QString & path);

    /*! \brief Validate given path for a test source files root directory
     *
     * \exception FileSystemValidationError
     * \sa TestSourceFilesRootDirectory::isValidExistingPath()
     */
    static
    void validateTestSourceFilesRootDirectoryPath(const QString & path);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_VALIDATION_H
