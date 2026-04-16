#include <gtest/gtest.h>

#include <cstddef>
#include <vector>

#include "leetcode.h"

namespace {

::testing::AssertionResult is_valid_two_sum(const std::vector<int>& nums, int target, const std::vector<int>& result) {
    if (result.size() != 2) {
        return ::testing::AssertionFailure() << "expected 2 indices, got " << result.size();
    }

    int first  = result[0];
    int second = result[1];

    if (first < 0 || second < 0) {
        return ::testing::AssertionFailure() << "indices must be non-negative";
    }

    if (first == second) {
        return ::testing::AssertionFailure() << "indices must be different";
    }

    auto first_index  = static_cast<std::size_t>(first);
    auto second_index = static_cast<std::size_t>(second);

    if (first_index >= nums.size() || second_index >= nums.size()) {
        return ::testing::AssertionFailure() << "index is out of range";
    }

    if (nums[first_index] + nums[second_index] != target) {
        return ::testing::AssertionFailure() << "nums[result[0]] + nums[result[1]] must equal target";
    }

    return ::testing::AssertionSuccess();
}

TEST(LeetCodePr0001TwoSum, HandlesExamples) {
    auto nums1 = std::vector<int>{2, 7, 11, 15};
    EXPECT_TRUE(is_valid_two_sum(nums1, 9, leetcode::pr0001::two_sum(nums1, 9)));

    auto nums2 = std::vector<int>{3, 2, 4};
    EXPECT_TRUE(is_valid_two_sum(nums2, 6, leetcode::pr0001::two_sum(nums2, 6)));

    auto nums3 = std::vector<int>{3, 3};
    EXPECT_TRUE(is_valid_two_sum(nums3, 6, leetcode::pr0001::two_sum(nums3, 6)));
}

TEST(LeetCodePr0001TwoSum, HandlesNegativeValues) {
    auto nums = std::vector<int>{-3, 4, 3, 90};
    EXPECT_TRUE(is_valid_two_sum(nums, 0, leetcode::pr0001::two_sum(nums, 0)));
}

TEST(LeetCodePr0001TwoSum, HandlesZeroTarget) {
    auto nums = std::vector<int>{0, 4, 3, 0};
    EXPECT_TRUE(is_valid_two_sum(nums, 0, leetcode::pr0001::two_sum(nums, 0)));
}

}  // namespace
