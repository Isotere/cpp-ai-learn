project_add_library(algos_sort_lib
    SOURCES
        tmp.cpp
        # stats.cpp
        # parse_args.cpp
    INCLUDE_CURRENT_DIR
)

project_add_executable(algos_sort
    SOURCES
        main.cpp
)

project_add_gtest(test_algos_sort
    SOURCES
        tests/test_main.cpp
        tests/test_insertion_sort.cpp
    LIBRARIES
        algos_sort_lib
)

project_add_benchmark(bench_algos_sort
    SOURCES
        bench/bench_insertion_sort.cpp
    LIBRARIES
        algos_sort_lib
)
