#include "easy.h"

#include <cassert>

// sum_array: O(n) time, O(1) memory
long long sum_array(const std::vector<long long>& in_array) {
    long long result{};

    for (const auto& v : in_array) {
        result += v;
    }

    return result;
}

// max_array: O(n) time, O(1) memory
std::tuple<std::size_t, long long> max_array(const std::vector<long long>& in_array) {
    assert(!in_array.empty());

    std::size_t ind{0};
    long long   max = in_array.at(0);
    for (std::size_t i = 1; i < in_array.size(); ++i) {
        if (max < in_array.at(i)) {
            ind = i;
            max = in_array.at(i);
        }
    }

    return {ind, max};
}

// count_array: O(n) time, O(n) memory
std::unordered_map<long long, std::size_t> count_array(const std::vector<long long>& in_array) {
    std::unordered_map<long long, std::size_t> result{};

    for (const auto& v : in_array) {
        result[v]++;
    }

    return result;
}
