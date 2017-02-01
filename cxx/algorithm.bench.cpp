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

#ifndef NDEBUG
#include<iostream>
template<typename T>
std::ostream& operator<<(std::ostream& os,const std::vector<T>& v)
{
  for(typename std::vector<T>::const_iterator i = v.begin(); i!= v.end(); ++i)
    os<<*i<<' ';
  os<< "\n";
  return os;
}
#endif

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
void BM_sort_std_list_with_vector(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_random(v);
  using T = typename V::value_type;
  // Copy the contents into a vector
  while (state.KeepRunning()) {
    std::vector<T> vec(v.begin(), v.end());
    // Sort the vector
    std::sort(vec.begin(), vec.end());
    // Put the item back in the list
    v.assign(vec.begin(), vec.end());
  }
  state.SetComplexityN(N);
}

// Sort (a sequence in ascending order) in ascending order.
template<typename V>
void BM_sort_std_ascending(benchmark::State& state) {
  int N = state.range(0);
  using T = typename V::value_type;
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    std::sort(v.begin(), v.end(), std::less<T>());
  }
  state.SetComplexityN(N);
}

// Sort (a sequence in ascending order) in descending order.
template<typename V>
void BM_sort_std_descending(benchmark::State& state) {
  int N = state.range(0);
  using T = typename V::value_type;
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    std::sort(v.begin(), v.end(), std::greater<T>());
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

#define COMPLEXITY_BENCHMARK_GEN_T(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::vector<T>, MSize); \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::list<T>, MSize); \
    COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_std, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_std_ascending, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_std_descending, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sort_stable, std::vector<T>, MSize);

// TODO: Find a better name for TYPED_BENCHMARK

COMPLEXITY_BENCHMARK_GEN_T(int)
//COMPLEXITY_BENCHMARK_GEN_T(double)
COMPLEXITY_BENCHMARK_GEN_T(aggregate)

COMPLEXITY_BENCHMARK_GEN(BM_sort_std_list_with_vector, std::list<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sort_std_list_with_vector, std::list<aggregate>, MSize);

BENCHMARK_MAIN()
