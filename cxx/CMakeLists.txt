set(src
  algorithm.search.bench.cpp)

set(target algorithm.search.bench.out)

add_executable(${target} EXCLUDE_FROM_ALL ${src})

target_link_libraries(${target} -lbenchmark -pthread)
