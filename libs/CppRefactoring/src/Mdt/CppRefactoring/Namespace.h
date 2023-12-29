// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_NAMESPACE_H
#define MDT_CPP_REFACTORING_NAMESPACE_H

#include "Mdt/CppRefactoring/DirectoryRelativePath.h"
#include "mdt_cpprefactoring_export.h"
#include <QString>
#include <QLatin1String>
#include <QStringList>
#include <QLatin1Char>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Represents a namespace
   *
   * \todo \exception NamespaceSyntaxError in NamespaceValidation
   */
  class MDT_CPPREFACTORING_EXPORT Namespace
  {
   public:

    Namespace() = delete;

    /*! \brief Get a list of parts representation of this namespace
     *
     * Each item will contain a part of the namespace.
     * Example:
     * \code
     * Mdt::CppRefactoring -> {Mdt,CppRefactoring}
     * \endcode
     */
    const QStringList & partList() const noexcept
    {
      return mPartList;
    }

    /*! \brief Get a colon separated string representation of this namespace
     */
    QString toColonSeparatedString() const noexcept
    {
      return mPartList.join( QLatin1String("::") );
    }

    /*! \brief Get the namespace begin string
     */
    QString toBeginString() const noexcept;

    /*! \brief Get the namespace end string
     */
    QString toEndString() const noexcept;

    /*! \brief Get the using namespace string
     */
    QString toUsingString() const noexcept;

    /*! \brief Get a relative directory path representation of this namespace
     *
     * \todo has not realy its place here
     */
    DirectoryRelativePath toDirectoryRelativePath() const noexcept
    {
      return DirectoryRelativePath::fromString( mPartList.join( QLatin1Char('/') ) );
    }

    /*! \brief Get a relative directory path representation of this namespace
     *
     * \todo has not realy its place here
     */
    QString toDirectoryRelativePathString() const noexcept
    {
      return toDirectoryRelativePath().toString();
    }

    /*! \brief Check if given char is valid for a namespace
     *
     * \todo to be defined
     */

    /*! \brief Check if given string is a valid colon separated namespace
     */
    static
    bool isValidColonSeparatedString(const QString & str) noexcept;

    /*! \brief Get a namespace from a colon separated string
     *
     * \pre \a str must be valid
     * \sa isValidColonSeparatedString()
     */
    static
    Namespace fromColonSeparatedString(const QString & str) noexcept;

   private:

    Namespace(const QStringList & partList) noexcept;

    QStringList mPartList;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // MDT_CPP_REFACTORING_NAMESPACE_H
