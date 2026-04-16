#include <iostream>
#include <vector>

#include "easy.h"

using ll = long long;

namespace {
void solve() {
    auto a = std::vector<ll>{3, 2, 1, 12, 5, 1, 6};

    auto sum = sum_array(a);

    std::cout << "Array (vector) sum: " << sum << '\n';

    auto max = max_array(a);
    std::cout << "Array max: " << std::get<1>(max) << " and index: " << std::get<0>(max) << '\n';

    auto cnt = count_array(a);
    for (const auto& [number, count] : cnt) {
        std::cout << count << " occurrence(s) of number '" << number << "'\n";
    }
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}