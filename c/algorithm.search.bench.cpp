#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include <cstdlib>
#include <type_traits>

// Linear search on a sequence
void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  int *a = (int*) malloc(N*sizeof(int));
  fillSeq(a, a+N);
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
  free(a);
}

template<typename T>
static int compare(const void * a, const void * b)
{
  static_assert(std::is_integral<T>::value, "Not an integral type.");
  return (*(T*)a - *(T*)b);
}

// Binary search on a sequence
void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  int *a = (int*) malloc(N*sizeof(int));
  fillSeq(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      int *p = (int*) bsearch(&i, a, N, sizeof (int), compare<int>);
      benchmark::DoNotOptimize(p);
      assert(*p == i); // j is the i-th element in a
    }
  }
  state.SetComplexityN(N);
  free(a);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK(BM_search_linear, MSize);
COMPLEXITY_BENCHMARK(BM_search_binary, MSize);
BENCHMARK_MAIN()
