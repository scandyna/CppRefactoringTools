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

#include "Mdt/CppRefactoring/ClassEditorData.h"
#include "Mdt/CppRefactoring/Class.h"
#include <QObject>
#include <QString>
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

  /*! \brief Set the top comment bloc
   */
  void setTopCommentBloc(const QString & bloc);

  /*! \brief Refresh
   *
   * \todo define exceptions
   */
  void refresh() noexcept;

  /*! \brief Get the editor data
   */
  const Mdt::CppRefactoring::ClassEditorData & editorData() const noexcept
  {
    return mEditorData;
  }

 signals:

  /*! \brief Emitted when the class has been updated
   */
  void classUpdated(const Mdt::CppRefactoring::Class & c);

 private:

  Mdt::CppRefactoring::ClassEditorData mEditorData;
  std::optional<Mdt::CppRefactoring::Class> mClass;
};

#endif // #ifndef CREATE_CLASS_EDITOR_H
