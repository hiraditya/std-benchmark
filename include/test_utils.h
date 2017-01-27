#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include "rng_utils.h"
#include <cstdlib>

// TODO: Add more aggregates.
struct aggregate {
  int first;
  int second;
  int third;
  int fourth;
  aggregate() : first(0), second(0), third(0), fourth(0)
  {}
  // This is a hacky constructor for ::find on associative containers to work.
  aggregate(int i)
    : first(i), second(i), third(i), fourth(i)
  {}
  aggregate(int i, int j, int k, int l)
    : first(i), second(j), third(k), fourth(l)
  {}

  aggregate& operator++() {
    ++first;
    ++second;
    ++third;
    ++fourth;
    return *this;
  }
  aggregate operator++(int) {
    aggregate N(*this);
    ++(*this);
    return N;
  }

  bool operator<(const aggregate& i) const {
    return first < i.first;
  }

  bool operator>(const aggregate& i) const {
    return i < *this;
  }

  bool operator==(const aggregate& i) const {
    return first == i.first;
  }

  bool operator!=(const aggregate& i) const {
    return !(*this == i);
  }
};

// Hasher for aggregate data type.
namespace std {
  template <>
  struct hash<aggregate>
  {
    std::size_t operator()(const aggregate& k) const
    {
      using std::hash;
      // Hash and combine using bit-shift.
      return ((hash<int>()(k.first)
               ^ (hash<int>()(k.second) << 1)) >> 1)
               ^ (hash<int>()(k.third) << 1)
               ^ (hash<int>()(k.fourth) << 1);
    }
  };
}

template<typename T>
struct remove_const { typedef T type; };

// value_type of a std::map is std::pair<const KeyType, ValueType>
template<typename T>
struct remove_const<std::pair<const T, T>> { typedef std::pair<T, T> type; };

template<typename T>
T get_rand(random_device &r, int max) {
  return r.get_rand(T(0), T(max));
}

template<>
std::pair<int, int> get_rand<std::pair<int, int>>(random_device &r, int max) {
  return std::make_pair(r.get_rand(0, max), r.get_rand(0, max));
}

template<>
aggregate get_rand<aggregate>(random_device &r, int max) {
  return aggregate(r.get_rand(0, max));
}

template<>
std::pair<aggregate, aggregate>
get_rand<std::pair<aggregate, aggregate>>(random_device &r, int max) {
  return std::make_pair(r.get_rand(0, max), r.get_rand(0, max));
}

template<typename T>
T increment(T &i) {
  return ++i;
}

// value_type of a std::map is std::pair<const KeyType, ValueType>
template<>
std::pair<int, int> increment<std::pair<int, int>>(std::pair<int, int> &i) {
  return std::make_pair(++i.first, i.second);
}

template<>
std::pair<aggregate, aggregate>
increment<std::pair<aggregate, aggregate>>(std::pair<aggregate, aggregate> &i) {
  return std::make_pair(++i.first, i.second);
}

template<typename T>
T init() {
  return T(0);
}

template<>
std::pair<int, int> init<std::pair<int, int>>() {
  return std::make_pair(0, 0);
}

template<>
std::pair<aggregate, aggregate> init<std::pair<aggregate, aggregate>>() {
  return std::make_pair(0, 0);
}

template <template <class, class> class Container, class value_type>
void fill_random(Container<value_type, std::allocator<value_type>> &v,
                int max = RAND_MAX) {
  random_device r;
  for (auto &e : v)
    e = get_rand<value_type>(r, max);
}

template <typename T>
void fill_random(T begin, T end, int max = RAND_MAX) {
  typedef typename std::iterator_traits<T>::value_type value_type;
  random_device r;
  for (auto it = begin; it != end; ++it)
    *it = get_rand<value_type>(r, max);
}

// It can work with char* or std::string.
template<typename T>
void fill_random_chars(T begin, T end, bool upper) {
  char max = upper ? 'Z' : 'z';
  char min = upper ? 'A' : 'a';
  auto it = begin;
  typedef typename std::iterator_traits<T>::value_type value_type;
  random_device r;
  for (; it != end -1; ++it) {
    *it = get_rand<value_type>(r, max) * (max - min) + min;
    assert(*it >= min);
    assert(*it <= max);
  }
  *it = '\0';
}

// TODO: Create a template class such that all the
// APIs of STL containers can be exercised in a concise way.
// for example insert, push_back, pop_back, push_front, pop_front, advance

// TODO: Benchmark memory allocated on heap vs. stack.
template <typename T>
void fill_seq(T begin, T end) {
  typedef typename std::iterator_traits<T>::value_type value_type;
  //random_device r;
  value_type j = init<value_type>();// = get_rand<value_type>(r, RAND_MAX);
  for (auto it = begin; it != end; ++it, increment(j))
    *it = j;
}

template <template <class, class> class Container, class value_type>
void fill_seq(Container<value_type, std::allocator<value_type>> &v) {
  fill_seq(std::begin(v), std::end(v));
}

// c-style comparator for integral types.
template<typename T>
static int compare(const void *a, const void *b)
{
  static_assert(std::is_integral<T>::value, "Not an integral type.");
  return (*(T*)a - *(T*)b);
}

// Custom allocator to manage memory yet keep C like semantics
// for building C standard library benchmarks.
template<typename T>
class c_alloc {
  public:
    c_alloc(int N) : p((T*)malloc(N*sizeof(T))) {}
    ~c_alloc() { free(p); }
    // Dangerous but simple if used properly.
    T* get() { return p; }
    operator T*() { return p; }
    T* operator+(int N) { return p+N; }
    const T* operator+(int N) const { return p+N; }
    const T& operator[] (int N) const { return p[N]; }
    T& operator[] (int N) { return p[N]; }
  private:
    T* p;
};

// Call a unary function for N real numbers
#define BM_unary_real(Name) template<typename T> \
void BM_##Name(benchmark::State& state) {\
  int N = state.range(0);\
  c_alloc<T> a(N);\
  fill_random(a.get(), a.get()+N);\
  while (state.KeepRunning()) {\
    for (int i = 0; i < N; ++i) {\
      T p = Name(a[i]);\
      benchmark::DoNotOptimize(p);\
    }\
  }\
  state.SetComplexityN(N);\
}

// Call a binary function for N real numbers
#define BM_binary_real(Name) template<typename T> \
void BM_##Name(benchmark::State& state) {\
  int N = state.range(0);\
  c_alloc<T> a(N);\
  fill_random(a.get(), a.get()+N);\
  random_device r;\
  while (state.KeepRunning()) {\
    for (int i = 0; i < N; ++i) {\
      T p = Name(a[i], get_rand<int>(r, RAND_MAX));\
      benchmark::DoNotOptimize(p);\
    }\
  }\
  state.SetComplexityN(N);\
}

#endif // TEST_UTILS_H

