#pragma once

#include "Tracer.h"

class MultiObjects : public Tracer {

public:

    MultiObjects() = default;

    explicit MultiObjects(Scene* worldPtr);

    Vec3 traceRay(const Ray &ray) const override;
};

