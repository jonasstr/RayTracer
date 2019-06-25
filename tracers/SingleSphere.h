#pragma once

#include "Tracer.h"

class SingleSphere : public Tracer {

public:

    SingleSphere();

    SingleSphere(Scene* worldPtr);

    Vec3 traceRay(const Ray &ray) const override;
};
