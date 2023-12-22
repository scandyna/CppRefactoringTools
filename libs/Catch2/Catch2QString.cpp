// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
 **
 ** MdtRailwayCableList
 ** Tool to edit cable lists specific to railway vehicles.
 **
 ** Copyright (C) 2023-2023 Philippe Steinmann.
 **
 *****************************************************************************************/
#include "Catch2QString.h"
#include <QByteArray>

std::ostream & operator <<(std::ostream & os, const QString & str)
{
  os << str.toLocal8Bit().toStdString();

  return os;
}
