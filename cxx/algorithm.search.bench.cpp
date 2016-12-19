#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<list>
#include<vector>

template<typename V>
void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      int j = *std::find(v.begin(), v.end(), i);
      benchmark::DoNotOptimize(j);
      assert(j == i); // j is the i-th element in v
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      int j = *std::lower_bound(v.begin(), v.end(), i);
      benchmark::DoNotOptimize(j);
      assert(j == i); // j is the i-th element in v
    }
  }
  state.SetComplexityN(N);
}

static const int MSize = L2;
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::list<int>, MSize);

BENCHMARK_MAIN()
