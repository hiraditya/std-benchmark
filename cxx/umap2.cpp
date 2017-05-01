#include <iostream>
#include <unordered_map> // Requires a C++11 compiler.
#include <map>
#include <sstream>
#include <sys/time.h> // gettimeofday
#include <stdlib.h> // strtol

int identity(int);

double elapsed(const timeval& tstart, const timeval& tstop)
{
return
  static_cast<double>(tstop.tv_sec  - tstart.tv_sec) +
  static_cast<double>(tstop.tv_usec - tstart.tv_usec)*1.e-6;
}

int main(int argc, char **argv)
{
  // Timing objects
  timeval tstart, tstop;

  // Possibly read number of trials from command line
  unsigned n_trials = static_cast<unsigned>(1e9);
  if (argc > 1)
    {
      double nt;
      std::stringstream ss;
      ss << argv[1];
      ss >> nt;
      n_trials = static_cast<unsigned>(nt);
    }
  std::cout << "Performing " << n_trials << " trials." << std::endl;

  // Possibly read number of map entries from command line
  unsigned N = 16;
  if (argc > 2)
    N = strtol(argv[2], NULL, 10);
  std::cout << "Containers have " << N << " entries." << std::endl;


  // Typedefs
  typedef std::map<unsigned, unsigned> MapType;
  typedef std::unordered_map<unsigned, unsigned> UnorderedMapType;

  // typedef std::multimap<unsigned, unsigned> MapType;
  // typedef std::unordered_multimap<unsigned, unsigned> UnorderedMapType;

  // The test objects
  MapType m;
  UnorderedMapType um;

  for (unsigned i=0; i<N; ++i)
    {
      m.insert(std::make_pair(i,i));
      um.insert(std::make_pair(i,i));
    }

    /*
  // 1.)
  {
    gettimeofday (&tstart, NULL);
    // We use 'dummy' to prevent clang from completely optimizing out the call to find().
    unsigned dummy = 0;
    for (unsigned trial=0; trial<n_trials; ++trial)
      {
        MapType::iterator it = m.find(N/2);
        dummy = it->first;
      }
    gettimeofday (&tstop, NULL);
    std::cout << "map::find() with a single key known to be in the map: " << elapsed(tstart, tstop) << std::endl;
  }
  */

  // 2.)
  {
    gettimeofday (&tstart, NULL);
    // We use 'dummy' to prevent clang from completely optimizing out the call to find().
    volatile unsigned dummy = 0;
    const int key2 = N / 2;
    for (unsigned trial=0; trial<n_trials; ++trial)
      {
        const int key = identity(key2);
        UnorderedMapType::iterator it = um.find(key);
        dummy += it->first;
      }
    gettimeofday (&tstop, NULL);
    std::cout << "unordered_map::find() with a single key known to be in the map: " << elapsed(tstart, tstop) << std::endl;
    std::cout << "Found " << dummy << std::endl;
  }

  return 0;
}
