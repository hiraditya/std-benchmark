#include <cstdlib>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

static int compareints(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

// qsort
void BM_sort(benchmark::State& state) {
  const unsigned N = state.range(0);
  int *a = (int*) malloc(N*sizeof(int));
  fillSeq(a, a+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i) {
      qsort (a, N, sizeof (int), compareints);
    }
  }
  state.SetComplexityN(N);
  free(a);
}

static const int MSize = L1;
COMPLEXITY_BENCHMARK(BM_sort, MSize);
BENCHMARK_MAIN()
