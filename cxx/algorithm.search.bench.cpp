#include<algorithm>
#include<set>
#include<vector>

#include "benchmark/benchmark_api.h"
#include "test_configs.h"

// TODO: Create a template class such that all the
// APIs of STL containers can be exercised in a concise way.
class BM_vector_search {
  public:
    BM_vector_search() {}
  private:
    std::vector<int> v;
};

template<typename T>
void fillVector(std::vector<T> &v) {
  //state.PauseTiming();
  // initialize.
  const unsigned N = v.size();
  for (int j = 0; j < N; ++j) {
    v[j] = j;
  }
  //state.ResumeTiming();
}

void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::vector<int> v(N);
  fillVector(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::find(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  std::vector<int> v(N);
  fillVector(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::lower_bound(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK_TEST(BM_search_linear);
COMPLEXITY_BENCHMARK_TEST(BM_search_binary);

BENCHMARK_MAIN()
