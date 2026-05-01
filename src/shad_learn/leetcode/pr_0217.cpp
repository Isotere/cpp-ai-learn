/**
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every
element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true



Constraints:

    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
 */

#include <algorithm>
#include <cstddef>
#include <unordered_set>

#include "leetcode.h"

// O(n) по времени в среднем и O(n) по памяти.
//
// Trade-off: `unordered_set` имеет большие константы: hash lookup, buckets,
// node allocations, хуже cache locality. На практике для этой задачи вариант с
// сортировкой часто быстрее и почти всегда лучше по памяти, несмотря на
// O(n log n). Этот вариант полезен как пример hash-подхода или когда нельзя
// менять порядок элементов в `nums`.
bool leetcode::pr0217::contains_duplicate_speed(std::vector<int>& nums) {
    std::unordered_set<int> seen{};

    for (int val : nums) {
        if (!seen.insert(val).second) {
            return true;
        }
    }

    return false;
}

// O(nlog(n)) speed O(1) memory
// Changes in-vector
bool leetcode::pr0217::contains_duplicate_memory(std::vector<int>& nums) {
    std::ranges::sort(nums);

    for (std::size_t i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] == nums[i]) {
            return true;
        }
    }

    return false;
}
