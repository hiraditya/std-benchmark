#include <cstdlib>
#include <cmath>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Compute trig of N numbers
#define BM_trig(Name) template<typename T> \
void BM_##Name(benchmark::State& state) {\
  const unsigned N = state.range(0);\
  c_alloc<T> a(N);\
  fill_seq(a.get(), a.get()+N);\
  while (state.KeepRunning()) {\
    for (int i = 0; i < N; ++i) {\
      T p = Name(a[i]);\
      benchmark::DoNotOptimize(p);\
    }\
  }\
  state.SetComplexityN(N);\
}

// Values between -1 and +1
#define BM_atrig(Name) template<typename T> \
void BM_##Name(benchmark::State& state) {\
  const unsigned N = state.range(0);\
  c_alloc<T> a(N);\
  fill_random(a.get(), a.get()+N, RAND_MAX);\
  while (state.KeepRunning()) {\
    for (int i = 0; i < N; ++i) {\
      T p = Name(a[i]);\
      benchmark::DoNotOptimize(p);\
    }\
  }\
  state.SetComplexityN(N);\
}

BM_trig(sin)
BM_trig(cos)
BM_trig(tan)
BM_trig(sinh)
BM_trig(cosh)
BM_trig(tanh)
BM_trig(atan)
BM_trig(asin)
BM_trig(acos)

static const int MSize = L1;
COMPLEXITY_BENCHMARK_GEN(BM_sin, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cos, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tan, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sinh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cosh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tanh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_asin, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_acos, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_atan, float, MSize);

COMPLEXITY_BENCHMARK_GEN(BM_sin, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cos, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tan, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sinh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cosh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tanh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_asin, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_acos, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_atan, double, MSize);



BENCHMARK_MAIN()
