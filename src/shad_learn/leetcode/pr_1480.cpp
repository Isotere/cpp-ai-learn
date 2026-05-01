/**
Given an array nums.
We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:

Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]



Constraints:

    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

**/

#include <cstddef>
#include <vector>

#include "leetcode.h"

// O(n) по скорости O(n) по памяти
std::vector<int> leetcode::pr1480::running_sum(std::vector<int>& nums) {
    std::vector<int> result(nums.size(), 0);

    if (nums.size() > 0) {
        result[0] = nums[0];
    }

    for (size_t i = 1; i < nums.size(); ++i) {
        result[i] = result[i - 1] + nums[i];
    }

    return result;
}

// O(n) по скорости O(1) по памяти
// std::vector<int> running_sum_comp(std::vector<int>& nums) {
//     if (nums.size() <= 1) {
//         return nums;
//     }

//     for (size_t i = 1; i < nums.size(); ++i) {
//         nums[i] += nums[i - 1];
//     }

//     return nums;
// }