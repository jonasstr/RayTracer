#pragma once

#include "Tracer.h"

class MultiObjects : public Tracer {

public:

    explicit MultiObjects(Scene* worldPtr);

    Vec3 traceRay(const Ray &ray) const override;
};

