
add_executable(
    ## Add test Code and name of test executable
  hello_test
  hello_test.cc
)
find_package(GTest CONFIG REQUIRED)

# linking to vcpkg managed gtest
target_link_libraries(hello_test PRIVATE 
  GTest::gtest 
  GTest::gtest_main 
  GTest::gmock 
  GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(hello_test)
add_subdirectory(calc)