// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef TOP_COMMENT_BLOC_FILE_READER_TEST_COMMON_H
#define TOP_COMMENT_BLOC_FILE_READER_TEST_COMMON_H

#include <QTemporaryFile>
#include <QTextStream>
#include <QString>

void writeTopCommentBlocFile(QTemporaryFile & file, const QString & bloc)
{
  assert( file.isOpen() );

  QTextStream s(&file);
  s << bloc;

  file.close();
}


#endif // #ifndef TOP_COMMENT_BLOC_FILE_READER_TEST_COMMON_H
