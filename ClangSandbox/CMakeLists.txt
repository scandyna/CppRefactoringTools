# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

add_executable(clangsandbox
  main.cpp
)

# Here I'im really not sure how to use libClang
# After searching on the web and looking in the package config files,
# I finally used ChatGPT to sandbox something.
# It seems that LLVM / Clang does not provide proper targets

target_include_directories(clangsandbox
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

target_include_directories(clangsandbox SYSTEM
  PRIVATE
    $<BUILD_INTERFACE:${LLVM_INCLUDE_DIRS}>
)

target_compile_definitions(clangsandbox
  PRIVATE
    ${LLVM_DEFINITIONS}
    CLANG_SANDBOX_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
    PROJECT_BUILD_DIR="${CMAKE_BINARY_DIR}"
)

# TODO: LLVM headers produces a lot of warnings
# Don't know how to suppress them
# target_compile_options(clangsandbox
#   PRIVATE
#     -isystem
# )

# TODO: see
# https://github.com/llvm/llvm-project/blob/main/clang/tools/clang-check/CMakeLists.txt
# https://clang.llvm.org/docs/LibASTMatchersTutorial.html
target_link_libraries(clangsandbox
  PRIVATE
    # Clang::libclang
    # LLVM::libTooling
    # LLVMSupport clangTooling
    clangTooling
    Qt5::Core
)
