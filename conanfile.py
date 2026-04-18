from conan import ConanFile
from conan.tools.env import VirtualBuildEnv
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake


# NOTE: this recipe is only to install dependnecies.
#       to create packages, see packaging subfolder
class MdtCppRefactoringToolsConan(ConanFile):
  name = "mdtcpprefactoringtools"
  #version = "0.1"
  license = "BSD 3-Clause"
  url = "https://gitlab.com/scandyna/cpprefactoringtools"
  description = "Tools to help C++ refactoring."
  settings = "os", "compiler", "build_type", "arch"
  options = {"shared": [True, False]}
  default_options = {"shared": True}
  generators = "CMakeDeps", "VirtualBuildEnv"

  # See: https://docs.conan.io/en/latest/reference/conanfile/attributes.html#short-paths
  # Should only be enabled if building with MSVC on Windows causes problems
  #short_paths = False

  def requirements(self):
    self.requires("qt/6.8.3")

  def build_requirements(self):
    self.test_requires("catch2/2.13.10")
    self.test_requires("mdtcmakemodules/0.22.0@scandyna/testing")

  def generate(self):
    tc = CMakeToolchain(self)
    #tc.variables["FROM_CONAN_PROJECT_VERSION"] = self.version
    tc.generate()
