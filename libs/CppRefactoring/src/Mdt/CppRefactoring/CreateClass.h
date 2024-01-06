// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CREATE_CLASS_H
#define MDT_CPP_REFACTORING_CREATE_CLASS_H

#include "Mdt/CppRefactoring/FileOverwriteBehavior.h"
#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/Class.h"
#include "Mdt/CppRefactoring/HeaderFileContent.h"
#include "Mdt/CppRefactoring/SourceFileContent.h"
#include "Mdt/CppRefactoring/TestSourceFileContent.h"
#include "Mdt/CppRefactoring/FileWriter.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Overwrite behavior for files when creating a class
   */
  enum class CreateClassFileOverwriteBehavior
  {
    Fail,
    AskConfirmation,
    Overwrite
  };

  /*! \brief Request to create a class
   *
   * \sa CreateClass
   */
  struct CreateClassRequest
  {
    Class c;
    FileSystemStructure fileSystemStructure;
    CreateClassFileOverwriteBehavior overwriteBehavior = CreateClassFileOverwriteBehavior::Fail;
  };

  /*! \brief Response after a class has been created
   *
   * \sa CreateClass
   */
  struct CreateClassResponse
  {
    bool isSuccess = false;
    bool isAskingToOverwriteHeaderFile = false;
    bool isAskingToOverwriteSourceFile = false;
    bool isAskingToOverwriteTestSourceFile = false;

    // bool isAskingToOverwriteFile = false;

    QString headerFileAbsolutePath;
    QString sourceFileAbsolutePath;
    QString testSourceFileAbsolutePath;

   //  bool isSuccess() const noexcept
   //  {
   //    return mIsSuccess;
   //  }

    bool isAskingToOverwriteFile() const noexcept
    {
      return isAskingToOverwriteHeaderFile || isAskingToOverwriteSourceFile || isAskingToOverwriteTestSourceFile;
    }

   private:

    // bool mIsSuccess = false;
    // bool mIsAskingToOverwriteHeaderFile = false;
    // bool mIsAskingToOverwriteSourceFile = false;
    // bool mIsAskingToOverwriteTestSourceFile = false;
  };

  /*! \brief Error thrown when writing a file fails
   */
  class FileWriteError
  {
   public:

    /*! \brief Check if this error is due to an attempt to overwrite a file
     *
     * Returns true if a file already exists,
     * and it was requested to fail on that case.
     */
    // bool isOverwriteFailure() const noexcept
    // {
    // }
  };

  /*! \brief Create a class
   */
  class MDT_CPPREFACTORING_EXPORT CreateClass : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Constructor
     */
    explicit
    CreateClass(QObject *parent = nullptr) noexcept;

    /*! \brief Create a class for given request
     *
     * \todo define and implement exceptions
     */
    CreateClassResponse execute(const CreateClassRequest & request);

    static
    bool shouldAskOverwriteConfirmation(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept;

    static
    bool shouldThrowError(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept;

    static
    bool isOkToWrite(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept;

   private:

    FileOverwriteBehavior fileOverwriteBehaviorFromRequest(const CreateClassRequest & request) const noexcept;

    CreateClassResponse getFilePathsAndCheckFilesExistence(const CreateClassRequest & request) const;
    void checkFileExistence(const QString & path, CreateClassFileOverwriteBehavior overwriteBehavior, bool & askToOverwriteFlag) const;

    void writeHeaderFile(const HeaderFileContent & content, const QString & path, FileOverwriteBehavior overwriteBehavior);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CREATE_CLASS_H
