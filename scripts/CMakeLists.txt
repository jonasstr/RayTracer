cmake_minimum_required(VERSION 3.14)
project(ToyTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToyTracer
        main.cpp)

include_directories(
        io
        utils
        objects
        scenes
        samplers
        tracers
        vendor)