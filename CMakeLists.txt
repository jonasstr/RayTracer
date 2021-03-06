cmake_minimum_required(VERSION 3.14)
project(ToyTracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ToyTracer
        io/ImageIO.h
        utils/Vec2.h
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
        scenes/SpheresScene.cpp
        scenes/MultiObjectsScene.cpp
        scenes/SamplerScene.cpp
        tracers/SingleSphere.h
        tracers/MultiObjects.cpp
        tracers/MultiObjects.h
        samplers/Sampler.cpp
        samplers/Sampler.h
        samplers/Jittered.cpp
        samplers/Jittered.h
        samplers/Regular.cpp
        samplers/Regular.h
        samplers/NRooks.cpp
        samplers/NRooks.h
        main.cpp cameras/Camera.cpp cameras/Camera.h cameras/Pinhole.cpp cameras/Pinhole.h cameras/ThinLens.cpp cameras/ThinLens.h scenes/LensScene.cpp samplers/Random.cpp samplers/Random.h samplers/MultiJittered.cpp samplers/MultiJittered.h cameras/FishEye.cpp cameras/FishEye.h scenes/FishEyeScene.cpp)

include_directories(
        io
        utils
        objects
        objects/primitives
        scenes
        samplers
        tracers
        cameras
        vendor)