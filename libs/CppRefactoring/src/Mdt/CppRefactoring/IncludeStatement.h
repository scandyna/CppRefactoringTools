// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H
#define MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H

#include "Mdt/CppRefactoring/Namespace.h"
#include "Mdt/CppRefactoring/DirectoryRelativePath.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <QChar>
#include <QFileInfo>
#include <optional>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Reprents an include Include
   */
  class MDT_CPPREFACTORING_EXPORT IncludeStatement
  {
   public:

    IncludeStatement() = delete;

    /*! \brief Set this statement a system include
     */
    void setSystemInclude(bool s) noexcept;

    /*! \brief Check if this statement represents a system include
     */
    bool isSystemInclude() const noexcept
    {
      return mIsSystemInclude;
    }

    /*! \brief Get the file name
     */
    QString fileName() const noexcept
    {
      return mFileName;
    }

    /*! \brief Get the file relative path
     */
    QString fileRelativePath() const noexcept;

    /*! \brief Get the string representation of this statement
     */
    QString toString() const noexcept;

    /*! \brief Get an include statement from given file base name
     *
     * \note the \a .h file extension is assumed
     * \pre \a name must not be empty
     */
    static
    IncludeStatement fromFileBaseName(const QString & name) noexcept;

    /*! \brief Get an include statement from given namespace and file base name
     *
     * \note the \a .h file extension is assumed
     * \pre \a name must not be empty
     */
    static
    IncludeStatement fromNamespaceAndFileBaseName(const Namespace & ns, const QString & name) noexcept;

    /*! \brief Get an include statement from given q-char-sequence
     *
     * The \a sequence is the complete relative path to the file to include:
     * \code
     * SomeFile.h
     * Ns/OtherFile.hpp
     * \endcode
     *
     * \pre \a sequence must not be empty
     * \sa https://en.cppreference.com/w/cpp/preprocessor/include
     */
    static
    IncludeStatement from_q_char_sequence(const QString & sequence) noexcept;

    /*! \brief Get a system include statement from given h-char-sequence
     *
     * The \a sequence is the complete relative path to the file to include:
     * \code
     * SomeFile.h
     * boost/algorithm/hex.hpp
     * QString
     * cassert
     * \endcode
     *
     * \pre \a sequence must not be empty
     * \sa https://en.cppreference.com/w/cpp/preprocessor/include
     */
    static
    IncludeStatement systemIncludeFrom_h_char_sequence(const QString & sequence) noexcept;

    /*! \brief
     *
     * \todo define and implement + What about Qt/QtTest ?
     */
    static
    IncludeStatement fromQtClassName(const QString & name) noexcept;

    /*! \brief
     *
     * \todo define and implement
     */
    static
    IncludeStatement fromStdlibHeaderName(const QString & name) noexcept;

   private:

    static
    IncludeStatement fromFileInfo(const QFileInfo & fi) noexcept;

    IncludeStatement(const QString & fileName) noexcept;
    IncludeStatement(const QString & fileName, const DirectoryRelativePath & path) noexcept;

    QChar getBeginQuote() const noexcept;
    QChar getEndQuote() const noexcept;
    QString getDirectoryRelativePathStringIf() const noexcept;

    bool mIsSystemInclude = false;
    QString mFileName;
    std::optional<DirectoryRelativePath> mDirectoryRelativePath;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_INCLUDE_STATEMENT_H
