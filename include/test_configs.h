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
// To benchmark data residing in L2 cache.
#define L2 (256 KB)
// To benchmark data residing in L3 cache.
#define L3 (8192 KB)
// To benchmark data residing in main memory.
#define MEMORY (12 GB)
#endif

#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(2<<5)->Arg(2<<10)\
                                ->Arg(2<<20)->Arg(2<<30)

#define COMPLEXITY_BENCHMARK(x, CACHE_TYPE) BENCHMARK(x)->RangeMultiplier(2)\
                                ->Range(1<<5, CACHE_TYPE)->Complexity();

#define COMPLEXITY_BENCHMARK_GEN(x, y, CACHE_TYPE) BENCHMARK_TEMPLATE(x, y)\
                                ->RangeMultiplier(2)->Range(1<<5, CACHE_TYPE)\
                                ->Complexity();
#endif // TEST_CONFIGS_H
