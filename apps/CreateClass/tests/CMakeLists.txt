# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(MdtAddTest)


mdt_add_test(
  NAME CL_EditorViewModelTest
  TARGET cl_EditorViewModelTest
  DEPENDENCIES Mdt::CreateClass Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/EditorViewModelTest.cpp
)

mdt_add_test(
  NAME CL_CreateClassEditorTest
  TARGET cl_CreateClassEditorTest
  DEPENDENCIES Mdt::CreateClass Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/CreateClassEditorTest.cpp
)

mdt_add_test(
  NAME CL_CreateClassEditorErrorTest
  TARGET cl_CreateClassEditorErrorTest
  DEPENDENCIES Mdt::CreateClass Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/CreateClassEditorErrorTest.cpp
)
