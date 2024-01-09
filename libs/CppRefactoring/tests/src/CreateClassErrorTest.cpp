// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2024-2024 Philippe Steinmann.
**
*****************************************************************************************/
#include "Mdt/CppRefactoring/CreateClass.h"
#include "Mdt/CppRefactoring/SourceFilesRootDirectory.h"
#include "Mdt/CppRefactoring/TestSourceFilesDirectory.h"
#include "CreateClassTestCommon.h"
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include <QTemporaryDir>
#include <QFileInfo>

using namespace Mdt::CppRefactoring;


TEST_CASE("execute")
{
  QTemporaryDir sourcesDir;
  QTemporaryDir testSourcesDir;
  REQUIRE( sourcesDir.isValid() );
  REQUIRE( testSourcesDir.isValid() );

  FileSystemStructure fss = fileSystemStructureFromSourcesAndTestDirs(sourcesDir, testSourcesDir);

  const auto className = ClassName::fromString("MyClass");
  auto c = Class::fromName(className);
  c.setNamespace( Namespace::fromColonSeparatedString("Mdt::CppRefactoring") );
  c.setTest( Test::fromClassName(className) );

  CreateClass useCase;
  CreateClassRequest request{c, fss, CreateClassFileOverwriteBehavior::Fail};

  CreateClassResponse response = useCase.execute(request);
  REQUIRE( response.isSuccess );

  SECTION("attempts to overwrite files")
  {
    REQUIRE_THROWS_AS( response = useCase.execute(request), CreateClassError );
    // REQUIRE( !response.isSuccess );
  }
}
