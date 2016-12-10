#include "benchmark/benchmark_api.h"

#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(2<<5)->Arg(2<<10)\
                                ->Arg(2<<20)->Arg(2<<30)

#define COMPLEXITY_BENCHMARK_TEST(x) BENCHMARK(x)->RangeMultiplier(2)->Range(1<<10, 1<<16)->Complexity();

void BM_search(benchmark::State& state) {
  int a[state.range(0)];
  while (state.KeepRunning()) {
    //state.PauseTiming(); state.ResumeTiming();
    for (int j = 0; j < state.range(0); ++j) {
      a[j] = j;
      //benchmark::DoNotOptimize(j);
    }
  }
  state.SetComplexityN(state.range(0));
}

//BASIC_BENCHMARK_TEST(BM_search);
COMPLEXITY_BENCHMARK_TEST(BM_search);

BENCHMARK_MAIN()
