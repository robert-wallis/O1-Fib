#include <benchmark/benchmark.h>
#include <cmath>
#include "fib.hpp"

static void BM_Fib(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(fib(state.range(0)));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_Fib)
    ->Arg(1)
    ->Arg(2)
    ->Arg(3)
    ->Arg(4)
    ->Arg(10)
    ->Arg(20)
    ->Arg(40)
    ->Arg(60)
    ->Arg(90)
    ->Complexity();

BENCHMARK_MAIN();
