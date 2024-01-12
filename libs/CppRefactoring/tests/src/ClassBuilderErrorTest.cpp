#include "catch2/catch.hpp"
#include "Catch2QString.h"
#include "Mdt/CppRefactoring/ClassBuilder.h"

using namespace Mdt::CppRefactoring;


TEST_CASE("makeClassName")
{
  SECTION("empty string")
  {
    REQUIRE_THROWS_AS( ClassBuilder::makeClassName(""), ClassValidationError );
  }

  SECTION("only spaces")
  {
    REQUIRE_THROWS_AS( ClassBuilder::makeClassName("   "), ClassValidationError );
  }
}

TEST_CASE("makeNamespaceFromColonSeparatedString")
{
  SECTION("empty string")
  {
    REQUIRE_THROWS_AS( ClassBuilder::makeNamespaceFromColonSeparatedString(""), ClassValidationError );
  }
}

TEST_CASE("makeClass")
{
  ClassEditorData data;

  SECTION("tell to use library export but not library name given")
  {
    data.className = "MyClass";
    data.useLibraryExport = true;

    REQUIRE_THROWS_AS( ClassBuilder::makeClass(data), ClassValidationError );
  }
}
