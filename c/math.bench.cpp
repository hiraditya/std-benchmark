#include <cstdlib>
#include <cmath>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Values between -1 and +1
#define BM_atrig(Name) template<typename T> \
void BM_##Name(benchmark::State& state) {\
  int N = state.range(0);\
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

// Trigonometric functions
BM_unary_real(sin)
BM_unary_real(cos)
BM_unary_real(tan)
BM_unary_real(sinh)
BM_unary_real(cosh)
BM_unary_real(tanh)
BM_unary_real(atan)
BM_atrig(asin)
BM_atrig(acos)

// Exponential/Logarithmic functions
BM_unary_real(exp)
BM_binary_real(pow)
BM_unary_real(sqrt)
BM_unary_real(log)
BM_unary_real(log10)
BM_binary_real(ldexp)

static const int MSize = L1;
#define COMPLEXITY_BENCHMARK_GEN_T(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_sin, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_cos, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_tan, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sinh, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_cosh, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_tanh, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_asin, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_acos, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_atan, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_exp, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_pow, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_sqrt, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_log, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_log10, T, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_ldexp, T, MSize);

COMPLEXITY_BENCHMARK_GEN_T(float)
COMPLEXITY_BENCHMARK_GEN_T(double)

BENCHMARK_MAIN()
