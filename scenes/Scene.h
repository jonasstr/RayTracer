#pragma once

#include "ImageIO.h"

#include "Sampler.h"
#include "Tracer.h"
#include "Sphere.h"

#include "Camera.h"

class Scene {

public:

    explicit Scene(const std::string &outputPath);

    int hRes; // Screen width
    int vRes; // Screen height
    float pixelSize;

    int numSamples;
    int gamma;

    Vec3 backgroundColor;

    Tracer *tracerPtr;
    Sampler *samplerPtr;
    std::vector<GeometricObject *> objects;
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

    void render();

    void displayPixel(const Vec3 &pixelColor);

    void setSampler(Sampler *sampler);

    void setSamples(int samples);

    void setCamera(Camera* camera);

protected:

    /**
     * Initialize scene-specific variables in subclasses.
     */
    virtual void setUp() = 0;

private:

    ImageIO img;
    Camera *cameraPtr{};
};

