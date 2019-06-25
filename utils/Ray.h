#pragma once

#include "Vec3.h"

class Ray {

public:

    Ray() {}

    Ray(const Vec3 &origin, const Vec3 &direction)
            : origin(origin), dir(direction) {}

    Vec3 pointAt(float t) const {
        return origin + t * dir;
    }

    Vec3 origin;
    Vec3 dir;
};
