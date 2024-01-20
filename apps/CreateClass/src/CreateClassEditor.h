// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef CREATE_CLASS_EDITOR_H
#define CREATE_CLASS_EDITOR_H

#include "EditorViewModel.h"
#include "Mdt/CppRefactoring/ClassEditorData.h"
#include "Mdt/CppRefactoring/Class.h"
#include "Mdt/CppRefactoring/ClassValidationError.h"
#include "Mdt/CppRefactoring/TestFrameworkType.h"
#include "Mdt/CppRefactoring/FileSystemEditorData.h"
#include "Mdt/CppRefactoring/FileSystemStructure.h"
#include "Mdt/CppRefactoring/FileSystemValidationError.h"

#include "Mdt/CppRefactoring/CreateClass.h"
/// #include "Mdt/CppRefactoring/CreateClassRequest.h"
/// #include "Mdt/CppRefactoring/CreateClassResponse.h"

#include <QObject>
#include <QString>
#include <QStringList>
#include <optional>

/*! \brief Editor to create a class
 */
class CreateClassEditor : public QObject
{
  Q_OBJECT

 public:

  /*! \brief Constructor
   */
  explicit
  CreateClassEditor(QObject *parent = nullptr) noexcept;

  /*! \brief Check if this editor has a valid class
   */
  bool hasValidClass() const noexcept
  {
    return mClass.has_value();
  }

  /*! \brief Get the valid class
   *
   * \pre This editor must have a valid class
   * \sa hasValidClass()
   */
  const Mdt::CppRefactoring::Class & validClass() const noexcept;

 public slots:

  /*! \brief Set the class name
   *
   * \todo define exceptions
   */
  void setClassName(const QString & name);

  /*! \brief Set the namespace
   */
  void setNamespace(const QString & ns);

  /*! \brief Set the path to the top comment bloc template file
   */
  void setTopCommentBlocTemplateFilePath(const QString & path);

  /*! \brief Set use library export
   */
  void setUseLibraryExport(bool use) noexcept;

  /*! \brief Set the library base name
   */
  void setLibraryBaseName(const QString & name) noexcept;

  /*! \brief Set the library base name from namespace
   *
   * \exception ClassValidationError
   */
  void setLibraryBaseNameFromNamespace();

  /*! \brief Set the test framework to use
   */
  void setTestFrameworkType(Mdt::CppRefactoring::TestFrameworkType type) noexcept;

  /*! \brief Set the test source file additional headers
   */
  void setTestSourceFileAdditionalIncludes(const QStringList & headers) noexcept;

  /*! \brief Set the test source file additional system headers
   */
  void setTestSourceFileAdditionalSystemIncludes(const QStringList & headers) noexcept;

  /*! \brief Set the absolute path to the source files directory root
   */
  void setSourceFilesRootDirectoryAbsolutePath(const QString & path) noexcept;

  /*! \brief Set the absolute path to the test source files directory
   */
  void setTestSourceFilesDirectoryAbsolutePath(const QString & path) noexcept;

  /*! \brief Refresh
   *
   * \exception ClassValidationError
   * \exception FileSystemValidationError
   */
  void refresh();

  /*! \brief Create the class
   *
   * \exception ClassValidationError
   * \exception FileSystemValidationError
   */
  Mdt::CppRefactoring::CreateClassResponse createClass(Mdt::CppRefactoring::CreateClassFileOverwriteBehavior overwriteBehavior);

  /*! \brief Get the editor data
   */
  const Mdt::CppRefactoring::ClassEditorData & editorData() const noexcept
  {
    return mEditorData;
  }

  /*! \brief Get the file system editor data
   */
  const Mdt::CppRefactoring::FileSystemEditorData & fileSystemEditorData() const noexcept
  {
    return mFileSystemEditorData;
  }

 signals:

  /*! \brief Emitted when the class has been updated
   */
  void classUpdated(const Mdt::CppRefactoring::Class & c);

  void libraryBaseNameGenerated(const QString & name);

  /*! \brief Emitted when the file system structure has been updated
   */
  void fileSystemStructureUpdated(const EditorViewModel & model);

 private:

  Mdt::CppRefactoring::ClassEditorData mEditorData;
  std::optional<Mdt::CppRefactoring::Class> mClass;
  Mdt::CppRefactoring::FileSystemEditorData mFileSystemEditorData;
  std::optional<Mdt::CppRefactoring::FileSystemStructure> mFileSystemStructure;
};

#endif // #ifndef CREATE_CLASS_EDITOR_H
