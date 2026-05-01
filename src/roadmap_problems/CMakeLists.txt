project_add_library(roadmap_problems_lib
    SOURCES
        tmp.cpp
    INCLUDE_CURRENT_DIR
)

project_add_executable(roadmap_problems
    SOURCES
        main.cpp
    LIBRARIES
        roadmap_problems_lib
)

project_add_gtest(test_roadmap_problems
    SOURCES
        tests/test_main.cpp
    LIBRARIES
        roadmap_problems_lib
)

project_add_benchmark(bench_roadmap_problems
    SOURCES
        bench/bench_roadmap_problems.cpp
    LIBRARIES
        roadmap_problems_lib
)
