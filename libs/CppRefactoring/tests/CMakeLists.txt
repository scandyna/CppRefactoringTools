# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(MdtAddTest)


mdt_add_test(
  NAME AlgorithmTest
  TARGET algorithmTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/AlgorithmTest.cpp
)

mdt_add_test(
  NAME DirectoryRelativePathTest
  TARGET directoryRelativePathTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/DirectoryRelativePathTest.cpp
)

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
  NAME ClassDeclarationTest
  TARGET classDeclarationTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassDeclarationTest.cpp
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
  NAME TestFrameworkEditorDataTest
  TARGET testFrameworkEditorDataTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestFrameworkEditorDataTest.cpp
)

mdt_add_test(
  NAME TestNameTest
  TARGET testNameTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestNameTest.cpp
)

mdt_add_test(
  NAME TestTest
  TARGET testTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestTest.cpp
)

mdt_add_test(
  NAME TestBuilderTest
  TARGET testBuilderTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestBuilderTest.cpp
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
  NAME LibraryExportTest
  TARGET libraryExportTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/LibraryExportTest.cpp
)

mdt_add_test(
  NAME IncludeStatementTest
  TARGET includeStatementTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/IncludeStatementTest.cpp
)

mdt_add_test(
  NAME IncludeStatementBlocTest
  TARGET includeStatementBlocTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/IncludeStatementBlocTest.cpp
)

mdt_add_test(
  NAME HeaderFileContentTest
  TARGET headerFileContentTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/HeaderFileContentTest.cpp
)

mdt_add_test(
  NAME SourceFileContentTest
  TARGET sourceFileContentTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/SourceFileContentTest.cpp
)

mdt_add_test(
  NAME TestSourceFileContentTest
  TARGET testSourceFileContentTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestSourceFileContentTest.cpp
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

mdt_add_test(
  NAME FileSystemHelpersTest
  TARGET fileSystemHelpersTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/FileSystemHelpersTest.cpp
)

mdt_add_test(
  NAME SourceFilesRootDirectoryTest
  TARGET sourceFilesRootDirectoryTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/SourceFilesRootDirectoryTest.cpp
)

mdt_add_test(
  NAME TestSourceFilesDirectoryTest
  TARGET testSourceFilesDirectoryTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/TestSourceFilesDirectoryTest.cpp
)

mdt_add_test(
  NAME FileSystemStructureTest
  TARGET fileSystemStructureTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/FileSystemStructureTest.cpp
)

mdt_add_test(
  NAME FileSystemEditorDataTest
  TARGET fileSystemEditorDataTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/FileSystemEditorDataTest.cpp
)

mdt_add_test(
  NAME FileSystemBuilderTest
  TARGET fileSystemBuilderTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/FileSystemBuilderTest.cpp
)

mdt_add_test(
  NAME ClassFileSystemStructureTest
  TARGET classFileSystemStructureTest
  DEPENDENCIES Mdt::CppRefactoring Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/ClassFileSystemStructureTest.cpp
)
