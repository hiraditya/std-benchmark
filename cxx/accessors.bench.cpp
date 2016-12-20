#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<deque>
#include<list>
#include<vector>

// TODO: get, operator[], find, count, equal_range, erase

template<typename V>
void BM_advance(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v;
  fill_seq(v);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i) {
      auto it = v.begin();
      std::advance(it, i);
      benchmark::DoNotOptimize(it);
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_at(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      benchmark::DoNotOptimize(v.at(i));
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::list<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::deque<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_at, std::vector<int>, MSize);
BENCHMARK_MAIN()
