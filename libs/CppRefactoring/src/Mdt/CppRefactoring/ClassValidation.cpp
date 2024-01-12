// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "ClassValidation.h"
#include "ClassName.h"
#include "LibraryExport.h"
#include "Namespace.h"

namespace Mdt{ namespace CppRefactoring{

ClassValidation::ClassValidation(QObject *parent) noexcept
 : QObject(parent)
{
}

void ClassValidation::validateClassNameString(const QString & name)
{
  if( !ClassName::isValidString(name) ){
    QString msg = tr("'%1' is not a valid name for a class")
                  .arg(name);
    throw ClassValidationError(msg);
  }
}

void ClassValidation::validateLibraryBaseNameString(const QString & name)
{
  if( !LibraryExport::isValidLibraryBaseName(name) ){
    QString msg = tr("'%1' is not a valid library base name")
                  .arg(name);
    throw ClassValidationError(msg);
  }
}

void ClassValidation::validateNamespaceColonSeparatedString(const QString & str)
{
  if( !Namespace::isValidColonSeparatedString(str) ){
    QString msg = tr("'%1' is not a valid namespace in colon separated format")
                  .arg(str);
    throw ClassValidationError(msg);
  }
}

void ClassValidation::validateEditorData(const ClassEditorData & data)
{
  if(data.useLibraryExport){
    validateLibraryBaseNameString(data.libraryBaseName);
  }
}

}} // namespace Mdt{ namespace CppRefactoring{
