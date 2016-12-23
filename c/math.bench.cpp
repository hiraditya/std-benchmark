#include <cstdlib>
#include <cmath>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

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
COMPLEXITY_BENCHMARK_GEN(BM_sin, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cos, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tan, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sinh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cosh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tanh, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_asin, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_acos, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_atan, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_exp, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_pow, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sqrt, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_log, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_log10, float, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_ldexp, float, MSize);

COMPLEXITY_BENCHMARK_GEN(BM_sin, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cos, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tan, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sinh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_cosh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_tanh, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_asin, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_acos, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_atan, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_exp, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_pow, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_sqrt, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_log, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_log10, double, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_ldexp, double, MSize);


BENCHMARK_MAIN()
