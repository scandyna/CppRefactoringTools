# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

add_library(CreateClass STATIC
  CreateClassEditor.cpp
)
add_library(Mdt::CreateClass ALIAS CreateClass)

if(BUILD_USE_IPO_LTO)
  set_target_properties(CreateClass
    PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE
  )
endif()

set_target_properties(CreateClass
  PROPERTIES POSITION_INDEPENDENT_CODE TRUE
)

target_compile_definitions(CreateClass
  PRIVATE
    QT_NO_CAST_DEFINITIONS QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_BYTEARRAY
)

target_include_directories(CreateClass
  PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_link_libraries(CreateClass
  PUBLIC
    Mdt::CppRefactoring
#     Mdt::Numeric
#     Mdt::ItemModel
)


add_executable(mdtcppcreateclass
  MainWindow.cpp
  main.cpp
)

target_compile_definitions(mdtcppcreateclass
  PRIVATE
    QT_NO_CAST_DEFINITIONS QT_NO_CAST_FROM_ASCII QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_BYTEARRAY
)


target_link_libraries(mdtcppcreateclass
  PRIVATE
    Mdt::CreateClass
    Qt5::Widgets
)

if(BUILD_USE_IPO_LTO)
  set_target_properties(mdtcppcreateclass
    PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE
  )
endif()

target_include_directories(mdtcppcreateclass
  PRIVATE
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
