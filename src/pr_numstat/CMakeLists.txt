add_library(pr_numstat_lib)
target_sources(pr_numstat_lib PRIVATE
    numstat.cpp
    # stats.cpp
    # parse_args.cpp
)
target_compile_features(pr_numstat_lib PUBLIC cxx_std_23)
project_apply_warnings(pr_numstat_lib)

add_executable(pr_numstat main.cpp)
target_link_libraries(pr_numstat PRIVATE pr_numstat_lib)
target_compile_features(pr_numstat PRIVATE cxx_std_23)
project_apply_warnings(pr_numstat)

# --- Tests ---
add_executable(test_pr_numstat tests/test_main.cpp)
target_link_libraries(test_pr_numstat PRIVATE pr_numstat_lib GTest::gtest_main)
project_apply_warnings(test_pr_numstat)

include(GoogleTest)
gtest_discover_tests(test_pr_numstat)
