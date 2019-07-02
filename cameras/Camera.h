#pragma once

#include "Vec3.h"

class Scene;

class Camera {

public:

    Camera();

    virtual ~Camera() = default;

    virtual void render(Scene &scene) = 0;

    inline void setPosition(const float x, const float y, const float z) {
        eye = Vec3(x, y, z);
    }

    inline void setLookAt(const float x, const float y, const float z) {
        lookAt = Vec3(x, y, z);
    }

protected:

    Vec3 eye;
    Vec3 lookAt;
    Vec3 up;

    Vec3 u, v, w; // The basis vectors for the viewing coordinate system

    float exposureTime;

public:

    void computeUVW();
};
