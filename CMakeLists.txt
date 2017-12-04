cmake_minimum_required(VERSION 3.9)
project(MapQuest)

set(CMAKE_CXX_STANDARD 11)

add_executable(MapQuest Digraph.hpp test_dijkstra.cpp Digraph.cpp)