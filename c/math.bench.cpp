#include <cstdlib>
#include <cmath>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Compute sin of N numbers
template<typename T>
void BM_sin(benchmark::State& state) {
  const unsigned N = state.range(0);
  T *a = (T*) malloc(N*sizeof(T));
  fill_seq(a, a+N);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i) {
      T p = sin(a[i]);
      benchmark::DoNotOptimize(p);
    }
  }
  state.SetComplexityN(N);
  free(a);
}

static const int MSize = L2;
COMPLEXITY_BENCHMARK_GEN(BM_sin, float, MSize);

BENCHMARK_MAIN()
