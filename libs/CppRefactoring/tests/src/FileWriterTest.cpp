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


TEST_CASE("checkIsExistingFile")
{
  CheckIsExistingFileResponse response;

  SECTION("directory")
  {
    QTemporaryDir dir;
    REQUIRE( dir.isValid() );

    response = FileWriter::checkIsExistingFile( dir.path() );

    REQUIRE( response == CheckIsExistingFileResponse::IsDirectory );
  }

  SECTION("Non existing")
  {
    response = FileWriter::checkIsExistingFile("/some/probably/non/existing/path/I/hope");

    REQUIRE( response == CheckIsExistingFileResponse::NonExisting );
  }

  SECTION("existing file")
  {
    QTemporaryFile file;
    REQUIRE( file.open() );

    response = FileWriter::checkIsExistingFile( file.fileName() );

    REQUIRE( response == CheckIsExistingFileResponse::IsExistingFile );
  }
}

TEST_CASE("open")
{
  FileWriter writer;
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );
  QString path;

  REQUIRE( !writer.isOpen() );

  SECTION("file is in dir and does not exist")
  {
    path = makeFilePath(dir, "file.h");

    writer.open(path, FileOverwriteBehavior::Fail);

    REQUIRE( writer.isOpen() );

    writer.close();

    REQUIRE( !writer.isOpen() );
    REQUIRE( isExistingFile(path) );
  }

  SECTION("file exists and we allow to overwrite")
  {
    path = makeFilePath(dir, "file.h");

    writer.open(path, FileOverwriteBehavior::Fail);
    writer.writeContent("ABCD");
    writer.close();

    writer.open(path, FileOverwriteBehavior::Overwrite);
    writer.close();

    REQUIRE( readTextFile(path).isEmpty() );
  }

  SECTION("create sub directories")
  {
    path = makeFilePath(dir, "src/Mdt/Namespace/file.h");

    writer.open(path, FileOverwriteBehavior::Fail);

    REQUIRE( writer.isOpen() );

    writer.close();

    REQUIRE( !writer.isOpen() );
    REQUIRE( isExistingFile(path) );
  }
}

TEST_CASE("writeContent")
{
  FileWriter writer;
  QTemporaryDir dir;
  REQUIRE( dir.isValid() );

  QString path = makeFilePath(dir, "file.h");

  writer.open(path, FileOverwriteBehavior::Fail);
  writer.writeContent("ABCD");
  writer.close();

  REQUIRE( readTextFile(path) == "ABCD" );
}
