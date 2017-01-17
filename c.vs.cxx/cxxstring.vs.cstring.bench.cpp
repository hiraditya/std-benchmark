//===-- cxxstring.vs.cstring.bench.cpp ------------------------------------===//
// Bechmark the c++ string::find function against the c-strstr function.
//
//===----------------------------------------------------------------------===//

#include <unordered_set>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>

#include "test_utils.h"
#include "benchmark/benchmark_api.h"

constexpr std::size_t MAX_STRING_LEN = 8 << 14;
constexpr std::size_t MIN_STRING_LEN = 16;
const int alignment_shift = 0;

// C++ Strings

// Benchmark when there is no match.
static void BM_CXXStringFindNoMatch(benchmark::State &state) {
  std::string s1(state.range(0), '-');
  std::string s2(8, '*');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_CXXStringFindNoMatch)->Range(MIN_STRING_LEN, MAX_STRING_LEN);

// Benchmark when the string matches first time.
static void BM_CXXStringFindAllMatch(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN, '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_CXXStringFindAllMatch)->Range(MIN_STRING_LEN, MAX_STRING_LEN);

// Benchmark when the string matches somewhere in the end.
static void BM_CXXStringFindMatch1(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}
BENCHMARK(BM_CXXStringFindMatch1)->Range(MIN_STRING_LEN, MAX_STRING_LEN / 4);

// Benchmark when the string matches somewhere from middle to the end.
static void BM_CXXStringFindMatch2(benchmark::State &state) {
  std::string s1(MAX_STRING_LEN / 2, '*');
  s1 += std::string(state.range(0), '-');
  s1 += std::string(state.range(0), '*');
  std::string s2(state.range(0), '-');
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}

BENCHMARK(BM_CXXStringFindMatch2)->Range(MIN_STRING_LEN, MAX_STRING_LEN / 4);

static void BM_CXXStringRegression(benchmark::State &state) {
  std::string s1 = "aabbaabbaaxd adbffdadgaxaabbbddhatyaaaabbbaabbaabbcsy";
  std::string s2 = "aabbaabbc";
  while (state.KeepRunning())
    benchmark::DoNotOptimize(s1.find(s2, alignment_shift));
}

BENCHMARK(BM_CXXStringRegression);

// CStrings

static void BM_CStringFindNoMatch(benchmark::State &state) {
  const unsigned N = state.range(0);
  c_alloc<char> s1(N);
  c_alloc<char> s2(8);
  memset(s1, '-', N);
  memset(s2, '*', 8);
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}
BENCHMARK(BM_CStringFindNoMatch)->Range(MIN_STRING_LEN, MAX_STRING_LEN);

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
BENCHMARK(BM_CStringFindAllMatch)->Range(MIN_STRING_LEN, MAX_STRING_LEN);

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
BENCHMARK(BM_CStringFindMatch1)->Range(MIN_STRING_LEN, MAX_STRING_LEN / 4);

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

BENCHMARK(BM_CStringFindMatch2)->Range(MIN_STRING_LEN, MAX_STRING_LEN / 4);

static void BM_CStringRegression(benchmark::State &state) {
  const char* s1 = "aabbaabbaaxd adbffdadgaxaabbbddhatyaaaabbbaabbaabbcsy";
  const char* s2 = "aabbaabbc";
  while (state.KeepRunning())
    benchmark::DoNotOptimize(strstr(s1, s2));
}

BENCHMARK(BM_CStringRegression);

BENCHMARK_MAIN()
