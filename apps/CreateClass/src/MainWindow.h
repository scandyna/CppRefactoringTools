// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "ui_MainWindow.h"
#include <QMainWindow>

/*! \brief Main window
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:

  /*! \brief Constructor
   */
  explicit
  MainWindow(QWidget *parent = nullptr) noexcept;

 private:

  Ui::MainWindow mUi;
};

#endif // #ifndef MAIN_WINDOW_H