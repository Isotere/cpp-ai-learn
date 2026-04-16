add_executable(tmpls main.cpp)
target_compile_features(tmpls PRIVATE cxx_std_23)
project_apply_warnings(tmpls)

# --- Tests ---
add_executable(test_tmpls tests/test_main.cpp)
target_link_libraries(test_tmpls PRIVATE GTest::gtest_main)
project_apply_warnings(test_tmpls)

include(GoogleTest)
gtest_discover_tests(test_tmpls)
