project_add_executable(tmpls
    SOURCES
        main.cpp
)

project_add_gtest(test_tmpls
    SOURCES
        tests/test_main.cpp
)
