#include "benchmark/benchmark_api.h"
#include "test_configs.h"
#include "test_utils.h"

#include <sstream>

static inline float istream_numbers(void) {
  const char *a[] = {
    "-6 69 -71 2.4882335544453341e-02",
    "-25 71 7 -9.3262388184041552e+01",
    "14 53 46 -6.7026092077494765e-02"
  };

  int x, y, z;
  float f = 0.0, q = 0.0;
  for (int i=0; i < 1; i++) {
    std::istringstream s(a[i]);
    s >> x >> y >> z >> f;
    q += x + y + z + f;
  }
  return q;
}

static void BM_Istream_numbers(benchmark::State &state) {
  while (state.KeepRunning())
    benchmark::DoNotOptimize(istream_numbers());
}
BENCHMARK(BM_Istream_numbers);

BENCHMARK_MAIN()
