#include <cassert>
#include <unordered_map>

#include "leetcode.h"

/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to
target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]



Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

**/

// two_sum: O(n) average time, O(n) memory
std::vector<int> leetcode::pr0001::two_sum(std::vector<int>& nums, int target) {
    assert(nums.size() > 1);

    std::unordered_map<int, int> mem{};

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int diff = target - nums[i];
        if (auto it = mem.find(diff); it != mem.end()) {
            return {it->second, i};
        }
        mem[nums[i]] = i;
    }

    assert(false && "Two Sum solution must exist");

    return {0, 0};
}