#include "rng_utils.h"
#include<cassert>

template<typename T>
void test_rand(random_device &r, T min, T max, int iter = 100) {
  for (int i = 0; i < iter; i++) {
    auto v = r.get_rand<T>(min, max);
    assert(v < max && v > min);
    assert(v != max && v != min);
  }
}

template<typename T>
void rand_tests(random_device &r) {
  test_rand<T>(r, -1, 1);
  test_rand<T>(r, 0, 1);
  test_rand<T>(r, -1, 0);
  test_rand<T>(r, 0, 100);
}

int main() {
  random_device r;
  rand_tests<float>(r);
  rand_tests<double>(r);
}
