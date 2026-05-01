#pragma once

#include <concepts>
#include <cstddef>
#include <vector>

namespace search {
template <std::equality_comparable T>
long long linear(const std::vector<T>& input, const T& needle) {
    for (std::size_t i = 0; i < input.size(); ++i) {
        if (input[i] == needle) {
            return static_cast<long long>(i);
        }
    }

    return -1;
}
}  // namespace search