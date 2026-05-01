#include <benchmark/benchmark.h>

#include <algorithm>
#include <cstddef>
#include <numeric>
#include <random>
#include <vector>

#include "insertion_sort.h"

namespace {

std::vector<int> make_random(std::size_t n) {
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(-1'000'000, 1'000'000);
    std::vector<int> v(n);
    std::ranges::generate(v, [&] { return dist(rng); });
    return v;
}

std::vector<int> make_sorted(std::size_t n) {
    std::vector<int> v(n);
    std::ranges::iota(v, 0);
    return v;
}

std::vector<int> make_reversed(std::size_t n) {
    auto v = make_sorted(n);
    std::ranges::reverse(v);
    return v;
}

// Имена BM_* — конвенция Google Benchmark, попадают в отчёт make bench.
// NOLINTBEGIN(readability-identifier-naming)
void BM_InsertionSort_Random(benchmark::State& state) {
    const auto data = make_random(static_cast<std::size_t>(state.range(0)));
    for (auto _ : state) {
        state.PauseTiming();
        auto copy = data;
        state.ResumeTiming();
        // DoNotOptimize: запрет компилятору выкинуть вызов как dead code.
        // ClobberMemory: барьер, запрещающий переупорядочить записи в память
        // через границу итерации (страховка от чрезмерных оптимизаций).
        benchmark::DoNotOptimize(sorting::insertion(std::move(copy)));
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InsertionSort_Random)->RangeMultiplier(2)->Range(1 << 6, 1 << 12)->Complexity(benchmark::oNSquared);

void BM_InsertionSort_Sorted(benchmark::State& state) {
    const auto data = make_sorted(static_cast<std::size_t>(state.range(0)));
    for (auto _ : state) {
        state.PauseTiming();
        auto copy = data;
        state.ResumeTiming();
        // DoNotOptimize: запрет компилятору выкинуть вызов как dead code.
        // ClobberMemory: барьер, запрещающий переупорядочить записи в память
        // через границу итерации (страховка от чрезмерных оптимизаций).
        benchmark::DoNotOptimize(sorting::insertion(std::move(copy)));
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InsertionSort_Sorted)->RangeMultiplier(2)->Range(1 << 6, 1 << 12)->Complexity(benchmark::oN);

void BM_InsertionSort_Reversed(benchmark::State& state) {
    const auto data = make_reversed(static_cast<std::size_t>(state.range(0)));
    for (auto _ : state) {
        state.PauseTiming();
        auto copy = data;
        state.ResumeTiming();
        // DoNotOptimize: запрет компилятору выкинуть вызов как dead code.
        // ClobberMemory: барьер, запрещающий переупорядочить записи в память
        // через границу итерации (страховка от чрезмерных оптимизаций).
        benchmark::DoNotOptimize(sorting::insertion(std::move(copy)));
        benchmark::ClobberMemory();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_InsertionSort_Reversed)->RangeMultiplier(2)->Range(1 << 6, 1 << 12)->Complexity(benchmark::oNSquared);
// NOLINTEND(readability-identifier-naming)

}  // namespace

BENCHMARK_MAIN();
