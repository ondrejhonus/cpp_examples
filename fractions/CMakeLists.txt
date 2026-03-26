cmake_minimum_required(VERSION 3.10.0)
project(fractions VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(fractions src/main.cpp src/fraction.cpp)


