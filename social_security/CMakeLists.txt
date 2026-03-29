cmake_minimum_required(VERSION 3.10.0)
project(social_security VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

add_executable(social_security src/main.cpp src/person.cpp)

