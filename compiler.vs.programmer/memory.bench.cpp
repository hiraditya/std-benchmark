#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include <cstring>

const char* assign(const char *beg, const char *end, char *dest) {
  while (beg != end)
    *dest++ = *beg++;
  return beg;
}

const char* assign_res(const char * __restrict beg, const char * __restrict end, char *__restrict dest) {
  while (beg != end)
    *dest++ = *beg++;
  return beg;
}

void BM_prog_memcpy(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(N);
  memset(s1, '*', N);  
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(assign(s1.get(), s1.get()+N, s2.get()));
  }
  state.SetComplexityN(N);
}

void BM_compiler_memcpy(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(N);
  memset(s1, '*', N);  
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(assign_res(s1.get(), s1.get()+N, s2.get()));
  }
  state.SetComplexityN(N);
}

void BM_memcpy(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(N);
  memset(s1, '*', N);  
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(memcpy(s2.get(), s1.get(), N));
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;


BASIC_BENCHMARK_TEST(BM_prog_memcpy);
BASIC_BENCHMARK_TEST(BM_compiler_memcpy);
BASIC_BENCHMARK_TEST(BM_memcpy);

BENCHMARK_MAIN()

