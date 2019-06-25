#pragma once

#include <vector>

#include "Tracer.h"
#include "primitives/Sphere.h"

class Scene {

public:

    int hRes; // Screen width
    int vRes; // Screen height
    float pixelSize;
    int gamma;

    Vec3 backgroundColor;
    Tracer *tracerPtr;
    std::vector<GeometricObject*> objects;

    Sphere sphere;

    ~Scene() {
        delete tracerPtr;
    };

    inline void addObject(GeometricObject *objectPtr) {
        objects.push_back(objectPtr);
    };

    /**
     * Intersects a ray with all objects in the scene and retrieves
     * information about the nearest hit with any object.
     *
     * @param ray the ray to intersect the objects with
     * @return the information about the nearest hit
     */
    ShadeRec hitNearest(const Ray &ray);

    void render(const std::string &outputPath);

protected:

    /**
     * Initialize scene-specific variables in subclasses.
     */
    virtual void setUp() = 0;
};

