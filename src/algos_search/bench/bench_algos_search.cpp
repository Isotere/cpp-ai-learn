#include <benchmark/benchmark.h>

#include <cstddef>
#include <numeric>
#include <vector>

#include "linear.h"

namespace {

std::vector<int> make_sequential(std::size_t n) {
    std::vector<int> data(n);
    std::iota(data.begin(), data.end(), 0);
    return data;
}

// Имена BM_* — конвенция Google Benchmark, попадают в отчёт make bench.
// NOLINTBEGIN(readability-identifier-naming)
void BM_LinearSearch_First(benchmark::State& state) {
    const auto data = make_sequential(static_cast<std::size_t>(state.range(0)));
    for (auto _ : state) {
        benchmark::DoNotOptimize(search::linear(data, 0));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinearSearch_First)->RangeMultiplier(2)->Range(1 << 6, 1 << 20)->Complexity(benchmark::o1);

void BM_LinearSearch_Middle(benchmark::State& state) {
    const auto data = make_sequential(static_cast<std::size_t>(state.range(0)));
    const auto needle = static_cast<int>(state.range(0) / 2);
    for (auto _ : state) {
        benchmark::DoNotOptimize(search::linear(data, needle));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinearSearch_Middle)->RangeMultiplier(2)->Range(1 << 6, 1 << 20)->Complexity(benchmark::oN);

void BM_LinearSearch_Last(benchmark::State& state) {
    const auto data = make_sequential(static_cast<std::size_t>(state.range(0)));
    const auto needle = static_cast<int>(state.range(0) - 1);
    for (auto _ : state) {
        benchmark::DoNotOptimize(search::linear(data, needle));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinearSearch_Last)->RangeMultiplier(2)->Range(1 << 6, 1 << 20)->Complexity(benchmark::oN);

void BM_LinearSearch_Missing(benchmark::State& state) {
    const auto data = make_sequential(static_cast<std::size_t>(state.range(0)));
    const auto needle = static_cast<int>(state.range(0));
    for (auto _ : state) {
        benchmark::DoNotOptimize(search::linear(data, needle));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_LinearSearch_Missing)->RangeMultiplier(2)->Range(1 << 6, 1 << 20)->Complexity(benchmark::oN);
// NOLINTEND(readability-identifier-naming)

}  // namespace

BENCHMARK_MAIN();
