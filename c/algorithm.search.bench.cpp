#include <iterator>
#include <algorithm>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

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

COMPLEXITY_BENCHMARK(BM_search_linear, L1);

BENCHMARK_MAIN()
