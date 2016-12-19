#include <cstdlib>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// qsort
void BM_sort(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<int> a(N);
  fill_seq<int*>(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      qsort(a.get(), N, sizeof (int), compare<int>);
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK(BM_sort, MSize);
BENCHMARK_MAIN()
