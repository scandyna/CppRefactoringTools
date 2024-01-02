// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_STRUCTURE_H
#define MDT_CPP_REFACTORING_FILE_SYSTEM_STRUCTURE_H

#include "Mdt/CppRefactoring/HeaderFileName.h"
#include "Mdt/CppRefactoring/SourceFileName.h"
#include "Mdt/CppRefactoring/TestSourceFileName.h"
#include "Mdt/CppRefactoring/DirectoryRelativePath.h"
#include "Mdt/CppRefactoring/SourceFilesRootDirectory.h"
#include "Mdt/CppRefactoring/TestSourceFilesDirectory.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Request to create a class
   */
  struct CreateClassRequest
  {
    // Class c;
    // FileSystemStructure fileSystemStructure;
    bool overwriteIfExists = false;
  };

  /*! \brief Create a class
   */
  class CreateClass
  {
  };

  /*! \brief File system structure
   *
   * This structure holds information for a class, or similar entity.
   * It groups informations about the location of a header file,
   * source file, a test source file and maybe a test header file.
   *
   * This class has no concept of a project.
   *
   * \todo Should ProjectFileSystemStructure be implemented to support a project ?
   *
   *
   * \code
   * project
   *  |-src // source and header files root directory
   *  |-tests
   *     |-src // test source (and header) files directory
   * \endcode
   *
   * \code
   * project
   *  |-apps
   *  |  |-MyApp
   *  |     |-src
   *  |     |-tests
   *  |        |-src
   *  |-libs
   *     |-SomeLib
   *        |-src  // source and header files root directory
   *        |  |-Mdt
   *        |     |-SomeLib
   *        |-tests
   *           |-src // test source (and header) files directory
   * \endcode
   *
   * \code
   * build
   *  |-project
   *     |-...
   * \endcode
   *
   * \sa ClassFileSystemStructure
   */
  class MDT_CPPREFACTORING_EXPORT FileSystemStructure
  {
   public:

    FileSystemStructure() = delete;

    /*! \brief Construct a file system structure
     */
    FileSystemStructure(const SourceFilesRootDirectory & sourceFilesRootDirectory,
                        const TestSourceFilesDirectory & testSourceFilesDirectory) noexcept;

    // /*! \brief Set the relative path to the source files
    //  */
    // void setSourceFilesRelativePath(const DirectoryRelativePath & path) noexcept;

    /*! \brief Get the absolute path to the source files directory
     */
    QString sourceFilesRootDirectoryAbsolutePath() const noexcept;

    /*! \brief Get the absolute path to the header files directory
     *
     * returns sourceFilesRootDirectoryAbsolutePath() by default
     */
    QString headerFilesRootDirectoryAbsolutePath() const noexcept;

    /*! \brief Get the absolute path to the tests source files directory
     */
    QString testSourceFilesDirectoryAbsolutePath() const noexcept;

    /*! \brief Get the absolute path to the source file
     */
    // QString getSourceFileAbsolutePath(const DirectoryRelativePath & relativePath, const SourceFileName & name) const noexcept;

    /*! \brief Get the absolute path to the source file
     */
    // QString getSourceFileAbsolutePath(const SourceFileName & name) const noexcept;

    /*! \brief Get the absolute path to the header file
     */
    // QString getHeaderFileAbsolutePath(const DirectoryRelativePath & relativePath, const HeaderFileName & name) const noexcept;

    /*! \brief Get the absolute path to the header file
     */
    // QString getHeaderFileAbsolutePath(const HeaderFileName & name) const noexcept;

    /*! \brief Get the absolute path to the test source file
     */
    // QString getTestSourceFileAbsolutePath(const TestSourceFileName & name) const noexcept;

  private:

    SourceFilesRootDirectory mSourceFilesRootDirectory;
    TestSourceFilesDirectory mTestSourceFilesDirectory;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_STRUCTURE_H
