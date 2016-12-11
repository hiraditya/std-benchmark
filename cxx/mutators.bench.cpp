#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<list>
#include<vector>
#include<forward_list>
#include<deque>

template<typename V>
void BM_push_back(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v;
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_push_back_resize(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_push_back_vector_reserve(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v;
  v.reserve(N);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

//std::forward_list<int> does not have push_back, push_back :(
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::vector<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::list<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::deque<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::vector<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::list<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::deque<int>, L1);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_vector_reserve, std::vector<int>, L1);

BENCHMARK_MAIN()
