#include <cstdlib>
#include <type_traits>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// qsort
template<typename T>
void BM_sort(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<T> a(N);
  fill_seq<T*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      qsort(a.get(), N, sizeof (T), compare<T>);
  }
  state.SetComplexityN(N);
}

// Linear search on a sequence
template<typename T>
void BM_search_linear(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<T> a(N);
  fill_seq<T*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      int j = 0;
      while (j < N)
        if (a[j++] == i)
          break;
      benchmark::DoNotOptimize(j);
      assert(j == i); // j is the i-th element in a
    }
  }
  state.SetComplexityN(N);
}

// Binary search on a sequence
template<typename T>
void BM_search_binary(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<T> a(N);
  fill_seq<T*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      T *p = (T*) bsearch(&i, a, N, sizeof (T), compare<T>);
      benchmark::DoNotOptimize(p);
      assert(*p == i); // j is the i-th element in a
    }
  }
  state.SetComplexityN(N);
}

//static const int MSize = L1;
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, int, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, char, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, int, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, char, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sort, int, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sort, char, MSize);
BENCHMARK_MAIN()
