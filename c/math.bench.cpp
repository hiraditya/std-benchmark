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

static uint32_t digits10(uint64_t v) {
  uint32_t result = 0;
  do {
    ++result;
    v /= 10;
  } while (v);
  return result;
}

static uint32_t digits10_fast(uint64_t v) {
  uint32_t result = 1;
  for (;;) {
    if (v < 10) return result;
    if (v < 100) return result + 1;
    if (v < 1000) return result + 2;
    if (v < 10000) return result + 3; // Skip ahead by 4 orders of magnitude
    v /= 10000;
    result += 4;
  }
}

BM_unary_real(digits10)
BM_unary_real(digits10_fast)

/*void BM_digits10(benchmark::State& state) {
  int N = state.range(0);
  c_alloc<T> a(N);
  fill_random(a.get(), a.get()+N, RAND_MAX);
  int i = 0;
  while (state.KeepRunning()) {
    uint32_t p = digits10(a[i]);
    benchmark::DoNotOptimize(p);
    if (i++ == N) // re-initialize
      i = 0;
  }
  state.SetComplexityN(N);
}*/

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

COMPLEXITY_BENCHMARK_GEN(BM_digits10, int, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_digits10_fast, int, MSize);

BENCHMARK_MAIN()
