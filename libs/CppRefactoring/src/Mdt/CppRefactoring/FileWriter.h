// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#ifndef MDT_CPP_REFACTORING_FILE_WRITER_H
#define MDT_CPP_REFACTORING_FILE_WRITER_H

#include "Mdt/CppRefactoring/FileOverwriteBehavior.h"
#include "Mdt/CppRefactoring/FileWriteError.h"
#include "mdt_cpprefactoring_export.h"
#include <QObject>
#include <QString>
#include <QFileInfo>
#include <QFile>

namespace Mdt{ namespace CppRefactoring{

  /*! \brief Response after checking about an existing file
   *
   * \sa FileWriter::checkIsExistingFile()
   */
  enum class CheckIsExistingFileResponse
  {
    NonExisting,
    IsDirectory,
    IsExistingFile
  };

  /*! \brief File writer
   */
  class MDT_CPPREFACTORING_EXPORT FileWriter : public QObject
  {
    Q_OBJECT

   public:

    /*! \brief Constructor
     */
    explicit
    FileWriter(QObject *parent = nullptr) noexcept;

    /*! \brief Open a file
     *
     * \exception FileWriteError
     * \pre \a path must not be empty
     */
    void open(const QString & path, FileOverwriteBehavior overwriteBehavior);

    /*! \brief Check if this file is open
     */
    bool isOpen() const noexcept
    {
      return mFile.isOpen();
    }

    /*! \brief Write given content to the file
     *
     * \exception FileWriteError
     * \pre this file must be open
     * \sa isOpen()
     */
    void writeContent(const QString & content);

    /*! \brief Close the file
     */
    void close();

    /*! \brief Check if given path refers to an existing file
     *
     * \pre \a path must not be empty
     */
    static
    CheckIsExistingFileResponse checkIsExistingFile(const QString & path) noexcept;

    /*! \brief Write a file
     *
     * \todo define and implement exceptions
     */
    // void writeFile(const QString & path, /*content,*/ FileOverwriteBehavior overwriteBehavior);

   private:

    static
    CheckIsExistingFileResponse checkIsExistingFileImpl(const QFileInfo & fi) noexcept;

    static
    void makePath(const QFileInfo & fi);

    QFile mFile;
  };

}} // namespace Mdt{ namespace CppRefactoring{

#endif // #ifndef MDT_CPP_REFACTORING_FILE_WRITER_H
