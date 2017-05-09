#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include<algorithm>
#include<deque>
#include<iterator>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>

template<typename V>
void BM_write_seq(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  while (state.KeepRunning()) {
    fill_seq(v);
    benchmark::DoNotOptimize(v);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_push_back(benchmark::State& state) {
  int N = state.range(0);
  V v;
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_push_back_resize(benchmark::State& state) {
  int N = state.range(0);
  V v(N);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_push_back_vector_reserve(benchmark::State& state) {
  int N = state.range(0);
  V v;
  v.reserve(N);
  while (state.KeepRunning()) {
    for (int i = 0; i < N; ++i)
      v.push_back(i);
  }
  state.SetComplexityN(N);
}

template<typename V>
void BM_insert_begin(benchmark::State& state) {
  int N = state.range(0);
  V v(N, 1);
  auto val = *v.begin();
  while (state.KeepRunning()) {
    v.insert(v.begin(), val);
  }
  state.SetComplexityN(N);
}

// Disable this for now for travis CI to pass until I figure out
// a way to use latest compiler on travis CI.
#if 0 && __cplusplus >= 201402L
template<typename V>
void BM_insert_middle(benchmark::State& state) {
  int N = state.range(0);
  using namespace std;
  using v_iterator = typename iterator_traits<typename V::iterator>::iterator_category;
  V v(N, 1);
  auto val = *v.begin();
  auto pos = std::next(v.begin(), N/2);
  while (state.KeepRunning()) {
    if constexpr(is_same<v_iterator, random_access_iterator_tag>::value)
      pos = std::next(v.begin(), N/2);
    v.insert(pos, val);
  }
  state.SetComplexityN(N);
}
#endif

// Insert random elements
template<typename V>
void BM_assoc_insert_random(benchmark::State& state) {
  int N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  std::vector<VT> temp(N);
  fill_random(temp);
  V v;
  auto it = temp.begin();
  while (state.KeepRunning()) {
    v.insert(*it++);
    if (it == temp.end()) // FIXME: After temp.end insert will just return.
      it = temp.begin();
  }
  state.SetComplexityN(N);
}

// Insert random elements
template<typename V>
void BM_assoc_insert_seq(benchmark::State& state) {
  int N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  std::vector<VT> temp(N);
  fill_seq(temp);
  V v;
  auto it = temp.begin();
  while (state.KeepRunning()) {
    v.insert(*it++);
    if (it == temp.end()) // FIXME: After temp.end insert will just return.
      it = temp.begin();
  }
  state.SetComplexityN(N);
}

// Insert same element over and over.
template<typename V>
void BM_assoc_insert(benchmark::State& state) {
  int N = state.range(0);
  using CVT = typename V::value_type;
  using VT = typename remove_const<CVT>::type;
  random_device r;
  VT temp = get_rand<VT>(r, N);
  V v;
  while (state.KeepRunning()) {
    v.insert(temp);
  }
  state.SetComplexityN(N);
}

/*/ Base case.
template <typename T>
void
check ()
{
}

template <typename T, typename container, typename... containers>
void
check ()
{
  COMPLEXITY_BENCHMARK_GEN(T, container, MSize);
  // Check rest of the properties.
  check<T, containers...>();
}

// All the sequence testing functors which take one argument.
#define CONTAINERS  std::vector<int>, std::list<int>

check<BM_push_back, CONTAINERS > ();*/


//std::forward_list<int> does not have push_back :(
//static const int MSize = L1;

#define BENCH_STD_MAP(T) SINGLE_ARG(std::map<T, T>)
#define BENCH_STD_UNORDERED_MAP(T) SINGLE_ARG(std::unordered_map<T, T>)

#define COMPLEXITY_BENCHMARK_GEN_T(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_write_seq, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_write_seq, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_write_seq, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back_resize, std::deque<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_push_back_vector_reserve, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_insert_begin, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_insert_begin, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_insert_begin, std::deque<T>, MSize);\
\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert, std::set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_random, std::set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_seq, std::set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert, std::unordered_set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_random, std::unordered_set<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_seq, std::unordered_set<T>, MSize);\
\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert, BENCH_STD_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_random, BENCH_STD_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_seq, BENCH_STD_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert, BENCH_STD_UNORDERED_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_random, BENCH_STD_UNORDERED_MAP(T), MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_assoc_insert_seq, BENCH_STD_UNORDERED_MAP(T), MSize);

COMPLEXITY_BENCHMARK_GEN_T(int)
COMPLEXITY_BENCHMARK_GEN_T(aggregate)

#if 0 && __cplusplus >= 201402L
#define COMPLEXITY_BENCHMARK_GEN_T_14(T) \
    COMPLEXITY_BENCHMARK_GEN(BM_insert_middle, std::vector<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_insert_middle, std::list<T>, MSize);\
    COMPLEXITY_BENCHMARK_GEN(BM_insert_middle, std::deque<T>, MSize);
COMPLEXITY_BENCHMARK_GEN_T_14(int)
COMPLEXITY_BENCHMARK_GEN_T_14(aggregate)
#endif

BENCHMARK_MAIN()
