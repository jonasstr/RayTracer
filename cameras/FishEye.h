#pragma once

#include <Vec2.h>
#include "Camera.h"

class FishEye : public Camera {

public:

    FishEye();

    void render(Scene &scene) override;

private:

    Vec3 getRayDirection(const Vec2 &p, int hRes, int vRes, float pixelSize, float rSquared);

    float psiMax; // in degrees
};