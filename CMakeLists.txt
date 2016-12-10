cmake_minimum_required(VERSION 2.8)
project(std_benchmark)


set(BENCHMARK_SRC ${CMAKE_SOURCE_DIR}/benchmark)
set(BENCHMARK_INSTALL ${CMAKE_BINARY_DIR}/benchmark)

set(COMPILE_FLAGS
  "-std=c++14 -O2 -I${BENCHMARK_SRC}/include -I${CMAKE_SOURCE_DIR}/include"
)

set(LINK_FLAGS
  # -nodefaultlibs
    "-L${BENCHMARK_INSTALL}/src/"
)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

add_subdirectory(benchmark)
add_subdirectory(cxx)
add_subdirectory(c)
