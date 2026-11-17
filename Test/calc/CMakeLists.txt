
add_executable(
    ## Add test Code and name of test executable
  calc_test
  calc_test.cc
)
find_package(GTest CONFIG REQUIRED)

# linking to vcpkg managed gtest
target_link_libraries(calc_test PRIVATE 
  calc
  GTest::gtest 
  GTest::gtest_main 
  GTest::gmock 
  GTest::gmock_main)

include(GoogleTest)
gtest_discover_tests(calc_test)