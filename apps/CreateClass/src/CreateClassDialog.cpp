// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtCppRefactoringTools
 ** Tools to help C++ refactoring.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "CreateClassDialog.h"

CreateClassDialog::CreateClassDialog(QWidget* parent) noexcept
 : QDialog(parent)
{
  mUi.setupUi(this);
}
