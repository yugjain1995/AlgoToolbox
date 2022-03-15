cmake_minimum_required(VERSION 3.0)
project(data_structures VERSION 1.0)

# Add executable
if(TEST_QUEUE_BY_ARRAY)
  add_executable(test test_queue_by_array.cpp)
  unset(TEST_QUEUE_BY_ARRAY CACHE)
elseif(TEST_QUEUE_BY_LIST)
  add_executable(test test_queue_by_list.cpp)
  unset(TEST_QUEUE_BY_LIST CACHE)
elseif(TEST_BINARY_TREE)
  add_executable(test test_binary_tree.cpp)
unset(TEST_BINARY_TREE CACHE)
endif()

# Include
target_include_directories(test PUBLIC .)