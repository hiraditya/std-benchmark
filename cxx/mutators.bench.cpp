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

template<typename V>
void BM_insert(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N, 1);
  auto val = *v.begin();
  while (state.KeepRunning()) {
    v.insert(v.begin(), val);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_insert_last(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N, 1);
  auto val = *v.begin();
  while (state.KeepRunning()) {
    v.insert(--v.end(), val);
  }
  state.SetComplexityN(N);
}

//std::forward_list<int> does not have push_back, push_back :(
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::vector<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::list<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::deque<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::vector<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::list<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::deque<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_push_back_vector_reserve, std::vector<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert, std::vector<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert, std::list<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert, std::deque<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert_last, std::vector<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert_last, std::list<int>, L2);
COMPLEXITY_BENCHMARK_GEN(BM_insert_last, std::deque<int>, L2);
BENCHMARK_MAIN()
