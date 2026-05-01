#include "leetcode.h"

#include <gtest/gtest.h>

#include <vector>

TEST(LeetCodePr0217ContainsDuplicateSpeed, HandlesExamples) {
    std::vector<int> first{1, 2, 3, 1};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_speed(first));

    std::vector<int> second{1, 2, 3, 4};
    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_speed(second));

    std::vector<int> third{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_speed(third));
}

TEST(LeetCodePr0217ContainsDuplicateSpeed, HandlesSingleElement) {
    std::vector<int> nums{1};

    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_speed(nums));
}

TEST(LeetCodePr0217ContainsDuplicateSpeed, HandlesNegativeValues) {
    std::vector<int> duplicate{-1, 2, -1};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_speed(duplicate));

    std::vector<int> distinct{-3, -2, -1, 0};
    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_speed(distinct));
}

TEST(LeetCodePr0217ContainsDuplicateMemory, HandlesExamples) {
    std::vector<int> first{1, 2, 3, 1};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_memory(first));

    std::vector<int> second{1, 2, 3, 4};
    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_memory(second));

    std::vector<int> third{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_memory(third));
}

TEST(LeetCodePr0217ContainsDuplicateMemory, HandlesSingleElement) {
    std::vector<int> nums{1};

    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_memory(nums));
}

TEST(LeetCodePr0217ContainsDuplicateMemory, HandlesNegativeValues) {
    std::vector<int> duplicate{-1, 2, -1};
    EXPECT_TRUE(leetcode::pr0217::contains_duplicate_memory(duplicate));

    std::vector<int> distinct{-3, -2, -1, 0};
    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_memory(distinct));
}

TEST(LeetCodePr0217ContainsDuplicateMemory, SortsInputInPlace) {
    std::vector<int> nums{3, 1, 2};

    EXPECT_FALSE(leetcode::pr0217::contains_duplicate_memory(nums));
    EXPECT_EQ(nums, (std::vector<int>{1, 2, 3}));
}

