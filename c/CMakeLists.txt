set(src
  algorithm.search.bench.cpp)

set(BENCHMARK_SRC ${CMAKE_SOURCE_DIR}/benchmark)
set(BENCHMARK_INSTALL ${CMAKE_BINARY_DIR}/benchmark)

set(COMPILE_FLAGS
  "-std=c++14 -O2 -I${BENCHMARK_SRC}/include"
)

set(LINK_FLAGS
  # -nodefaultlibs
    "-L${BENCHMARK_INSTALL}/src/"
)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

set(target algorithm.search.bench.c.out)

add_executable(${target} EXCLUDE_FROM_ALL ${src})

target_link_libraries(${target} -lbenchmark -pthread)
