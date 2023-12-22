// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef CREATE_CLASS_DIALOG_H
#define CREATE_CLASS_DIALOG_H

#include "ui_CreateClassDialog.h"
#include <QDialog>

/*! \brief Dialog to create a class
 */
class CreateClassDialog : public QDialog
{
  Q_OBJECT

 public:

  /*! \brief Constructor
   */
  explicit
  CreateClassDialog(QWidget *parent = nullptr) noexcept;

 private:

  Ui::CreateClassDialog mUi;
};

#endif // #ifndef CREATE_CLASS_DIALOG_H
