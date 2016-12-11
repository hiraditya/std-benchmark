#ifndef TEST_UTILS_H
#define TEST_UTILS_H

template <template <class, class> class Container, class value_type>
void fillRandom(Container<value_type, std::allocator<value_type>> &v) {
  //state.PauseTiming();
  // initialize.
  for (auto &e : v)
    e = rand();
  //state.ResumeTiming();
}

// TODO: Create a template class such that all the
// APIs of STL containers can be exercised in a concise way.
// for example insert, push_back, pop_back, push_front, pop_front, advance

template <template <class, class> class Container, class value_type>
void fillSeq(Container<value_type, std::allocator<value_type>> &v) {
  //state.PauseTiming();
  // initialize.
  unsigned j = 0;
  for (auto &e : v)
    e = j++;
  //state.ResumeTiming();
}

template <typename T>
void fillSeq(T begin, T end) {
  //state.PauseTiming();
  // initialize.
  unsigned j = 0;
  for (auto it = begin; it != end; ++it)
    *it = j++;
  //state.ResumeTiming();
}

#endif // TEST_UTILS_H

