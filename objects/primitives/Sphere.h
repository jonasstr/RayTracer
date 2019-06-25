#pragma once

#include "GeometricObject.h"

class Sphere : public GeometricObject {

public:

    Sphere();

    Sphere(const Vec3 &center, double radius);

    bool hit(const Ray &ray, double &tMin, ShadeRec &rec) const override;

private:

    Vec3 center;
    double radius;

    static const double kEpsilon;

public:

    inline void setCenter(Vec3 c) { center = c; };

    inline void setRadius(double r) { radius = r; };
};
