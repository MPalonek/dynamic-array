# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("dynamic-array")

# Include sub-projects.
add_subdirectory ("app")
add_subdirectory ("test")
