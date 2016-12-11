#include "benchmark/benchmark_api.h"
#include "test_configs.h"

void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  int a[N];
  while (state.KeepRunning()) {
    state.PauseTiming();
    // initialize.
    for (int j = 0; j < N; ++j) {
      a[j] = j;
      //benchmark::DoNotOptimize(a[j] = j);
    }
    state.ResumeTiming();
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (a[j] == i)
          break; // found!
      }
    }
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK(BM_search_linear, L1);

BENCHMARK_MAIN()
