#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<deque>
#include<map>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>

// TODO: get, operator[], find, count, equal_range, erase, lower_bound, upper_bound

template<typename V>
void BM_advance(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v;
  fill_seq(v);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i) {
      auto it = v.begin();
      std::advance(it, i);
      benchmark::DoNotOptimize(it);
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_access(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v;
  fill_seq(v);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i) {
      auto it = v.begin();
      std::advance(it, i);
      benchmark::DoNotOptimize(*it);
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_at(benchmark::State& state) {
  const unsigned N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      benchmark::DoNotOptimize(v.at(i));
  }
  state.SetComplexityN(N);
}

// Insert random elements
template<typename V>
void BM_assoc_find_random(benchmark::State& state) {
  const unsigned N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  using KT = typename std::remove_const<typename V::key_type>::type;
  std::vector<KT> temp(N);
  fill_random(temp, N);
  V v;
  for (unsigned i = 0; i < N; ++i)
    v.insert(get_rand<VT>(RAND_MAX));
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i)
      benchmark::DoNotOptimize(v.find(temp[i]));
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_assoc_find_seq(benchmark::State& state) {
  const unsigned N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  using KT = typename std::remove_const<typename V::key_type>::type;
  std::vector<VT> temp(N);
  fill_seq(temp);
  V v;
  for (unsigned i = 0; i < N; ++i)
    v.insert(temp[i]);
  while (state.KeepRunning()) {
    for (unsigned i = 0; i < N; ++i) {
      auto it = v.find(i);
      benchmark::DoNotOptimize(it);
      assert (it != v.end());
    }
  }
  state.SetComplexityN(N);
}


static const int MSize = L1;
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::list<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_advance, std::deque<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_access, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_access, std::list<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_access, std::deque<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_at, std::vector<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_at, std::deque<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, std::set<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, std::unordered_set<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, SINGLE_ARG(std::map<int, int>), MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, SINGLE_ARG(std::unordered_map<int, int>), MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, std::set<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, std::unordered_set<int>, MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, SINGLE_ARG(std::map<int, int>), MSize);
COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, SINGLE_ARG(std::unordered_map<int, int>), MSize);
BENCHMARK_MAIN()
