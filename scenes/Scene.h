#pragma once

#include "Tracer.h"
#include "primitives/Sphere.h"

class Scene {

public:

    ~Scene() {
        delete tracerPtr;
    };

    void render(const std::string &outputPath);

protected:

    /**
     * Initialize scene-specific variables in subclasses.
     */
    virtual void setUp() = 0;

public:

    int hRes; // Screen width
    int vRes; // Screen height
    float pixelSize;
    int gamma;

    Vec3 backgroundColor;
    Tracer* tracerPtr;

    Sphere sphere;
};

