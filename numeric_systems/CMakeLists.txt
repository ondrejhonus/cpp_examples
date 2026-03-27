cmake_minimum_required(VERSION 3.10.0)
project(numeric_systems VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(numeric_systems src/main.cpp src/system.cpp)

