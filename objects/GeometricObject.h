#pragma once

#include "ShadeRec.h"
#include "Ray.h"

class GeometricObject {

public:

    /**
     * Computes the intersection between a ray and an object.
     *
     * @param ray the ray to use to compute a possible intersection
     * @param tMin the ray parameter t for the nearest hit point (if any)
     * @param rec information required for shading
     * @return whether the ray hits the object
     */
    virtual bool hit(const Ray &ray, double &tMin, ShadeRec &rec) const = 0;

    inline Vec3 getColor() const {
        return color;
    };

    inline void setColor(Vec3 c) {
        color = c;
    }

private:

    Vec3 color;
};
