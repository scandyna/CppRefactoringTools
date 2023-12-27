// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_DECLARATION_H
#define MDT_CPP_REFACTORING_CLASS_DECLARATION_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/LibraryExport.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class declaration
   */
  class MDT_CPPREFACTORING_EXPORT ClassDeclaration
  {
   public:

    ClassDeclaration() = delete;

    /*! \brief Construct class declaration from given class name
     */
    ClassDeclaration(const ClassName & name) noexcept
     : mClassName(name)
    {
    }

    /*! \brief Set the indentation char count
     *
     * \pre \a charCount must be in valid range (0 <= \a charCount <= 20)
     */
    void setIndentationCharCount(int charCount) noexcept;

    /*! \brief Set the library export
     */
    void setLibraryExport(const LibraryExport & libraryExport) noexcept;

    /*! \brief Get the string representation of this declaration
     */
    QString toString() const noexcept;

   private:

    QString getIndentationString() const noexcept;
    QString getLibraryExportMacroIf() const noexcept;

    ClassName mClassName;
    int mIndentationCharCount = 0;
    std::optional<LibraryExport> mLibraryExport;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_CLASS_DECLARATION_H
