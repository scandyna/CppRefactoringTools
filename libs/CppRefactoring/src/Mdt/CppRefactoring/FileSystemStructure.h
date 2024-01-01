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
#include "mdt_cpprefactoring_export.h"
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /// In FileSystemHelpers
  
  
  
  /*! \brief Check if a path refers to an existing directory
   *
   * \todo Make shure to test empty path and path without dir sep, see QDir for why !
   * \note relative path is accepted
   */
  bool isValidPathToExistingDirectory(const QString & path) noexcept;

  /*! \brief Source files root directory
   */
  class SourceFilesRootDirectory
  {
   public:

    SourceFilesRootDirectory() = delete;

    /*! \brief Get the absolute path to this directory
     */
    QString absolutePath() const noexcept
    {
    }

    /*! \brief Check if given path is valid
     *
     * Returns true if given path refers to an existing directory.
     * \sa isValidPathToExistingDirectory()
     */
    static
    bool isValidExistingPath(const QString & path) noexcept;

    /*! \brief Create a directory from existing path
     *
     */
    static
    SourceFilesRootDirectory fromExistingPath(const QString & path) noexcept;
  };

  /*! \brief Source files directory
   */
  class TestSourceFilesDirectory
  {
   public:

    TestSourceFilesDirectory() = delete;

    /*! \brief Get the absolute path to this directory
     */
    QString absolutePath() const noexcept
    {
    }

    /*! \brief Check if given path is valid
     *
     * Returns true if given path refers to an existing directory.
     * \sa isValidPathToExistingDirectory()
     */
    static
    bool isValidExistingPath(const QString & path) noexcept;

    /*! \brief Create a directory from existing path
     *
     */
    static
    TestSourceFilesDirectory fromExistingPath(const QString & path) noexcept;
  };


  /*! \brief File system builder
   */
  class FileSystemBuilder
  {
   public:

    /*! \brief Make a file system structure for a class
     */
    // static
    // FileSystemStructure makeStructure(const FileSystemEditorData & data);
  };

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
     *
     * \todo requiring args seems Nok
     */
    QString getSourceFileAbsolutePath(const DirectoryRelativePath & relativePath, const SourceFileName & name) const noexcept;

    /*! \brief Get the absolute path to the source file
     *
     * \todo requiring args seems Nok
     */
    QString getSourceFileAbsolutePath(const SourceFileName & name) const noexcept;

    /*! \brief Get the absolute path to the header file
     *
     * \todo requiring args seems Nok
     */
    QString getHeaderFileAbsolutePath(const DirectoryRelativePath & relativePath, const HeaderFileName & name) const noexcept;

    /*! \brief Get the absolute path to the header file
     *
     * \todo requiring args seems Nok
     */
    QString getHeaderFileAbsolutePath(const HeaderFileName & name) const noexcept;

    /*! \brief Get the absolute path to the test source file
     *
     * \todo requiring args seems Nok
     */
    QString getTestSourceFileAbsolutePath(const TestSourceFileName & name) const noexcept;

  private:

    
  };

  // /*! \brief Represents a FileSystemStructure that can be empty
  //  *
  //  * \todo Could probably not dispplay file paths..
  //  *
  //  * \todo Maybe, fileSystemStructure should not know about file paths ?
  //  * Hmm... yes, as helpers to build the paths
  //  */
  // class MDT_CPPREFACTORING_EXPORT FileSystemStructureViewModel
  // {
  //  public:
  // 
  //   /*! \brief Construct an empty structure
  //    */
  //   FileSystemStructureViewModel() noexcept = default;
  // };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_SYSTEM_STRUCTURE_H
