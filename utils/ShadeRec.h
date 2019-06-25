#pragma once

#include "Vec3.h"

class Scene;
struct ShadeRec {

    bool hitAnyObject;
    Vec3 localHitPoint;
    Vec3 normal;
    Vec3 color;

    Scene* scene;

    ShadeRec(Scene* scene);
};
