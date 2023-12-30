// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_CLASS_H
#define MDT_CPP_REFACTORING_CLASS_H

#include "Mdt/CppRefactoring/ClassName.h"
#include "Mdt/CppRefactoring/Namespace.h"
#include "Mdt/CppRefactoring/HeaderFileName.h"
#include "Mdt/CppRefactoring/SourceFileName.h"
#include "Mdt/CppRefactoring/TestSourceFileName.h"
#include "Mdt/CppRefactoring/TopCommentBloc.h"
#include "Mdt/CppRefactoring/HeaderFileContent.h"
#include "Mdt/CppRefactoring/LibraryExport.h"
#include "Mdt/CppRefactoring/SourceFileContent.h"
#include "Mdt/CppRefactoring/TestSourceFileContent.h"
#include "Mdt/CppRefactoring/Test.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <optional>
#include <cassert>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Class holds attributes to create or rename a class
   */
  class MDT_CPPREFACTORING_EXPORT Class
  {
   public:

    Class() = delete;

    /*! \brief Get the name of this class
     */
    const ClassName & name() const noexcept
    {
      return mName;
    }

    /*! \brief Check if this class is in a namespace
     */
    bool isInNamespace() const noexcept
    {
      return mNamespace.has_value();
    }

    /*! \brief Put this class into a namespace
     */
    void setNamespace(const Namespace & ns) noexcept;

    /*! \brief Get the namespace this class is in
     *
     * \pre this class must be in a namespace
     * \sa isInNamespace()
     */
    const Namespace & ns() const noexcept;

    /*! \brief Get the header file name
     */
    const HeaderFileName & headerFileName() const noexcept
    {
      return mHeaderFileName;
    }

    /*! \brief Get the source file name
     */
    const SourceFileName & sourceFileName() const noexcept
    {
      return mSourceFileName;
    }

    /*! \brief Set a test
     */
    void setTest(const Test & test) noexcept;

    /*! \brief Get the test source file name
     *
     * \pre this class must have a test
     * \sa hasTest()
     */
    const TestSourceFileName & testSourceFileName() const noexcept
    {
      assert( hasTest() );

      return mTest->testSourceFileName();
    }

    /*! \brief Set the top comment bloc
     */
    void setTopCommentBloc(const TopCommentBloc & bloc) noexcept;

    /*! \brief Set the library export
     */
    void setLibraryExport(const LibraryExport & libraryExport) noexcept;

    /*! \brief Get the header file content
     */
    const HeaderFileContent & headerFileContent() const noexcept
    {
      return mHeaderFileContent;
    }

    /*! \brief Get the source file content
     */
    const SourceFileContent & sourceFileContent() const noexcept
    {
      return mSourceFileContent;
    }

    /*! \brief Check if a test used
     */
    bool hasTest() const noexcept
    {
      return mTest.has_value();
    }

    /*! \brief Get the test source file content
     *
     * \pre this class must have a test
     * \sa hasTest()
     */
    const TestSourceFileContent & testSourceFileContent() const noexcept
    {
      assert( hasTest() );

      return mTest->testSourceFileContent();
    }

    /*! \brief Create a class from given name
     *
     * \pre \a name must be valid
     * \sa isValidName()
     */
    static
    Class fromName(const ClassName & name) noexcept;

   private:

    Class(const ClassName & name) noexcept;

    ClassName mName;
    std::optional<Namespace> mNamespace;
    std::optional<TopCommentBloc> mTopCommentBloc;
    HeaderFileName mHeaderFileName;
    SourceFileName mSourceFileName;
    HeaderFileContent mHeaderFileContent;
    SourceFileContent mSourceFileContent;
    std::optional<Test> mTest;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // MDT_CPP_REFACTORING_CLASS_H
