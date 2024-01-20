// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2024-2024 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_FILE_READER_H
#define MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_FILE_READER_H

#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/TopCommentBlocFileReadError.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief
   */
  class MDT_CPPREFACTORING_EXPORT TopCommentBlocFileReader : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Get a top comment bloc from a template file
     *
     * Given file should only contain the content to put into the top comment bloc.
     *
     * \code
     * TopCommentBloc bloc = TopCommentBlocFileReader::fromTemplateFile("/path/to/myProject/TopCommentBloc.txt");
     * \endcode
     *
     * \exception TopCommentBlocFileReadError
     * \pre \a path must not be empty
     */
    static
    TopCommentBloc fromTemplateFile(const QString & path);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_TOP_COMMENT_BLOC_FILE_READER_H
