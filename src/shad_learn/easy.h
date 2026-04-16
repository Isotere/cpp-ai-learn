#pragma once

#include <cstddef>
#include <tuple>
#include <unordered_map>
#include <vector>

long long sum_array(const std::vector<long long>& in_array);

std::tuple<std::size_t, long long> max_array(const std::vector<long long>& in_array);

std::unordered_map<long long, std::size_t> count_array(const std::vector<long long>& in_array);