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

// TODO: get, operator[], count, equal_range, erase, lower_bound, upper_bound

template<typename V>
void BM_advance(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i) {
      auto it = v.begin();
      std::advance(it, i);
      benchmark::DoNotOptimize(it);
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_access(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i) {
      auto it = v.begin();
      std::advance(it, i);
      benchmark::DoNotOptimize(*it);
    }
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_at(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  fill_seq(v);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(v.at(i));
  }
  state.SetComplexityN(N);
}

// Insert random elements
template<typename V>
void BM_assoc_find_random(benchmark::State& state) {
  int N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  using KT = typename std::remove_const<typename V::key_type>::type;
  std::vector<KT> temp(N);
  fill_random(temp, N);
  V v;
  random_device r;
  for (int i = 0; i < N; ++i)
    v.insert(get_rand<VT>(r, RAND_MAX));
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i)
      benchmark::DoNotOptimize(v.find(temp[i]));
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_assoc_find_seq(benchmark::State& state) {
  int N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  using KT = typename std::remove_const<typename V::key_type>::type;
  std::vector<VT> temp(N);
  fill_seq(temp);
  V v;
  for (int i = 0; i < N; ++i)
    v.insert(temp[i]);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i) {
      auto it = v.find(i);
      benchmark::DoNotOptimize(it);
      assert (it != v.end());
    }
  }
  state.SetComplexityN(N);
}

static const int MSize = L1;

#define BENCH_STD_MAP(T) SINGLE_ARG(std::map<T, T>)
#define BENCH_STD_UNORDERED_MAP(T) SINGLE_ARG(std::unordered_map<T, T>)

#define COMPLEXITY_BENCHMARK_GEN_T(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_advance, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_advance, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_advance, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_access, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_access, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_access, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_at, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_at, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, std::set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, std::unordered_set<T>, MSize);\
\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, BENCH_STD_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_random, BENCH_STD_UNORDERED_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, std::set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, std::unordered_set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, BENCH_STD_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_find_seq, BENCH_STD_UNORDERED_MAP(T), MSize);

COMPLEXITY_BENCHMARK_GEN_T(int)
COMPLEXITY_BENCHMARK_GEN_T(aggregate)

BENCHMARK_MAIN()
