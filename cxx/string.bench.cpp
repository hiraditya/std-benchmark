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

static void BM_find(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned ss2_sz = N/16;
  std::string s1(N, 0);
  std::string s2(ss2_sz, 0);
  fill_random_chars(s1.begin(), s1.end(), true);
  fill_random_chars(s2.begin(), s2.end(), false);
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

static void BM_strcat(benchmark::State& state) {
  const unsigned N = state.range(0);
  const unsigned s2_sz = N/16;
  std::string s1(N, 0);
  std::string s2(s2_sz, 0);
  fill_random_chars(s1.begin(), s1.end(), true);
  fill_random_chars(s2.begin(), s2.end(), false);
  unsigned s1_sz = 1;
  while (state.KeepRunning()) {
    benchmark::DoNotOptimize(s1.append(s2));
    s1_sz += s2_sz;
    if (s1_sz >= N) {
      //
    }
  }
  state.SetComplexityN(N);
}

static const int MSize = L2;
COMPLEXITY_BENCHMARK(BM_find, MSize);
COMPLEXITY_BENCHMARK(BM_find_no_match, MSize);
COMPLEXITY_BENCHMARK(BM_find_all_match, MSize);
COMPLEXITY_BENCHMARK(BM_find_match1, MSize);
COMPLEXITY_BENCHMARK(BM_find_match2, MSize);
COMPLEXITY_BENCHMARK(BM_strcat, MSize);
BENCHMARK_MAIN()

