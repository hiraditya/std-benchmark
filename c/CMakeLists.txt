file(GLOB BENCHMARK_TESTS "*.bench.cpp")
foreach(test_path ${BENCHMARK_TESTS})
  get_filename_component(test_file "${test_path}" NAME)
  set(target ${test_file}.c.out)
  #EXCLUDE_FROM_ALL
  add_executable(${target} ${test_file})
  target_link_libraries(${target} benchmark -pthread)
endforeach()
