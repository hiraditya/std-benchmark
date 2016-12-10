#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(2<<5)->Arg(2<<10)\
                                ->Arg(2<<20)->Arg(2<<30)

#define COMPLEXITY_BENCHMARK_TEST(x) BENCHMARK(x)->RangeMultiplier(2)->Range(1<<10, 1<<16)->Complexity();
