#include <cstdlib>
#include <type_traits>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// qsort
void BM_sort(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<int> a(N);
  fill_seq<int*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      qsort(a.get(), N, sizeof (int), compare<int>);
  }
  state.SetComplexityN(N);
}

// Linear search on a sequence
void BM_search_linear(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<int> a(N);
  fill_seq<int*>(a, a+N);
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
void BM_search_binary(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<int> a(N);
  fill_seq<int*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      int *p = (int*) bsearch(&i, a, N, sizeof (int), compare<int>);
      benchmark::DoNotOptimize(p);
      assert(*p == i); // j is the i-th element in a
    }
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK(BM_search_linear, MSize);
COMPLEXITY_BENCHMARK(BM_search_binary, MSize);
COMPLEXITY_BENCHMARK(BM_sort, MSize);
BENCHMARK_MAIN()
