add_library(algos_sort_lib)
target_sources(algos_sort_lib PRIVATE
    tmp.cpp
    # stats.cpp
    # parse_args.cpp
)
target_include_directories(algos_sort_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(algos_sort_lib PUBLIC cxx_std_23)
project_apply_warnings(algos_sort_lib)

add_executable(algos_sort main.cpp)
target_compile_features(algos_sort PRIVATE cxx_std_23)
project_apply_warnings(algos_sort)

# --- Tests ---
add_executable(test_algos_sort
    tests/test_main.cpp
    tests/test_insertion_sort.cpp
)
target_link_libraries(test_algos_sort PRIVATE algos_sort_lib GTest::gtest_main)
project_apply_warnings(test_algos_sort)

include(GoogleTest)
gtest_discover_tests(test_algos_sort)

# --- Benchmarks ---
if(WITH_BENCHMARK)
    add_executable(bench_algos_sort bench/bench_insertion_sort.cpp)
    target_link_libraries(bench_algos_sort PRIVATE algos_sort_lib benchmark::benchmark)
    project_apply_warnings(bench_algos_sort)
endif()
