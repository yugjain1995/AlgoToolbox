cmake_minimum_required( VERSION 2.8 )
project( binary_search )


# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MaxSumOfTwoDigits library
add_subdirectory(src)

add_executable(test test.cpp)

target_link_libraries(test PUBLIC Search_algo)

message(STATUS "Build directory - ${PROJECT_BINARY_DIR}") # Print directory where build files are stored

target_include_directories(test PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src")
