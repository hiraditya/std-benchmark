set(src
  algorithm.search.bench.cpp)

set(target algorithm.search.bench.out)

#EXCLUDE_FROM_ALL
add_executable(${target} ${src})

target_link_libraries(${target} -lbenchmark -pthread)
