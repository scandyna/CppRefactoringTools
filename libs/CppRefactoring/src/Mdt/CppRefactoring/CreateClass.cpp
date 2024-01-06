// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "CreateClass.h"
#include "ClassFileSystemStructure.h"

// #include "FileWriter.h"
#include <QFile>

#include <QDebug>

namespace Mdt{ namespace CppRefactoring{

CreateClass::CreateClass(QObject *parent) noexcept
 : QObject(parent)
{
}

CreateClassResponse CreateClass::execute(const CreateClassRequest & request)
{
  CreateClassResponse response = getFilePathsAndCheckFilesExistence(request);

  if( response.isAskingToOverwriteFile() ){
    return response;
  }

  FileOverwriteBehavior fileOverwriteBehavior = fileOverwriteBehaviorFromRequest(request);

  writeHeaderFile(request.c.headerFileContent(), response.headerFileAbsolutePath, fileOverwriteBehavior);
  

  if( !response.testSourceFileAbsolutePath.isEmpty() ){
    
  }

  // try{
  //   writeHeaderFile(request.c.headerFileContent(), headerFilePath, request.overwriteBehavior);
  // }catch(const FileWriteError & error){
  //   if( error.isOverwriteFailure() ){
  //     response.isAskingToOverwriteFile = true;
  //   }
  // }

  return response;
}

bool CreateClass::shouldAskOverwriteConfirmation(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept
{
  if(overwriteBehavior != CreateClassFileOverwriteBehavior::AskConfirmation){
    return false;
  }
  if(response != CheckIsExistingFileResponse::IsExistingFile){
    return false;
  }

  return true;
}

bool CreateClass::shouldThrowError(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept
{
  if(response == CheckIsExistingFileResponse::IsDirectory){
    return true;
  }
  if(response == CheckIsExistingFileResponse::IsExistingFile){
    return overwriteBehavior == CreateClassFileOverwriteBehavior::Fail;
  }

  return false;
}

bool CreateClass::isOkToWrite(CheckIsExistingFileResponse response, CreateClassFileOverwriteBehavior overwriteBehavior) noexcept
{
  if(response == CheckIsExistingFileResponse::NonExisting){
    return true;
  }
  if(response == CheckIsExistingFileResponse::IsExistingFile){
    return overwriteBehavior == CreateClassFileOverwriteBehavior::Overwrite;
  }

  return false;
}

FileOverwriteBehavior CreateClass::fileOverwriteBehaviorFromRequest(const CreateClassRequest & request) const noexcept
{
  switch(request.overwriteBehavior){
    case CreateClassFileOverwriteBehavior::AskConfirmation:
    case CreateClassFileOverwriteBehavior::Overwrite:
      return FileOverwriteBehavior::Overwrite;
    case CreateClassFileOverwriteBehavior::Fail:
      break;
  }

  return FileOverwriteBehavior::Fail;
}

CreateClassResponse CreateClass::getFilePathsAndCheckFilesExistence(const CreateClassRequest & request) const
{
  CreateClassResponse response;

  ClassFileSystemStructure fss(request.fileSystemStructure);

  response.headerFileAbsolutePath = fss.getHeaderFileAbsolutePath(request.c);
  response.sourceFileAbsolutePath = fss.getSourceFileAbsolutePath(request.c);

  if( request.c.hasTest() ){
    response.testSourceFileAbsolutePath = fss.getTestSourceFileAbsolutePath(request.c);
  }

  qDebug() << "header file: " << response.headerFileAbsolutePath;
  qDebug() << "source file: " << response.sourceFileAbsolutePath;
  qDebug() << "test source file: " << response.testSourceFileAbsolutePath;

  checkFileExistence(response.headerFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteHeaderFile);
  checkFileExistence(response.sourceFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteSourceFile);

  if( !response.testSourceFileAbsolutePath.isEmpty() ){
    checkFileExistence(response.testSourceFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteTestSourceFile);
  }

  return response;
}

void CreateClass::checkFileExistence(const QString & path, CreateClassFileOverwriteBehavior overwriteBehavior, bool & askToOverwriteFlag) const
{
  /// Check if header file exists
  /// - If is dir - error
  /// - If not exists - Ok
  /// - If exists:
  ///   - If Fail - error
  ///   - If AskConfirmation - Flag
  ///   - If Overwrite - Ok

  const CheckIsExistingFileResponse ieResponse = FileWriter::checkIsExistingFile(path);
  
  if( shouldThrowError(ieResponse, overwriteBehavior) ){
    if(ieResponse == CheckIsExistingFileResponse::IsDirectory){
      /// \todo throw
    }
    if(overwriteBehavior == CreateClassFileOverwriteBehavior::Fail){
      // Here file exists
      /// \todo throw
    }
  }
  assert( !shouldThrowError(ieResponse, overwriteBehavior) );

  askToOverwriteFlag = shouldAskOverwriteConfirmation(ieResponse, overwriteBehavior);

  assert( isOkToWrite(ieResponse, overwriteBehavior) );
}

void CreateClass::writeHeaderFile(const HeaderFileContent & content, const QString & path, FileOverwriteBehavior overwriteBehavior)
{
  /// Check exisence of given path
  /// - If is existing dir, fail
  /// - If is existing file:
  ///   - case overwriteBehavior is Fail: throw with error
  ///   - case overwriteBehavior is Ask: throw with ??
  

}

}} // namespace Mdt{ namespace CppRefactoring{
