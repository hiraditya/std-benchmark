#include <algorithm> // std::max
#include <array>
#include <cassert>
#include <cmath>     // std::fmax
#include <ctime>
#include <iostream>

#ifndef FUNC
#error Define FUNC to be either max or fmax!
#endif

int
main(int argc, char *argv[]) {
  size_t static const numEntries = 30000;
  size_t static const runs = 10;

  if (argc != 2) {
    std::cout << "error: Please pass an integer to the executable"
              << std::endl;
    std::exit(1);
  }
  // Make sure the loop cannot be optimised away
  int const arg = std::stoi(argv[1]);

  for (size_t k = 0; k < runs; ++k) {
    double res = 0;
    srand(arg + k);
    std::array<double, numEntries> a;
    for (size_t i=0; i < numEntries; ++i) {
      a[i] = (double)rand() / RAND_MAX;
    }

    clock_t const begin = clock();
    double y = 0;
    for (size_t i = k; i < numEntries - runs + k; ++i) {
      double x = 0;
      for (size_t j = 0; j <= i; j+=arg)
        x = std::FUNC(x, a[j]);
      y += x;
    }
    clock_t const end = clock();

    double const elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout << elapsed_secs << " (result = " << y << ")" << std::endl;
  }
}

