#include<algorithm>
#include<set>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"

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

COMPLEXITY_BENCHMARK_TEST(BM_search);

BENCHMARK_MAIN()
