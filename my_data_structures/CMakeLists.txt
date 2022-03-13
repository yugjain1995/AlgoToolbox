cmake_minimum_required(VERSION 3.0)
project(data_structures VERSION 1.0)

# Add executable
add_executable(test_queue test_queue.cpp)

# Include
target_include_directories(test_queue PUBLIC .)