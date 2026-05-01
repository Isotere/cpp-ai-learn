#include "leetcode.h"

#include <gtest/gtest.h>

#include <vector>

TEST(LeetCodePr1480RunningSum, HandlesExamples) {
    std::vector<int> first{1, 2, 3, 4};
    EXPECT_EQ(leetcode::pr1480::running_sum(first), (std::vector<int>{1, 3, 6, 10}));

    std::vector<int> second{1, 1, 1, 1, 1};
    EXPECT_EQ(leetcode::pr1480::running_sum(second), (std::vector<int>{1, 2, 3, 4, 5}));

    std::vector<int> third{3, 1, 2, 10, 1};
    EXPECT_EQ(leetcode::pr1480::running_sum(third), (std::vector<int>{3, 4, 6, 16, 17}));
}

TEST(LeetCodePr1480RunningSum, HandlesSingleElement) {
    std::vector<int> nums{42};

    EXPECT_EQ(leetcode::pr1480::running_sum(nums), (std::vector<int>{42}));
}

TEST(LeetCodePr1480RunningSum, HandlesNegativeValues) {
    std::vector<int> nums{5, -2, -3, 10};

    EXPECT_EQ(leetcode::pr1480::running_sum(nums), (std::vector<int>{5, 3, 0, 10}));
}

