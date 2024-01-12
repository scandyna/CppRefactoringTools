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
#include "Mdt/CppRefactoring/ClassValidationError.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "Mdt/CppRefactoring/ClassFileSystemStructure.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class builder
   *
   * \sa ClassValidation
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
     * \exception ClassValidationError
     */
    static
    ClassName makeClassName(const QString & name);

    /*! \brief Make a namespace from given colon separated string
     *
     * \exception ClassValidationError
     */
    static
    Namespace makeNamespaceFromColonSeparatedString(const QString & str);

    /*! \brief Make a class from given editor data
     *
     * \exception ClassValidationError
     */
    static
    Class makeClass(const ClassEditorData & editorData);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_BUILDER_H
