#include "SingleSphere.h"

#include "ShadeRec.h"
#include "Scene.h"

SingleSphere::SingleSphere(Scene *scenePtr)
        : Tracer(scenePtr) {}

Vec3 SingleSphere::traceRay(const Ray &ray) const {

    ShadeRec rec(*scenePtr);
    double t;

    if (scenePtr->sphere.hit(ray, t, rec)) {
        return red;
    } else {
        return black;
    }
}
