# CMakeList.txt : CMake project for gTest, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (gTest "gTest.cpp" "dynamicArrayTest.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET gTest PROPERTY CXX_STANDARD 20)
endif()

# Now simply link against gtest or gtest_main as needed. Eg
target_link_libraries(gTest gtest_main)