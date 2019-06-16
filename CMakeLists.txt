cmake_minimum_required(VERSION 3.14)
project(ToyTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToyTracer
        io/ImageIO.cpp
        utils/Vec3.h
        main.cpp utils/Ray.h objects/GeometricObject.h utils/ShadeRec.h utils/Constants.h objects/primitives/Plane.cpp objects/primitives/Plane.h objects/primitives/Sphere.cpp objects/primitives/Sphere.h)

include_directories(
        io
        utils
        objects)