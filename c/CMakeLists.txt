set(src
  algorithm.search.bench.cpp)

set(target algorithm.search.bench.c.out)

add_executable(${target} ${src})
target_link_libraries(${target} -lbenchmark -pthread)
