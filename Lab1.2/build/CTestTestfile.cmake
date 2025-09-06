# CMake generated Testfile for 
# Source directory: /workspaces/CS-310/Lab1.2
# Build directory: /workspaces/CS-310/Lab1.2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
include("/workspaces/CS-310/Lab1.2/build/tests-b12d07c_include.cmake")
add_test([=[run_tests]=] "/workspaces/CS-310/Lab1.2/build/tests")
set_tests_properties([=[run_tests]=] PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/CS-310/Lab1.2/CMakeLists.txt;57;add_test;/workspaces/CS-310/Lab1.2/CMakeLists.txt;0;")
subdirs("_deps/json-build")
subdirs("_deps/yaml-cpp-build")
subdirs("_deps/catch2-build")
