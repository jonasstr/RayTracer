#include "Regular.h"
#include "Jittered.h"
#include "Scene.h"

Scene::Scene(const std::string &outputPath)
        : img(outputPath),
          hRes(200),
          vRes(200),
          pixelSize(1.0),
          gamma(1),
          backgroundColor(black),
          numSamples(1),
          tracerPtr(nullptr),
          samplerPtr(nullptr) {}

void Scene::render() {

    // Call setUp() method implemented in subclasses.
    setUp();
    if (tracerPtr == nullptr) {
        std::cerr << "No tracer pointer specified, exiting!" << std::endl;
        return;
    }
    if (samplerPtr == nullptr) {
        std::cerr << "No sampler pointer specified, exiting!" << std::endl;
        return;
    }
    if (cameraPtr == nullptr) {
        std::cerr << "No camera pointer specified, exiting!" << std::endl;
        return;
    }

    img.setDimensions(vRes, hRes);
    cameraPtr->render(*this);
    img.open();
}

void Scene::displayPixel(const Vec3 &pixelColor) {
    img.setPixel(pixelColor);
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

void Scene::setCamera(Camera *camera) {

    if (samplerPtr) {
        delete samplerPtr;
        samplerPtr = nullptr;
    }
    cameraPtr = camera;
    cameraPtr->computeUVW();
}
