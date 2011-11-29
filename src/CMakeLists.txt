cmake_minimum_required(VERSION 2.6)

project(aunf)

add_definitions(-Wall -g)

add_executable(aunf main.cpp net.cpp unf.cpp readlib.cpp readpep.cpp output.cpp)
