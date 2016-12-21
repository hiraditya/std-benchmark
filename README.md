A benchmark for c/c++ standard library algorithms.
Please contact me if you would like to contribute to this project.

Dependencies:
CMake 2.8 or higher
Since this is a standard library benchmark, you need a compiler toolchain to benchmark.
A C++ compiler with C++11 support
google-benchmark (added as a submodule)

To download the google-benchmark submodule run the following command in the project root.
git submodule update --recursive --remote


How to build on Windows with MSVC
Install CMake
cd build
cmake ..
cmake --build .
If there are errors then build the project by opening the visual studio IDE (devenv)
and then try to build one component at a time.
All the c benchmark do not compile with MSVC for now because of compiler incompatibilities,
but all the cxx benchmarks do compile. I need to fix c benchmarks for MSVC.
