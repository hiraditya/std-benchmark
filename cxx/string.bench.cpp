#include <string>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

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
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(s1.find(s2));
  }
  state.SetComplexityN(N);
}

void BM_find(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned ss2_sz = N/16;
  char ss1[N];
  char ss2[ss2_sz];
  fillRandomChars(ss1, ss1+N, true);
  fillRandomChars(ss2, ss2+ss2_sz, false);
  std::string s1(ss1, N);
  std::string s2(ss2, ss2_sz);
  while (state.KeepRunning()) {
    // searching for all the elements.
    benchmark::DoNotOptimize(s1.find(s2));
  }
  state.SetComplexityN(N);
}

// Benchmark when there is no match.
static void BM_find_no_match(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0)/8, '*');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2));
}

// Benchmark when the string matches first time.
static void BM_find_all_match(benchmark::State& state) {
  std::string s1(state.range(0), '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2));
}

// Benchmark when the string matches somewhere in the end.
static void BM_find_match1(benchmark::State& state) {
  std::string s1(state.range(0), '*');
  s1 += std::string(state.range(0), '-');
  std::string s2(state.range(0)/4, '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2));
}

// Benchmark when the string matches somewhere from middle to the end.
static void BM_find_match2(benchmark::State& state) {
  std::string s1(state.range(0), '*');
  s1 += std::string(state.range(0), '-');
  s1 += std::string(state.range(0), '*');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2));
}

COMPLEXITY_BENCHMARK(BM_find_nomatch, L1);
COMPLEXITY_BENCHMARK(BM_find_all_match, L1);
COMPLEXITY_BENCHMARK(BM_find_match1, L1);
COMPLEXITY_BENCHMARK(BM_find_match2, L1);
COMPLEXITY_BENCHMARK(BM_find, L1);
BENCHMARK_MAIN()

