cmake_minimum_required(VERSION 3.25)
project(physics)

set(CMAKE_CXX_STANDARD 20)

add_executable(physics main.cpp vec.cpp Universe.cpp Object.cpp Sphere.cpp Sphere.h Simulation.cpp Simulation.h)
