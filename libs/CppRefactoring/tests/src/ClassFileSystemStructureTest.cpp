// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/ClassFileSystemStructure.h"
#include "Mdt/CppRefactoring/Class.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("filesPath")
{
  const auto sourcesDir = SourceFilesRootDirectory::fromUncheckedPath("/tmp");
  const auto testSourcesDir = TestSourceFilesDirectory::fromUncheckedPath("/tmp/tests");

  FileSystemStructure fss(sourcesDir, testSourcesDir);
  ClassFileSystemStructure cfss(fss);

  auto className = ClassName::fromString("MyClass");
  auto c = Class::fromName(className);
  c.setTest( Test::fromClassName(className) );

  SECTION("No namespace")
  {
    REQUIRE( cfss.getHeaderFileAbsolutePath(c) == "/tmp/MyClass.h" );
    REQUIRE( cfss.getSourceFileAbsolutePath(c) == "/tmp/MyClass.cpp" );
    REQUIRE( cfss.getTestSourceFileAbsolutePath(c) == "/tmp/tests/MyClassTest.cpp" );
  }

  SECTION("In Mdt::CppRefactoring namespace")
  {
    c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );

    REQUIRE( cfss.getHeaderFileAbsolutePath(c) == "/tmp/Mdt/CppRefactoring/MyClass.h" );
    REQUIRE( cfss.getSourceFileAbsolutePath(c) == "/tmp/Mdt/CppRefactoring/MyClass.cpp" );
    REQUIRE( cfss.getTestSourceFileAbsolutePath(c) == "/tmp/tests/MyClassTest.cpp" );
  }
}
