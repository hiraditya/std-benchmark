#ifndef TEST_CONFIGS_H
#define TEST_CONFIGS_H

#define KB << 10
#define MB << 20
#define GB << 30

#define i7_4770


// Configurations for i7_4770
#ifdef i7_4770
// To benchmark data residing completely in L1 cache.
#define L1 (32 KB)
// For the Travis CI to run the entire test.
//#define L1 (1 KB)
// To benchmark data residing in L2 cache.
#define L2 (256 KB)
// To benchmark data residing in L3 cache.
#define L3 (8192 KB)
// To benchmark data residing in main memory.
#define MEMORY (12 GB)
#endif

#define SINGLE_ARG(...) __VA_ARGS__

#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->RangeMultiplier(2)\
                                ->Range(L1, L2)

#define COMPLEXITY_BENCHMARK(x, CACHE_TYPE) BENCHMARK(x)->RangeMultiplier(2)\
                                ->Range(L1, CACHE_TYPE)->Complexity()

#define COMPLEXITY_BENCHMARK_GEN(x, y, CACHE_TYPE) BENCHMARK_TEMPLATE(x, y)\
                                ->RangeMultiplier(2)->Range(L1, CACHE_TYPE)\
                                ->Complexity()
#endif // TEST_CONFIGS_H

constexpr int MSize = L2;

#if defined(__clang__)
#define COMPILER_CLANG
#elif defined(__GNUC__)
#define COMPILER_GCC
#elif defined(_MSC_VER)
#define COMPILER_MSVC
#endif

#if defined(COMPILER_GCC) || defined(COMPILER_CLANG)
#define ATTR_NOINLINE __attribute__((noinline))
#elif defined(COMPILER_MSVC)
#define ATTR_NOINLINE __declspec(noinline)
#else
#define ATTR_NOINLINE
#endif
