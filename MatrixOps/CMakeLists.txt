cmake_minimum_required(VERSION 3.0)
project(Matrix)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(test main.cpp)
target_link_libraries (test Eigen3::Eigen)