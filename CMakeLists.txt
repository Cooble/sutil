# CMakeList.txt : CMake project for sutil, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project ("sutil")

# Add source to this project's executable.
add_executable (sutil "sutil.cpp" "sutil.h" "test.cpp")

# TODO: Add tests and install targets if needed.
