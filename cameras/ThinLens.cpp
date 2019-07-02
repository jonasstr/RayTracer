#include "ThinLens.h"

#include "Ray.h"
#include "Scene.h"

ThinLens::ThinLens()
        : Camera(),
          lensRadius(1.0),
          d(40),
          f(70),
          zoom(1),
          samplerPtr(nullptr) {}

void ThinLens::setSampler(Sampler *sampler) {

    if (samplerPtr) {
        delete samplerPtr;
        samplerPtr = nullptr;
    }
    samplerPtr = sampler;
    // Create samples on unit disk for later use
    samplerPtr->mapSamplesToUnitDisk();
}

void ThinLens::render(Scene &scene) {

    if (samplerPtr == nullptr) {
        std::cerr << "ThinLens::render - no sampler pointer specified!" << std::endl;
        return;
    }

    Vec2 sp{}; // Sample point on unit square
    Vec2 pp{}; // Sample pixel point
    Vec2 lp{}; // Sample point on lens

    Vec3 pixelColor{};
    Ray ray;

    scene.pixelSize /= zoom;

    for (int row = scene.vRes - 1; row >= 0; row--) {
        for (int col = 0; col < scene.hRes; col++) {
            pixelColor = black;
            for (int i = 0; i < scene.numSamples; i++) {
                // Apply per-pixel sampling
                sp = samplerPtr->nextSquareSample();
                pp.x = scene.pixelSize * (col - scene.hRes / 2.0 + sp.x);
                pp.y = scene.pixelSize * (row - scene.vRes / 2.0 + sp.y);
                // Sample point on unit disk
                lp = samplerPtr->nextDiskSample() * lensRadius;

                ray.origin = eye + lp.x * u + lp.y * v;
                ray.dir = getRayDirection(pp, lp);
                pixelColor += scene.tracerPtr->traceRay(ray);
            }
            pixelColor /= scene.numSamples;
            pixelColor *= exposureTime;
            scene.displayPixel(pixelColor);
        }
    }
}

Vec3 ThinLens::getRayDirection(const Vec2 &pixelPoint, const Vec2 &lensPoint) const {

    Vec2 p{}; // Hit point on focal plane
    p.x = pixelPoint.x * (f / d);
    p.y = pixelPoint.y * (f / d);
    Vec3 dir = (p.x - lensPoint.x) * u + (p.y - lensPoint.y) * v - f * w;
    return dir.normalize();
}
