A benchmark for c/c++ standard library.

**DEPENDENCIES**
- CMake 2.8 or higher
- Since this is a standard library benchmark, you need a compiler toolchain to benchmark.
- A C++ compiler with C++11 support
- google-benchmark (added as a submodule)
        To download the google-benchmark submodule run the following command in the project root.
        `git submodule update --recursive --remote`

**BUILDING ON LINUX, MAC**
```sh
mkdir $SRC/build
cd $SRC/build
cmake ..
cmake --build .
```

**BUILDING WITH VISUAL STUDIO**
```sh
mkdir $SRC/build
cd $SRC/build
cmake ..
cmake --build .
```

If there are errors then build the project by opening the visual studio IDE (devenv)
and then try to build one component at a time.
All the c benchmark do not compile with MSVC for now because of compiler incompatibilities,
but all the cxx benchmarks do compile. I need to fix c benchmarks for MSVC.

**TESTING**

To test the project run ctest. Running ctest will run the google-benchmark harness tests
as well, so if you are only interested in runningthe c and cxx std-benchmark tests use:

```sh
ctest -L c
ctest -L cxx
```
