#include<algorithm>
#include<list>
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

template <template <class, class> class Container, class value_type>
void fillSeq(Container<value_type, std::allocator<value_type>> &v) {
  //state.PauseTiming();
  // initialize.
  unsigned j = 0;
  for (auto &e : v)
    e = j++;
  //state.ResumeTiming();
}

template<typename V>
void BM_search_linear(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillSeq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::find(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_search_binary(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fillSeq(v);
  while (state.KeepRunning()) {
    // searching for all the elements.
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(std::lower_bound(v.begin(), v.end(), i));
  }
  state.SetComplexityN(N);
}

COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::vector<int>);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::vector<int>);
COMPLEXITY_BENCHMARK_GEN(BM_search_linear, std::list<int>);
COMPLEXITY_BENCHMARK_GEN(BM_search_binary, std::list<int>);

BENCHMARK_MAIN()
