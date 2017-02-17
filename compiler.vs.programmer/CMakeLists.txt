file(GLOB BENCHMARK_TESTS "*.bench.cpp")
foreach(test_path ${BENCHMARK_TESTS})
  get_filename_component(test_file "${test_path}" NAME)
  set(target ${test_file}.out)
  #EXCLUDE_FROM_ALL
  add_executable(${target} ${test_file})
  # shlwapi for MSVC
  #target_link_libraries(${target} benchmark -pthread shlwapi)
  target_link_libraries(${target} benchmark -pthread)
  # TODO: Rename test targets different from executables.
  add_test (NAME ${target} COMMAND ${target})
  set_tests_properties(${target} PROPERTIES LABELS "compiler.vs.programmer")
endforeach()
