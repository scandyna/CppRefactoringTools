# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(GenerateExportHeader)
include(MdtInstallLibrary)

add_library(Mdt_CppRefactoring
  Mdt/CppRefactoring/QRuntimeError.cpp
  Mdt/CppRefactoring/Algorithm.cpp
  Mdt/CppRefactoring/DirectoryRelativePath.cpp
  Mdt/CppRefactoring/ClassEditorData.cpp
  Mdt/CppRefactoring/Namespace.cpp
  Mdt/CppRefactoring/ClassName.cpp
  Mdt/CppRefactoring/ClassDeclaration.cpp
  Mdt/CppRefactoring/HeaderFileName.cpp
  Mdt/CppRefactoring/SourceFileName.cpp
  Mdt/CppRefactoring/TestSourceFileName.cpp
  Mdt/CppRefactoring/TopCommentBloc.cpp
  Mdt/CppRefactoring/TopCommentBlocFileReader.cpp
  Mdt/CppRefactoring/TopCommentBlocFileReadError.cpp
  Mdt/CppRefactoring/IncludeGuard.cpp
  Mdt/CppRefactoring/LibraryExport.cpp
  Mdt/CppRefactoring/IncludeStatement.cpp
  Mdt/CppRefactoring/IncludeStatementBloc.cpp
  Mdt/CppRefactoring/HeaderFileContent.cpp
  Mdt/CppRefactoring/SourceFileContent.cpp
  Mdt/CppRefactoring/TestFrameworkType.cpp
  Mdt/CppRefactoring/TestFrameworkEditorData.cpp
  Mdt/CppRefactoring/TestName.cpp
  Mdt/CppRefactoring/Test.cpp
  Mdt/CppRefactoring/TestBuilder.cpp
  Mdt/CppRefactoring/TestSourceFileContent.cpp
  Mdt/CppRefactoring/Class.cpp
  Mdt/CppRefactoring/ClassValidationError.cpp
  Mdt/CppRefactoring/ClassValidation.cpp
  Mdt/CppRefactoring/ClassBuilder.cpp
  Mdt/CppRefactoring/FileSystemHelpers.cpp
  Mdt/CppRefactoring/SourceFilesRootDirectory.cpp
  Mdt/CppRefactoring/TestSourceFilesDirectory.cpp
  Mdt/CppRefactoring/FileSystemEditorData.cpp
  Mdt/CppRefactoring/FileSystemStructure.cpp
  Mdt/CppRefactoring/FileSystemValidationError.cpp
  Mdt/CppRefactoring/FileSystemValidation.cpp
  Mdt/CppRefactoring/FileSystemBuilder.cpp
  Mdt/CppRefactoring/ClassFileSystemStructure.cpp
  Mdt/CppRefactoring/FileOverwriteBehavior.cpp
  Mdt/CppRefactoring/FileWriteError.cpp
  Mdt/CppRefactoring/FileWriter.cpp
  Mdt/CppRefactoring/CreateClass.cpp
)
add_library(Mdt::CppRefactoring ALIAS Mdt_CppRefactoring)

if(BUILD_USE_IPO_LTO)
  set_target_properties(Mdt_CppRefactoring
    PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE
  )
endif()

target_compile_definitions(Mdt_CppRefactoring
  PRIVATE
    QT_NO_CAST_DEFINITIONS QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_BYTEARRAY
)

target_include_directories(Mdt_CppRefactoring
  PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_link_libraries(Mdt_CppRefactoring
  PUBLIC
    Qt5::Core
    # Mdt::Numeric
#   PRIVATE
#     Boost::boost
)

generate_export_header(Mdt_CppRefactoring)

mdt_install_library(
  TARGET Mdt_CppRefactoring
  RUNTIME_DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY_DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE_DESTINATION ${CMAKE_INSTALL_LIBDIR}
  INCLUDES_DIRECTORY .
  INCLUDES_FILE_WITHOUT_EXTENSION
  ADDITIONAL_INCLUDES_FILES "${CMAKE_CURRENT_BINARY_DIR}/mdt_cpprefactoring_export.h"
  INCLUDES_DESTINATION ${MDT_INSTALL_INCLUDEDIR}
  EXPORT_NAME CppRefactoring
  EXPORT_NAMESPACE Mdt${PROJECT_VERSION_MAJOR}::
  INSTALL_NAMESPACE ${MDT_INSTALL_PACKAGE_NAME}
  FIND_PACKAGE_PATHS ..
  INSTALL_IS_UNIX_SYSTEM_WIDE ${MDT_INSTALL_IS_UNIX_SYSTEM_WIDE}
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  VERSION_COMPATIBILITY ExactVersion
  RUNTIME_COMPONENT Mdt_RailwayCableList_Runtime
  DEVELOPMENT_COMPONENT Mdt_RailwayCableList_Dev
)
