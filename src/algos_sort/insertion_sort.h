#pragma once

#include <concepts>
#include <cstddef>
#include <utility>
#include <vector>

namespace sorting {
// T должен поддерживать <, >, <=, >=, ==, != (см. std::totally_ordered)
template <std::totally_ordered T>
std::vector<T> insertion(std::vector<T> inp) {
    for (std::size_t i = 1; i < inp.size(); ++i) {
        std::size_t k = i;
        while (k > 0 && inp[k - 1] > inp[k]) {
            std::swap(inp[k - 1], inp[k]);
            --k;
        }
    }

    return inp;
}
}  // namespace sorting
