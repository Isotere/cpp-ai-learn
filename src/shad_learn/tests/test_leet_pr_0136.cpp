#include "leetcode.h"

#include <gtest/gtest.h>

#include <vector>

TEST(LeetCodePr0136SingleNumber, HandlesExamples) {
    std::vector<int> first{2, 2, 1};
    EXPECT_EQ(leetcode::pr0136::single_number(first), 1);

    std::vector<int> second{4, 1, 2, 1, 2};
    EXPECT_EQ(leetcode::pr0136::single_number(second), 4);

    std::vector<int> third{1};
    EXPECT_EQ(leetcode::pr0136::single_number(third), 1);
}

TEST(LeetCodePr0136SingleNumber, HandlesNegativeValues) {
    std::vector<int> nums{-1, 2, 2};

    EXPECT_EQ(leetcode::pr0136::single_number(nums), -1);
}

TEST(LeetCodePr0136SingleNumber, HandlesZero) {
    std::vector<int> nums{0, 7, 7};

    EXPECT_EQ(leetcode::pr0136::single_number(nums), 0);
}

TEST(LeetCodePr0136SingleNumber, DoesNotDependOnOrder) {
    std::vector<int> nums{10, -3, 10, 4, 4};

    EXPECT_EQ(leetcode::pr0136::single_number(nums), -3);
}

