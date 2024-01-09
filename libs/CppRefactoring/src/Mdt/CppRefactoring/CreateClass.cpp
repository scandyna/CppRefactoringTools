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
  writeSourceFile(request.c.sourceFileContent(), response.sourceFileAbsolutePath, fileOverwriteBehavior);

  if( !response.testSourceFileAbsolutePath.isEmpty() ){
    writeTestSourceFile(request.c.testSourceFileContent(), response.testSourceFileAbsolutePath, fileOverwriteBehavior);
  }

  response.isSuccess = true;

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

  checkFileExistence(response.headerFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteHeaderFile);
  checkFileExistence(response.sourceFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteSourceFile);

  if( !response.testSourceFileAbsolutePath.isEmpty() ){
    checkFileExistence(response.testSourceFileAbsolutePath, request.overwriteBehavior, response.isAskingToOverwriteTestSourceFile);
  }

  return response;
}

void CreateClass::checkFileExistence(const QString & path, CreateClassFileOverwriteBehavior overwriteBehavior, bool & askToOverwriteFlag) const
{
  const CheckIsExistingFileResponse ieResponse = FileWriter::checkIsExistingFile(path);

  if( shouldThrowError(ieResponse, overwriteBehavior) ){
    if(ieResponse == CheckIsExistingFileResponse::IsDirectory){
      const QString msg = tr("can't create file '%1' because it is a directory")
                          .arg(path);
      throw CreateClassError(msg);
    }
    if(overwriteBehavior == CreateClassFileOverwriteBehavior::Fail){
      // Here file exists
      const QString msg = tr("can't create file '%1' because it exists and overwrit behavior is to fail in that case")
                          .arg(path);
      throw CreateClassError(msg);
    }
  }
  assert( !shouldThrowError(ieResponse, overwriteBehavior) );

  askToOverwriteFlag = shouldAskOverwriteConfirmation(ieResponse, overwriteBehavior);
  if(askToOverwriteFlag){
    return;
  }

  assert( isOkToWrite(ieResponse, overwriteBehavior) );
}

void CreateClass::writeHeaderFile(const HeaderFileContent & content, const QString & path, FileOverwriteBehavior overwriteBehavior)
{
  FileWriter writer;

  writer.open(path, overwriteBehavior);
  writer.writeContent( content.toString() );

  writer.close();
}

void CreateClass::writeSourceFile(const SourceFileContent & content, const QString & path, FileOverwriteBehavior overwriteBehavior)
{
  FileWriter writer;

  writer.open(path, overwriteBehavior);
  writer.writeContent( content.toString() );

  writer.close();
}

void CreateClass::writeTestSourceFile(const TestSourceFileContent & content, const QString & path, FileOverwriteBehavior overwriteBehavior)
{
  FileWriter writer;

  writer.open(path, overwriteBehavior);
  writer.writeContent( content.toString() );

  writer.close();
}

}} // namespace Mdt{ namespace CppRefactoring{
