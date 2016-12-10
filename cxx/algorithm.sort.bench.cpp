#include<algorithm>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"

template<typename T>
void fillVectorRandom(std::vector<T> &v) {
  //state.PauseTiming();
  // initialize.
  const unsigned N = v.size();
  for (int j = 0; j < N; ++j) {
    v[j] = rand();
  }
  //state.ResumeTiming();
}

void BM_sort_std(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::vector<int> v(N);
  fillVectorRandom(v);
  while (state.KeepRunning()) {
    std::sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}

void BM_sort_stable(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::vector<int> v(N);
  fillVectorRandom(v);
  while (state.KeepRunning()) {
    std::stable_sort(v.begin(), v.end());
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK_TEST(BM_sort_std);
COMPLEXITY_BENCHMARK_TEST(BM_sort_stable);

BENCHMARK_MAIN()

