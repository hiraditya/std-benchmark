#include<algorithm>
#include<list>
#include<set>
#include<vector>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

template<typename V>
void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillSeq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::find(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillSeq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::lower_bound(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::vector<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::list<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::vector<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::list<int>, L1);

BENCHMARK_MAIN()
