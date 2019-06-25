cmake_minimum_required(VERSION 3.14)
project(ToyTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToyTracer
        io/ImageIO.h
        utils/Vec3.h
        utils/Ray.h
        utils/ShadeRec.h
        utils/ShadeRec.cpp
        utils/Constants.h
        objects/GeometricObject.h
        objects/primitives/Plane.cpp
        objects/primitives/Plane.h
        objects/primitives/Sphere.cpp
        objects/primitives/Sphere.h
        tracers/Tracer.cpp
        tracers/Tracer.h
        tracers/SingleSphere.cpp
        scenes/Scene.cpp
        scenes/Scene.h
        scenes/RedSphereScene.cpp
        scenes/MultiObjectsScene.cpp
        tracers/SingleSphere.h
        tracers/MultiObjects.cpp
        tracers/MultiObjects.h
        main.cpp)

include_directories(
        io
        utils
        objects
        scenes
        tracers)