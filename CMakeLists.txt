cmake_minimum_required(VERSION 2.8)
project(std_benchmark)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "In-source builds are not allowed.
  Please remove/comment this line to build in-source")
endif()

set(GOOGLE_BENCHMARK_SRC ${CMAKE_SOURCE_DIR}/benchmark)
set(BENCHMARK_INSTALL ${CMAKE_BINARY_DIR}/benchmark)
set(STD_BENCHMARK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set(COMPILE_FLAGS
    "-std=c++11 -g3 -I${GOOGLE_BENCHMARK_SRC}/include -I${STD_BENCHMARK_INCLUDE_DIR}")
else()
  # Google benchmark is build as Debug by default.
  set(CMAKE_BUILD_TYPE "Release")
  set(COMPILE_FLAGS
    "-std=c++11 -I${GOOGLE_BENCHMARK_SRC}/include -I${STD_BENCHMARK_INCLUDE_DIR}")
endif()

if (BENCHMARK_USE_LIBCXX)
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
   set(COMPILE_FLAGS "${COMPILE_FLAGS} -stdlib=libc++")
  else()
    message(FATAL "-DBENCHMARK_USE_LIBCXX:BOOL=ON is not supported for compiler")
  endif()
endif(BENCHMARK_USE_LIBCXX)

if (MSVC)
  add_compile_options("$<$<CONFIG:DEBUG>:/MDd>")
  add_compile_options("$<$<CONFIG:RELEASE>:/O2>")
endif()

# -fno-omit-frame-pointer

set(LINK_FLAGS
  # -nodefaultlibs
    "-L${BENCHMARK_INSTALL}/src/")

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(benchmark)

# Set these after adding benchmark because google-bechmark
# fails with C++ standard greater than 2003
#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_C_BENCHMARKS "Compile C benchmarks" ON)
option(ENABLE_CXX_BENCHMARKS "Compile C++ benchmarks" ON)
option(ENABLE_C_VS_CXX_BENCHMARKS "Compile C vs C++ benchmarks" ON)
option(ENABLE_COMPILER_VS_PROGRAMMER "Compile C vs C++ benchmarks" ON)

enable_testing()

if (TRAVIS_BUILD)
  add_definitions(-DENABLE_TRAVIS_BUILD)
endif()

if(ENABLE_C_BENCHMARKS)
  add_subdirectory(c)
endif()

if(ENABLE_CXX_BENCHMARKS)
  add_subdirectory(cxx)
endif()

if(ENABLE_C_VS_CXX_BENCHMARKS)
  add_subdirectory(c.vs.cxx)
endif()

if(ENABLE_COMPILER_VS_PROGRAMMER)
  add_subdirectory(compiler.vs.programmer)
endif()

# Only for testing utility functions written for the std-benchmark.
add_subdirectory(test EXCLUDE_FROM_ALL)
