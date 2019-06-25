#pragma once

#include "GeometricObject.h"
#include "Constants.h"

class Sphere : public GeometricObject {

public:

    Sphere();

    Sphere(const Vec3 &center, double radius);

    bool hit(const Ray &ray, double &tMin, ShadeRec &rec) const override;

    inline void setCenter(Vec3 c) { center = c; };

    inline void setRadius(double r) { radius = r; };

private:

    Vec3 center;
    double radius;
};
