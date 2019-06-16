#pragma once

#include "Vec3.h"

struct ShadeRec {

    bool hitAnyObject;
    Vec3 localHitPoint;
    Vec3 normal;
    Vec3 color;
    //World& world;

    ShadeRec(World &world);
};
