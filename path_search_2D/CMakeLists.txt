cmake_minimum_required(VERSION 3.0.2)

project(path_search_2D)

include_directories(path_search_2D .)
add_executable(path_search_2D main.cpp path_search_2D.cpp create_map.cpp)
