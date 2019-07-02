#pragma once

#include "Sampler.h"
#include "Camera.h"

class ThinLens : public Camera {

public:

    ThinLens();

    void render(Scene &scene) override;

    void setSampler(Sampler *sampler);

    inline void setViewDistance(const float dist) {
        d = dist;
    }

    inline void setFocalDistance(const float dist) {
        f = dist;
    }

    inline void setLensRadius(const float r) {
        lensRadius = r;
    }

    inline void setZoom(const float z) {
        zoom = z;
    }

    Vec3 getRayDirection(const Vec2 &pixelPoint, const Vec2 &lensPoint) const;

private:

    float lensRadius;
    float d; // view plane distance
    float f; // focal plane distance
    float zoom;

    Sampler *samplerPtr;
};
