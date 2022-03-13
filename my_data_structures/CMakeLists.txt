cmake_minimum_required(VERSION 3.0)
project(data_structures VERSION 1.0)

# Add executable
if(TEST_QUEUE_BY_ARRAY)
  add_executable(test_queue test_queue_by_array.cpp)
  unset(TEST_QUEUE_BY_ARRAY CACHE)
elseif(TEST_QUEUE_BY_LIST)
  add_executable(test_queue test_queue_by_list.cpp)
  unset(TEST_QUEUE_BY_LIST CACHE)
endif()

# Include
target_include_directories(test_queue PUBLIC .)