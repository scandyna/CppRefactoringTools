// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_BUILDER_H
#define MDT_CPP_REFACTORING_CLASS_BUILDER_H

#include "Mdt/CppRefactoring/Class.h"
#include "Mdt/CppRefactoring/ClassEditorData.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class builder
   */
  class MDT_CPPREFACTORING_EXPORT ClassBuilder : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Constructor
     */
    explicit
    ClassBuilder(QObject *parent = nullptr) noexcept;

    /*! \brief Make a class name
     *
     * \todo define exceptions
     */
    static
    ClassName makeClassName(const QString & name);

    /*! \brief Make a class from given editor data
     *
     * \todo define exceptions
     */
    static
    Class makeClass(const ClassEditorData & editorData);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_BUILDER_H
