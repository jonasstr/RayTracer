#pragma once

#include "Camera.h"
#include "Vec2.h"

class Pinhole : public Camera {

public:

    Pinhole();

    void render(Scene &scene) override;

    inline void setViewDistance(const float d) {
        distance = d;
    }

    inline void setZoom(const float z) {
        zoom = z;
    }

private:

    float distance; // View plane distance
    float zoom; // Zoom factor

    Vec3 getRayDirection(const Vec2 &p);
};
