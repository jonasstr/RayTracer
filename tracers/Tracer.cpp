#include "Tracer.h"

Tracer::Tracer()
        : scenePtr(nullptr) {}

Tracer::Tracer(Scene *scenePtr)
        : scenePtr(scenePtr) {}

Tracer::~Tracer() {
    if (scenePtr) {
        scenePtr = nullptr;
    }
}

Vec3 Tracer::traceRay(const Ray &ray) const {
    return black;
}
