// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/FileWriter.h"
#include "FileWriterTestCommon.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryFile>
#include <QTemporaryDir>
#include <QDir>

using namespace Mdt::CppRefactoring;


TEST_CASE("open_ExistingFile")
{
  FileWriter writer;
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );

  const QString path = makeFilePath(dir, "file.h");
  const QString originalContent = "ABCD";

  writer.open(path, FileOverwriteBehavior::Fail);
  writer.writeContent(originalContent);
  writer.close();

  REQUIRE_THROWS_AS( writer.open(path, FileOverwriteBehavior::Fail), FileWriteError );
  REQUIRE( !writer.isOpen() );
  REQUIRE( readTextFile(path) == originalContent );
}

TEST_CASE("open_Directory")
{
  FileWriter writer;
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );

  REQUIRE_THROWS_AS( writer.open(dir.path(), FileOverwriteBehavior::Overwrite), FileWriteError );
  REQUIRE( !writer.isOpen() );
}
