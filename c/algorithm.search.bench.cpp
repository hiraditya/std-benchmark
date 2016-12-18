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

static const int MSize = L2;
COMPLEXITY_BENCHMARK(BM_search_linear, MSize);
COMPLEXITY_BENCHMARK(BM_search_binary, MSize);
COMPLEXITY_BENCHMARK(BM_search_linear, MSize);
COMPLEXITY_BENCHMARK(BM_search_binary, MSize);
BENCHMARK_MAIN()
