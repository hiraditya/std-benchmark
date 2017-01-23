#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<deque>
#include<list>
#include<vector>

// TODO: reverse, rotate, shuffle, lower_bound, upper_bound
// uninitialized_fill, uninitialized_copy
// change data type (int, double, class { int, int }, and compare
// algorithms.

template<typename V>
void BM_sort_std(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_random(v);
  while (state.KeepRunning()) {
    std::sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_sort_stable(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_random(v);
  while (state.KeepRunning()) {
    std::stable_sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}


template<typename V>
void BM_search_linear(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      auto j = std::find(v.begin(), v.end(), i);
      benchmark::DoNotOptimize(j);
      assert(std::distance(v.begin(), j) == i); // j is the i-th element in v
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_search_binary(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      auto j = std::lower_bound(v.begin(), v.end(), i);
      benchmark::DoNotOptimize(j);
      assert(std::distance(v.begin(), j) == i); // j is the i-th element in v
    }
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;

#define TYPED_BENCHMARK(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::vector<T>, MSize); \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::list<T>, MSize); \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_std, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_stable, std::vector<T>, MSize);

// TODO: Find a better name for TYPED_BENCHMARK
//TYPED_BENCHMARK(int_int)
TYPED_BENCHMARK(int)
//TYPED_BENCHMARK(double)

BENCHMARK_MAIN()
