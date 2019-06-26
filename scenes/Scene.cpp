#include <Regular.h>
#include <Jittered.h>
#include "ImageIO.h"
#include "Ray.h"
#include "Scene.h"

void Scene::render(const std::string &outputPath) {

    // Call setUp() method implemented in subclasses.
    setUp();
    if (tracerPtr == nullptr) {
        std::cerr << "No tracer pointer specified, exiting!" << std::endl;
        return;
    }

    ImageIO img(outputPath, hRes, vRes);

    Vec2 sampleUnitPoint{}; // Sample point on the unit square.
    double x, y;
    const float zw = 100.0;
    Vec3 pixelColor{};

    Ray ray;
    ray.dir = Vec3(0, 0, -1);

    for (int row = vRes - 1; row >= 0; row--) {
        for (int col = 0; col < hRes; col++) {
            pixelColor = black;
            // Apply per-pixel sampling.
            for (int i = 0; i < numSamples; i++) {
                sampleUnitPoint = samplerPtr->nextSample();
                x = pixelSize * (col - 0.5 * hRes + sampleUnitPoint.x);
                y = pixelSize * (row - 0.5 * vRes + sampleUnitPoint.y);
                ray.origin = Vec3(x, y, zw);
                pixelColor += tracerPtr->traceRay(ray);
            }
            // Average the colors.
            pixelColor /= numSamples;
            img.setPixel(pixelColor);
        }
    }
    img.open();
}

ShadeRec Scene::hitNearest(const Ray &ray) {

    ShadeRec rec(*this);
    double t;
    double tMin = kInfinity;
    const int numObjects = objects.size();

    for (int i = 0; i < numObjects; i++) {
        if (objects[i]->hit(ray, t, rec) && (t < tMin)) {
            rec.hitAnyObject = true;
            tMin = t;
            rec.color = objects[i]->getColor();
        }
    }
    return rec;
}

void Scene::setSampler(Sampler *sampler) {

    if (samplerPtr) {
        delete samplerPtr;
        samplerPtr = nullptr;
    }
    numSamples = sampler->getNumSamples();
    samplerPtr = sampler;
}

void Scene::setSamples(const int samples) {

    if (samplerPtr) {
        delete samplerPtr;
        samplerPtr = nullptr;
    }

    numSamples = samples;
    if (numSamples > 1) {
        samplerPtr = new Jittered(numSamples);
    } else {
        samplerPtr = new Regular(1);
    }
}


