#include "Sphere.h"

const double Sphere::kEpsilon = 0.001;

Sphere::Sphere()
        : radius(0) {};

Sphere::Sphere(const Vec3 &center, double radius)
        : center(center), radius(radius) {}

bool Sphere::hit(const Ray &ray, double &tMin, ShadeRec &rec) const {

    const Vec3 oc = ray.origin - center;
    const double a = dot(ray.dir, ray.dir);
    const double b = dot(2 * oc, ray.dir);
    const double c = dot(oc, oc) - radius * radius;
    const double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0.0) {
        // Quadratic function has no real solution.
        return false;
    } else {

        double t;
        const double root = sqrt(discriminant);
        const double denominator = 2.0 * a;

        t = (-b - root) / denominator; // Smaller root (-b - ...).
        if (t > kEpsilon) {
            tMin = t;
            rec.normal = (oc + t * ray.dir) / radius;
            rec.localHitPoint = ray.pointAt(t);
            return true;
        }

        t = (-b + root) / denominator; // Larger root (-b + ...).
        if (t > kEpsilon) {
            tMin = t;
            rec.normal = (oc + t * ray.dir) / radius;
            rec.localHitPoint = ray.pointAt(t);
            return true;
        }
    }
    return false;
}
