#include<algorithm>
#include<set>

#include "benchmark/benchmark_api.h"

#define BASIC_BENCHMARK_TEST(x) BENCHMARK(x)->Arg(2<<5)->Arg(2<<10)\
                                ->Arg(2<<20)->Arg(2<<30)

#define COMPLEXITY_BENCHMARK_TEST(x) BENCHMARK(x)->RangeMultiplier(2)->Range(1<<10, 1<<16)->Complexity();

class BM_vector_search {
  public:
    BM_vector_search() {}
  private:
    std::vector<int> v;
};

void BM_search(benchmark::State& state) {
  std::vector<int> v;
  while (state.KeepRunning()) {
    //state.PauseTiming(); state.ResumeTiming();
    for (int j = 0; j < state.range(0); ++j) {
      v.push_back(j);
      //benchmark::DoNotOptimize(j);
    }
  }
  state.SetComplexityN(state.range(0));
}

//BASIC_BENCHMARK_TEST(BM_search);
COMPLEXITY_BENCHMARK_TEST(BM_search);

BENCHMARK_MAIN()
