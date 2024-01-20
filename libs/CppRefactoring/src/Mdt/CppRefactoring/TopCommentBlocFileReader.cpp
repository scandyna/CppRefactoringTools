// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "TopCommentBlocFileReader.h"
#include <QFile>
#include <QTextStream>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

TopCommentBloc TopCommentBlocFileReader::fromTemplateFile(const QString & path)
{
  const QString cPath = path.trimmed();
  assert( !cPath.isEmpty() );

  QFile file(cPath);

  if( !file.open(QFile::ReadOnly | QFile::Text) ){
    const QString msg = tr("reading file '%1' failed: %2")
                        .arg( path, file.errorString() );
    throw TopCommentBlocFileReadError(msg);
  }

  QTextStream s(&file);

  const QString bloc = s.readAll().trimmed();
  if( bloc.isEmpty() ){
    const QString msg = tr("file '%1' is not valid as top comment bloc because it is empty")
                        .arg(cPath);
    throw TopCommentBlocFileReadError(msg);
  }

  return TopCommentBloc::fromString(bloc);
}

}} // namespace Mdt{ namespace CppRefactoring{
