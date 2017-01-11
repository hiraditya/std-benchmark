#include <unordered_set>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>

#include "test_utils.h"
#include "benchmark/benchmark_api.h"

constexpr std::size_t MAX_STRING_LEN = 8 << 14;
const int alignment_shift = 0;

// Benchmark when there is no match.
static void BM_StringFindNoMatch(benchmark::State &state) {
  std::string s1(state.range(0), '-');
  std::string s2(8, '*');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_StringFindNoMatch)->Range(16, MAX_STRING_LEN);

// Benchmark when the string matches first time.
static void BM_StringFindAllMatch(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN, '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_StringFindAllMatch)->Range(16, MAX_STRING_LEN);

// Benchmark when the string matches somewhere in the end.
static void BM_StringFindMatch1(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_StringFindMatch1)->Range(16, MAX_STRING_LEN / 4);

// Benchmark when the string matches somewhere from middle to the end.
static void BM_StringFindMatch2(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  s1 += std::string(state.range(0), '*');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}

BENCHMARK(BM_StringFindMatch2)->Range(16, MAX_STRING_LEN / 4);

static void BM_StringRegression(benchmark::State &state) {
  std::string s1 = "aabbaabbaaxd adbffdadgaxaabbbddhatyaaaabbbaabbaabbcsy";
  std::string s2 = "aabbaabbc";
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}

BENCHMARK(BM_StringRegression);

//------------------------------------------------------------------
static void BM_CStringFindNoMatch(benchmark::State &state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(8);
  memset(s1, '-', N);
  memset(s2, '*', 8);
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}
BENCHMARK(BM_CStringFindNoMatch)->Range(16, MAX_STRING_LEN);

// Benchmark when the string matches first time.
static void BM_CStringFindAllMatch(benchmark::State &state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(MAX_STRING_LEN);
  c_alloc<char> s2(N);
  memset(s1, '-', MAX_STRING_LEN);
  memset(s2, '-', N);
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}
BENCHMARK(BM_CStringFindAllMatch)->Range(16, MAX_STRING_LEN);

// Benchmark when the string matches somewhere in the end.
static void BM_CStringFindMatch1(benchmark::State &state) {
  /*std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  std::string s2(state.range(0), '-');*/

  const unsigned N = state.range(0);
  c_alloc<char> s1(MAX_STRING_LEN/2+N);
  c_alloc<char> s2(N);
  memset(s1, '*', MAX_STRING_LEN/2);
  memset(s1 + MAX_STRING_LEN/2, '-', N);
  memset(s2, '-', N);
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}
BENCHMARK(BM_CStringFindMatch1)->Range(16, MAX_STRING_LEN / 4);

// Benchmark when the string matches somewhere from middle to the end.
static void BM_CStringFindMatch2(benchmark::State &state) {
  /*std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  s1 += std::string(state.range(0), '*');
  std::string s2(state.range(0), '-');*/

  const unsigned N = state.range(0);
  c_alloc<char> s1(MAX_STRING_LEN/2 + 2*N);
  c_alloc<char> s2(N);
  memset(s1, '*', MAX_STRING_LEN/2);
  memset(s1 + MAX_STRING_LEN/2, '-', N);
  memset(s1 + MAX_STRING_LEN/2 + N, '*', N);
  memset(s2, '-', N);
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}

BENCHMARK(BM_CStringFindMatch2)->Range(16, MAX_STRING_LEN / 4);

static void BM_CStringRegression(benchmark::State &state) {
  const char* s1 = "aabbaabbaaxd adbffdadgaxaabbbddhatyaaaabbbaabbaabbcsy";
  const char* s2 = "aabbaabbc";
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}

BENCHMARK(BM_CStringRegression);

BENCHMARK_MAIN()
