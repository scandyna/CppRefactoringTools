// SPDX-License-Identifier: LGPL-3.0-or-later
/****************************************************************************************
**
** MdtCppRefactoringTools
** Tools to help C++ refactoring.
**
** Copyright (C) 2023-2023 Philippe Steinmann.
**
*****************************************************************************************/
#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "Mdt/CppRefactoring/IncludeStatementBloc.h"
#include <QString>

using namespace Mdt::CppRefactoring;


TEST_CASE("addAStatement")
{
  IncludeStatementBloc bloc;
  auto stm = IncludeStatement::fromFileBaseName("MyClass");

  REQUIRE( bloc.isEmpty() );

  bloc.appendStatement(stm);

  REQUIRE( !bloc.isEmpty() );
}

TEST_CASE("updateOrAppendStatement")
{
  IncludeStatementBloc bloc;
  auto stm = IncludeStatement::fromFileBaseName("MyClass");

  bloc.updateOrAppendStatement(stm);

  REQUIRE( bloc.toString() == "#include \"MyClass.h\"" );

  stm.setSystemInclude(true);
  bloc.updateOrAppendStatement(stm);

  REQUIRE( bloc.toString() == "#include <MyClass.h>" );
}

TEST_CASE("updateOrAppendStatementByFileName")
{
  IncludeStatementBloc bloc;
  auto stm = IncludeStatement::fromFileBaseName("MyClass");

  bloc.updateOrAppendStatementByFileName(stm);

  REQUIRE( bloc.toString() == "#include \"MyClass.h\"" );

  stm = IncludeStatement::from_q_char_sequence("Mdt/MyClass.h");
  bloc.updateOrAppendStatementByFileName(stm);

  REQUIRE( bloc.toString() == "#include \"Mdt/MyClass.h\"" );

}

TEST_CASE("toString")
{
  IncludeStatementBloc bloc;
  QString expectedResult;

  SECTION("empty bloc")
  {
    REQUIRE( bloc.toString().isEmpty() );
  }

  SECTION("1 file")
  {
    bloc.appendStatement( IncludeStatement::fromFileBaseName("MyClass") );

    expectedResult =
      "#include \"MyClass.h\"";

    REQUIRE( bloc.toString() == expectedResult );
  }

  SECTION("2 files")
  {
    bloc.appendStatement( IncludeStatement::fromFileBaseName("Model") );
    bloc.appendStatement( IncludeStatement::fromFileBaseName("Widget") );

    expectedResult =
      "#include \"Model.h\"\n"
      "#include \"Widget.h\"";

    REQUIRE( bloc.toString() == expectedResult );
  }

  SECTION("3 files")
  {
    bloc.appendStatement( IncludeStatement::fromFileBaseName("Model") );
    bloc.appendStatement( IncludeStatement::fromFileBaseName("Widget") );
    bloc.appendStatement( IncludeStatement::fromFileBaseName("Dialog") );

    expectedResult =
      "#include \"Model.h\"\n"
      "#include \"Widget.h\"\n"
      "#include \"Dialog.h\"";

    REQUIRE( bloc.toString() == expectedResult );
  }
}
