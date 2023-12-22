# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

# add_subdirectory(CableList)

if(BUILD_TESTS OR BUILD_BENCHMARKS)
  add_subdirectory(Catch2)
endif()
