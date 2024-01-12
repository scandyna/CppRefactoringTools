// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_VALIDATION_H
#define MDT_CPP_REFACTORING_CLASS_VALIDATION_H

#include "Mdt/CppRefactoring/ClassValidationError.h"
#include "Mdt/CppRefactoring/ClassEditorData.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class validation
   */
  class MDT_CPPREFACTORING_EXPORT ClassValidation : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Constructor
     */
    explicit
    ClassValidation(QObject *parent = nullptr) noexcept;

    /*! \brief Validate given string for a class name
     *
     * \exception ClassValidationError
     * \sa ClassName
     */
    static
    void validateClassNameString(const QString & name);

    /*! \brief Validate given string for a library base name usable for an export
     *
     * \exception ClassValidationError
     * \sa LibraryExport::isValidLibraryBaseName()
     */
    static
    void validateLibraryBaseNameString(const QString & name);

    /*! \brief Validate given string for a namespace in colon separated format
     *
     * \exception ClassValidationError
     * \sa Namespace::isValidColonSeparatedString()
     */
    static
    void validateNamespaceColonSeparatedString(const QString & str);

    /*! \brief Validate given class editor data
     *
     * \exception ClassValidationError
     */
    static
    void validateEditorData(const ClassEditorData & data);
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_VALIDATION_H
