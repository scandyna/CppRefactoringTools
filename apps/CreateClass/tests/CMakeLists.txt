# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

include(MdtAddTest)


mdt_add_test(
  NAME CL_EditorViewModelTest
  TARGET cle_EditorViewModelTest
  DEPENDENCIES Mdt::CreateClass Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/EditorViewModelTest.cpp
)

mdt_add_test(
  NAME CL_CreateClassEditorTest
  TARGET cle_CreateClassEditorTest
  DEPENDENCIES Mdt::CreateClass Mdt::Catch2Main Mdt::Catch2Qt
  SOURCE_FILES
    src/CreateClassEditorTest.cpp
)
