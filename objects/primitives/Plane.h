#pragma once

#include "GeometricObject.h"

class Plane : public GeometricObject {

public:

    Plane(const Vec3 &point, const Vec3 &normal);

    bool hit(const Ray &ray, double &tMin, ShadeRec &rec) const override;

private:

    const Vec3 point; // Point through which plane passes.
    const Vec3 normal; // Normal to the plane.

    static const double kEpsilon; // For shadows and secondary rays.
};

