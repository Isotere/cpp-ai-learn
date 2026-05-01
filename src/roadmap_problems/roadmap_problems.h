#pragma once

#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

namespace roadmap_problems {

// Задача из roadmap, День 4: подготовить префиксные суммы для быстрых запросов
// суммы на отрезке.
//
// Для входного массива `a` размера n строим `pref` размера n + 1:
//   pref[0] = 0
//   pref[i + 1] = pref[i] + a[i]
//
// Возвращаемая лямбда должна работать как range_sum(l, r): отвечать на запрос
// суммы на полуинтервале [l, r) за O(1) по формуле `pref[r] - pref[l]`.
// Допустимые границы запроса: 0 <= l <= r <= n. Полуинтервал удобен тем, что
// пустой диапазон выражается как `range_sum(l, l) == 0`, а случай l == 0 не
// требует отдельной обработки.
inline auto make_prefix_sum(const std::vector<int>& input) {
    std::vector<long long> pref(input.size() + 1, 0);

    for (std::size_t i = 0; i < input.size(); ++i) {
        pref[i + 1] = pref[i] + input[i];
    }

    return [pref = std::move(pref)](std::size_t l, std::size_t r) {
        assert(l <= r && r < pref.size());

        return pref[r] - pref[l];
    };
}

}  // namespace roadmap_problems
