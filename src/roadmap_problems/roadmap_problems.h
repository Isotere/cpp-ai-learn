#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <unordered_map>
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

// Задача из roadmap, День 4: построить счетчик частот чисел.
//
// Для входного массива `input` строим `unordered_map`, где ключ — число из
// массива, а значение — сколько раз оно встретилось.
//
// Возвращаемая лямбда работает как count(needle): за O(1) в среднем отвечает,
// сколько раз `needle` встречается во входном массиве. Если числа нет, результат
// равен 0. Подготовка занимает O(n) времени и O(k) памяти, где k — количество
// различных чисел.
inline auto make_number_counter(const std::vector<int>& input) {
    std::unordered_map<int, std::size_t> stor{};

    std::ranges::for_each(input, [&stor](int val) { ++stor[val]; });

    return [stor = std::move(stor)](int needle) {
        auto it = stor.find(needle);

        if (it == stor.end()) {
            return static_cast<std::size_t>(0);
        }

        return it->second;
    };
}

}  // namespace roadmap_problems
