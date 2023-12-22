// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "MainWindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  MainWindow window;

  window.show();

  return app.exec();
}
