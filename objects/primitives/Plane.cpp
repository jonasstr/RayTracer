#include "Plane.h"

const double Plane::kEpsilon = 0.001;

Plane::Plane(const Vec3 &point, const Vec3 &normal)
        : point(point), normal(normal) {}

bool Plane::hit(const Ray &ray, double &tMin, ShadeRec &rec) const {

    const double t = dot(point - ray.origin, normal) / dot(ray.dir, normal);

    if (t > kEpsilon) {
        tMin = t;
        rec.normal = normal;
        rec.localHitPoint = ray.pointAt(t);
        return true;
    }
    return false;
}


