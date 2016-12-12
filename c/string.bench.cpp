#include <cstring>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Linear search on a sequence
void BM_strstr(benchmark::State& state) {
  const unsigned N = state.range(0);
  char s1[N];
  char s2[N/16];
  fillRandomChars(s1, s1+N);
  fillRandomChars(s2, s2+N/16, false);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(strstr(s1, s2));
  }
  state.SetComplexityN(N);
}

// Linear search on a sequence
void BM_strcmp(benchmark::State& state) {
  const unsigned N = state.range(0);
  char s1[N];
  char s2[N/16];
  fillRandomChars(s1, s1+N);
  fillRandomChars(s2, s2+N/16);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(strcmp(s1, s2));
  }
  state.SetComplexityN(N);
}

// Linear search on a sequence
void BM_strchr(benchmark::State& state) {
  const unsigned N = state.range(0);
  char s1[N];
  char s2 = '1';
  fillRandomChars(s1, s1+N);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(strchr(s1, s2));
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK(BM_strstr, L1);
COMPLEXITY_BENCHMARK(BM_strcmp, L1);
COMPLEXITY_BENCHMARK(BM_strchr, L1);
BENCHMARK_MAIN()

