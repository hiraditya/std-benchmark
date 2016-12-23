cmake_minimum_required(VERSION 2.8)
project(std_benchmark)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "In-source builds are not allowed.
  Please remove/comment this line to build in-source")
endif()

set(GOOGLE_BENCHMARK_SRC ${CMAKE_SOURCE_DIR}/benchmark)
set(BENCHMARK_INSTALL ${CMAKE_BINARY_DIR}/benchmark)
set(STD_BENCHMARK_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(COMPILE_FLAGS
  "-std=c++14 -O3 -I${GOOGLE_BENCHMARK_SRC}/include -I${STD_BENCHMARK_INCLUDE_DIR}")

# -fno-omit-frame-pointer

set(LINK_FLAGS
  # -nodefaultlibs
    "-L${BENCHMARK_INSTALL}/src/")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

# Google benchmark is build as Debug by default.
SET(CMAKE_BUILD_TYPE "Release")

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(benchmark)

option(ENABLE_C_BENCHMARKS "Compile C benchmarks" ON)
option(ENABLE_CXX_BENCHMARKS "Compile C++ benchmarks" ON)

enable_testing()

if(ENABLE_C_BENCHMARKS)
  add_subdirectory(c)
endif()

if(ENABLE_CXX_BENCHMARKS)
  add_subdirectory(cxx)
endif()

# Only for testing utility functions written for the std-benchmark.
add_subdirectory(test EXCLUDE_FROM_ALL)
