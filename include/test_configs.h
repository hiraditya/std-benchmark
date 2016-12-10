#ifndef TEST_CONFIGS_H
#define TEST_CONFIGS_H


#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(2<<5)->Arg(2<<10)\
                                ->Arg(2<<20)->Arg(2<<30)

#define COMPLEXITY_BENCHMARK(x) BENCHMARK(x)->RangeMultiplier(2)\
                                ->Range(1<<5, 1<<12)->Complexity();

#define COMPLEXITY_BENCHMARK_GEN(x, y) BENCHMARK_TEMPLATE(x, y)\
                                ->RangeMultiplier(2)->Range(1<<5, 1<<12)\
                                ->Complexity();
#endif // TEST_CONFIGS_H
