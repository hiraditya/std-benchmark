#ifndef TEST_UTILS_H
#define TEST_UTILS_H

template<typename T>
struct remove_const { typedef T type; };

// value_type of a std::map is std::pair<const KeyType, ValueType>
template<typename T>
struct remove_const<std::pair<const T, T>> { typedef std::pair<T, T> type; };

template<typename T>
T getRand(int max) {
  return T(0) % max;
}

template<>
int getRand<int>(int max) {
  return rand() % max;
}

template<>
std::pair<int, int> getRand<std::pair<int, int>>(int max) {
  return std::make_pair(rand() % max, rand() % max);
}

template<typename T>
T increment(T &i) { // do-nothing
  return i;
}

// Generalize this for is_integral
template<>
int increment<int>(int &i) {
  return i++;
}

// value_type of a std::map is std::pair<const KeyType, ValueType>
template<>
std::pair<int, int> increment<std::pair<int, int>>(std::pair<int, int> &i) {
  return std::make_pair(i.first++, i.second);
}

template <template <class, class> class Container, class value_type>
void fillRandom(Container<value_type, std::allocator<value_type>> &v,
                unsigned max = RAND_MAX) {
  for (auto &e : v)
    e = getRand<value_type>(max);
}

// TODO: Create a template class such that all the
// APIs of STL containers can be exercised in a concise way.
// for example insert, push_back, pop_back, push_front, pop_front, advance

// TODO: Benchmark memory allocated on heap vs. stack.

template <template <class, class> class Container, class value_type>
void fillSeq(Container<value_type, std::allocator<value_type>> &v) {
  value_type j = getRand<value_type>(RAND_MAX);
  for (auto &e : v)
    e = increment(j);
}

template <typename T>
void fillSeq(T begin, T end) {
  typedef typename std::iterator_traits<T>::value_type value_type;
  value_type j = getRand<value_type>(RAND_MAX);
  for (auto it = begin; it != end; ++it)
    *it = increment(j);
}

template <typename T>
void fillRandom(T begin, T end, unsigned max = RAND_MAX) {
  for (auto it = begin; it != end; ++it)
    *it = rand() % max;
}

// It can work with char* or std::string.
template<typename T>
void fillRandomChars(T begin, T end, bool upper) {
  char max = upper ? 'Z' : 'z';
  char min = upper ? 'A' : 'a';
  auto it = begin;
  for (; it != end -1; ++it)
    *it = rand() % (max - min + 1) + min;
  *it = '\0';
}

#endif // TEST_UTILS_H

