#include "rng_utils.h"
#include<iostream>
#include<cassert>

int main() {
  random_device r;
  for (int i = 0; i < 10000; i++) {
    auto v = r.get_rand<float>(-1, 1);
    assert(v < 1 && v > -1);
  }
}

