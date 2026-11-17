cmake_minimum_required(VERSION 4.0)
project(templateProjectMSVC VERSION 1.0.0)

option(BUILD_TESTS "Will build test programs, installing GoogleTest if neccessary" OFF)
option(ENABLE_DOXYGEN_INTEGRATION "Enables CMake to generate documentation using Doxygen" OFF)

if(BUILD_TESTS)
  # HEY THERE!
  # You... YEAH YOU!!
  # It's really important that enable_testing() goes here in
  # the *root* CMakeLists.txt file. putting it in one of the 
  # test subdir cmakelists.txt will break google test!!
  # Or won't let it find your tests properly.
  enable_testing()
  
  #vcpkg gtest method
  find_package(GTest CONFIG REQUIRED)
  #include(GoogleTest)
  
  add_subdirectory(Test)
endif()

add_subdirectory(src)

# Generating Documentation
if(ENABLE_DOXYGEN_INTEGRATION)
  message("Doxygen Integration enabled: Finding Doxygen")
  add_subdirectory(docs)
endif()

