#include <iterator>
#include <algorithm>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Linear search on a sequence
void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  int a[N];
  fillSeq(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::find(a, a+N, i));
  }
  state.SetComplexityN(N);
}

// Binary search on a sequence
void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  int a[N];
  fillSeq(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::lower_bound(a, a+N, i));
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK(BM_search_linear, L1);
COMPLEXITY_BENCHMARK(BM_search_binary, L1);
COMPLEXITY_BENCHMARK(BM_search_linear, L2);
COMPLEXITY_BENCHMARK(BM_search_binary, L2);
BENCHMARK_MAIN()
