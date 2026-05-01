project_add_library(algos_search_lib
    SOURCES
        tmp.cpp
    INCLUDE_CURRENT_DIR
)

project_add_executable(algos_search
    SOURCES
        main.cpp
    LIBRARIES
        algos_search_lib
)

project_add_gtest(test_algos_search
    SOURCES
        tests/test_linear.cpp
    LIBRARIES
        algos_search_lib
)

project_add_benchmark(bench_algos_search
    SOURCES
        bench/bench_algos_search.cpp
    LIBRARIES
        algos_search_lib
)
