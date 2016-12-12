#ifndef TEST_UTILS_H
#define TEST_UTILS_H

template <template <class, class> class Container, class value_type>
void fillRandom(Container<value_type, std::allocator<value_type>> &v,
                unsigned max = RAND_MAX) {
  //state.PauseTiming();
  // initialize.
  for (auto &e : v)
    e = rand() % max;
  //state.ResumeTiming();
}

// TODO: Create a template class such that all the
// APIs of STL containers can be exercised in a concise way.
// for example insert, push_back, pop_back, push_front, pop_front, advance

// TODO: Benchmark memory allocated on heap vs. stack.

template <template <class, class> class Container, class value_type>
void fillSeq(Container<value_type, std::allocator<value_type>> &v) {
  // initialize.
  unsigned j = 0;
  for (auto &e : v)
    e = j++;
}

template <typename T>
void fillSeq(T begin, T end) {
  // initialize.
  unsigned j = 0;
  for (auto it = begin; it != end; ++it)
    *it = j++;
}

template <typename T>
void fillRandom(T begin, T end, unsigned max = RAND_MAX) {
  // initialize.
  for (auto it = begin; it != end; ++it)
    *it = rand() % max;
}

void fillRandomChars(char * begin, char * end, bool upper = true) {
  // initialize.
  char max = upper ? 'Z' : 'z';
  char min = upper ? 'a' : 'a';
  auto it = begin;
  for (; it != end -1; ++it)
    *it = rand() % (max - min + 1) + min;
  *it = '\0';
}

#endif // TEST_UTILS_H

