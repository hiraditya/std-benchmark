#include <cstring>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

// Linear search on a sequence
static void BM_strstr(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(N/16);
  fill_random_chars<char*>(s1, s1+N, true);
  fill_random_chars<char*>(s2, s2+N/16, false);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(strstr(s1, s2));
  }
  state.SetComplexityN(N);
}

// FIXME: Set a limit on the max number of iterations.
static void BM_strcat(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned s2_sz = 2;
  c_alloc<char> s1(N);
  c_alloc<char> s2(s2_sz);
  fill_random_chars<char*>(s1, s1+1, true);
  fill_random_chars<char*>(s2, s2+s2_sz, false);
  unsigned s1_sz = 1;
  while (state.KeepRunning()) {
    // searching for all the elements.
    // FIXME: strcat is tricky because it keeps concatenating
    // until the timer stops, that corrupts memory.
    benchmark::DoNotOptimize(strcat(s1, s2));
    s1_sz += s2_sz;
    if (s1_sz >= N) {
      state.SkipWithError("Memory corruption");
    }
  }
  state.SetComplexityN(N);
}

// Linear search on a sequence
static void BM_strchr(benchmark::State& state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  char s2 = '1';
  fill_random_chars<char*>(s1, s1+N, true);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(strchr(s1, s2));
  }
  state.SetComplexityN(N);
}

static void BM_strcmp(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned s2_sz = N/16;
  c_alloc<char> s1(N);
  c_alloc<char> s2(s2_sz);
  fill_random_chars<char*>(s1, s1+N, true);
  fill_random_chars<char*>(s2, s2+s2_sz, false);
  unsigned i = 0;
  while (state.KeepRunning()) {
    // strcmp at varying positions
    benchmark::DoNotOptimize(strcmp(s1+(i++%N), s2));
  }
  state.SetComplexityN(N);
}

static void BM_strcpy(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned s2_sz = N/16;
  c_alloc<char> s1(N);
  c_alloc<char> s2(s2_sz);
  fill_random_chars<char*>(s1, s1+N, true);
  fill_random_chars<char*>(s2, s2+s2_sz, false);
  unsigned i = 0;
  while (state.KeepRunning()) {
    // strcpy at varying positions.
    const unsigned offset = (i++%N)/2;
    benchmark::DoNotOptimize(strcpy(s1 + offset, s2));
  }
  state.SetComplexityN(N);
}

static void BM_strlen(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned s2_sz = N/16;
  c_alloc<char> s1(N);
  c_alloc<char> s2(s2_sz);
  fill_random_chars<char*>(s1, s1+N, true);
  fill_random_chars<char*>(s2, s2+s2_sz, false);
  unsigned i = 0;
  while (state.KeepRunning()) {
    // strlen at varying positions.
    benchmark::DoNotOptimize(strlen(s1+i++));
    if (i == N) // Reinitialize to avoid segfault.
      i = 0;
  }
  state.SetComplexityN(N);
}

static const int MSize = L2;
COMPLEXITY_BENCHMARK(BM_strstr, MSize);
COMPLEXITY_BENCHMARK(BM_strcat, MSize);
COMPLEXITY_BENCHMARK(BM_strchr, MSize);
COMPLEXITY_BENCHMARK(BM_strcmp, MSize);
COMPLEXITY_BENCHMARK(BM_strcpy, MSize);
COMPLEXITY_BENCHMARK(BM_strlen, MSize);
BENCHMARK_MAIN()
