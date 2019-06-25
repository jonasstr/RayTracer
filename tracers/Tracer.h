#pragma once

#include "Vec3.h"
#include "Ray.h"
#include "Constants.h"

class Scene;

class Tracer {

public:

    Tracer();

    explicit Tracer(Scene *scenePtr);

    virtual ~Tracer();

    virtual Vec3 traceRay(const Ray &ray) const;

protected:

    Scene *scenePtr;
};

