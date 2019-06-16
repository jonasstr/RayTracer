cmake_minimum_required(VERSION 3.14)
project(ToyTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToyTracer
        ImageIO.cpp
        Vec3.h
        main.cpp)
