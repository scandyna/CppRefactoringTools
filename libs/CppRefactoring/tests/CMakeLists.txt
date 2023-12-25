# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(MdtAddTest)


mdt_add_test(
  NAME NamespaceTest
  TARGET namespaceTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/NamespaceTest.cpp
)

mdt_add_test(
  NAME ClassNameTest
  TARGET classNameTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassNameTest.cpp
)

mdt_add_test(
  NAME HeaderFileNameTest
  TARGET headerFileNameTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/HeaderFileNameTest.cpp
)

mdt_add_test(
  NAME SourceFileNameTest
  TARGET sourceFileNameTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/SourceFileNameTest.cpp
)

mdt_add_test(
  NAME TestSourceFileNameTest
  TARGET testSourceFileNameTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestSourceFileNameTest.cpp
)

mdt_add_test(
  NAME TopCommentBlocTest
  TARGET topCommentBlocTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TopCommentBlocTest.cpp
)

mdt_add_test(
  NAME IncludeGuardTest
  TARGET includeGuardTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/IncludeGuardTest.cpp
)

mdt_add_test(
  NAME HeaderFileContentTest
  TARGET headerFileContentTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/HeaderFileContentTest.cpp
)

mdt_add_test(
  NAME ClassTest
  TARGET classTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassTest.cpp
)

mdt_add_test(
  NAME ClassEditorDataTest
  TARGET classEditorDataTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassEditorDataTest.cpp
)

mdt_add_test(
  NAME ClassBuilderTest
  TARGET classBuilderTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassBuilderTest.cpp
)
