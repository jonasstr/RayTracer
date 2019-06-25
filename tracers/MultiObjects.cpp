#include "MultiObjects.h"

#include "ShadeRec.h"
#include "Scene.h"

MultiObjects::MultiObjects(Scene *scenePtr) :
        Tracer(scenePtr) {}

Vec3 MultiObjects::traceRay(const Ray &ray) const {

    ShadeRec rec(scenePtr->hitNearest(ray));

    if (rec.hitAnyObject) {
        return rec.color;
    } else {
        return scenePtr->backgroundColor;
    }
}
