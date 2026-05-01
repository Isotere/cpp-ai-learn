project_add_library(shad_learn_lib
    SOURCES
        easy.cpp
        # stats.cpp
        # parse_args.cpp
    INCLUDE_CURRENT_DIR
)

project_add_library(leetcode_lib
    SOURCES
        leetcode/pr_1.cpp
    INCLUDE_CURRENT_DIR
)

project_add_executable(shad_learn
    SOURCES
        main.cpp
    LIBRARIES
        shad_learn_lib
)

project_add_gtest(test_shad_learn
    SOURCES
        tests/test_easy.cpp
        tests/test_leet_pr_1.cpp
    LIBRARIES
        shad_learn_lib
        leetcode_lib
)
