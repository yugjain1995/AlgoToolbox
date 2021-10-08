cmake_minimum_required( VERSION 2.8 )
project( max_sum_of_two_digits )


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MaxSumOfTwoDigits library
add_subdirectory(MaxSumOfTwoDigits)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC MaxSumOfTwoDigits)

message(STATUS "Build directory - ${PROJECT_BINARY_DIR}") # Print directory where build files are stored

target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/MaxSumOfTwoDigits")
