#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include <string>
#include <cassert>

static inline void BM_find_util(benchmark::State& state, const std::string &s1,
                           const std::string &s2, std::string::size_type ex) {
  std::string::size_type pos = std::string::npos;
  while (state.KeepRunning()) {
    pos = s1.find(s2);
    benchmark::DoNotOptimize(pos);
  }
  assert (pos == ex);
}

// Linear search on a sequence
void BM_find_nomatch(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned ss2_sz = N/16;
  char ss1[N];
  char ss2[ss2_sz];
  fillRandomChars(ss1, ss1+N, true);
  fillRandomChars(ss2, ss2+ss2_sz, false);
  std::string s1(ss1, N);
  std::string s2(ss2, ss2_sz);
  BM_find_util(state, s1, s2, std::string::npos);
  state.SetComplexityN(N);
}

void BM_find(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned ss2_sz = N/16;
  std::string s1(N, 0);
  std::string s2(ss2_sz, 0);
  fillRandomChars(s1.begin(), s1.end(), true);
  fillRandomChars(s2.begin(), s2.end(), false);
  BM_find_util(state, s1, s2, std::string::npos);
  state.SetComplexityN(N);
}

// Benchmark when there is no match.
static void BM_find_no_match(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::string s1(N, '-');
  std::string s2(N/8, '*');
  BM_find_util(state, s1, s2, std::string::npos);
  state.SetComplexityN(N);
}

// Benchmark when the string matches first time.
static void BM_find_all_match(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::string s1(N, '-');
  std::string s2(N, '-');
  BM_find_util(state, s1, s2, 0);
  state.SetComplexityN(N);
}

// Benchmark when the string matches somewhere in the end.
static void BM_find_match1(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::string s1(N, '*');
  s1 += std::string(N/4, '-');
  std::string s2(N/4, '-');
  BM_find_util(state, s1, s2, N);
  state.SetComplexityN(N);
}

// Benchmark when the string matches somewhere from middle to the end.
static void BM_find_match2(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::string s1(N, '*');
  s1 += std::string(N/2, '-');
  s1 += std::string(N/2, '*');
  std::string s2(N/4, '-');
  BM_find_util(state, s1, s2, N);
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK(BM_find_nomatch, L2);
COMPLEXITY_BENCHMARK(BM_find, L2);
COMPLEXITY_BENCHMARK(BM_find_all_match, L2);
COMPLEXITY_BENCHMARK(BM_find_match1, L2);
COMPLEXITY_BENCHMARK(BM_find_match2, L2);
BENCHMARK_MAIN()

