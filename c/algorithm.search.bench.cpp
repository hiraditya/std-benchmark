#include "benchmark/benchmark_api.h"
#include "test_configs.h"

void BM_search(benchmark::State& state) {
  const unsigned N = state.range(0);
  int a[N];
  while (state.KeepRunning()) {
    //state.PauseTiming(); state.ResumeTiming();
    for (int j = 0; j < N; ++j) {
      a[j] = j;
      //benchmark::DoNotOptimize(a[j] = j);
    }
  }
  state.SetComplexityN(state.range(0));
}

COMPLEXITY_BENCHMARK_TEST(BM_search);

BENCHMARK_MAIN()
