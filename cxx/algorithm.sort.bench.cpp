#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<list>
#include<vector>

template<typename V>
void BM_sort_std(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillRandom(v);
  while (state.KeepRunning()) {
    std::sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_sort_stable(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillRandom(v);
  while (state.KeepRunning()) {
    std::stable_sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK_GEN(BM_sort_std, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sort_stable, std::vector<int>, MSize);

BENCHMARK_MAIN()
