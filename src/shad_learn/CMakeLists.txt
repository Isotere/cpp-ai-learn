add_library(shad_learn_lib)
target_sources(shad_learn_lib PRIVATE
    easy.cpp
    # stats.cpp
    # parse_args.cpp
)
target_include_directories(shad_learn_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(shad_learn_lib PUBLIC cxx_std_23)
project_apply_warnings(shad_learn_lib)

add_library(leetcode_lib)
target_sources(leetcode_lib PRIVATE
    leetcode/pr_1.cpp
)
target_include_directories(leetcode_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(leetcode_lib PUBLIC cxx_std_23)
project_apply_warnings(leetcode_lib)

add_executable(shad_learn main.cpp)
target_link_libraries(shad_learn PRIVATE shad_learn_lib)
target_compile_features(shad_learn PRIVATE cxx_std_23)
project_apply_warnings(shad_learn)

# --- Tests ---
add_executable(test_shad_learn)
target_sources(test_shad_learn PRIVATE
    tests/test_easy.cpp
    tests/test_leet_pr_1.cpp
)
target_link_libraries(test_shad_learn PRIVATE shad_learn_lib leetcode_lib GTest::gtest_main)
project_apply_warnings(test_shad_learn)

include(GoogleTest)
gtest_discover_tests(test_shad_learn)
