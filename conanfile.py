from conans import ConanFile, tools
import os

# NOTE: this recipe is only to install dependnecies.
#       to create packages, see packaging subfolder
class MdtCppRefactoringToolsConan(ConanFile):
  name = "MdtCppRefactoringTools"
  #version = "0.1"
  license = "BSD 3-Clause"
  url = "https://gitlab.com/scandyna/cpprefactoringtools"
  description = "Tools to help C++ refactoring."
  settings = "os", "compiler", "build_type", "arch"
  options = {"shared": [True, False]}
  default_options = {"shared": True}
  generators = "CMakeDeps", "CMakeToolchain", "VirtualBuildEnv"

  # See: https://docs.conan.io/en/latest/reference/conanfile/attributes.html#short-paths
  # Should only be enabled if building with MSVC on Windows causes problems
  #short_paths = False

  def requirements(self):
    # Due to a issue using GitLab Conan repository,
    # version ranges are not possible.
    # See https://gitlab.com/gitlab-org/gitlab/-/issues/333638
    self.requires("qt/5.15.6")
    #self.requires("boost/1.72.0")
    self.requires("MdtCMakeConfig/0.0.5@scandyna/testing")

  # When using --profile:build xx and --profile:host xx ,
  # the dependencies declared in build_requires and tool_requires
  # will not generate the required files.
  # see:
  # - https://github.com/conan-io/conan/issues/10272
  # - https://github.com/conan-io/conan/issues/9951
  def build_requirements(self):
    # Due to a issue using GitLab Conan repository,
    # version ranges are not possible.
    # See https://gitlab.com/gitlab-org/gitlab/-/issues/333638
    self.tool_requires("catch2/2.13.9", force_host_context=True)
    self.tool_requires("MdtCMakeModules/0.19.3@scandyna/testing", force_host_context=True)
