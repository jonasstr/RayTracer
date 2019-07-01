#include "Pinhole.h"

#include "Constants.h"
#include "Ray.h"
#include "Scene.h"

Pinhole::Pinhole()
        : Camera(),
          distance(500),
          zoom(1) {}

void Pinhole::render(Scene &scene) {

    Vec2 sampleUnitPoint{}; // Sample point on the unit square
    Vec2 p{}; // Sample point on a pixel
    Vec3 pixelColor{};
    Ray ray;

    scene.pixelSize /= zoom;
    ray.origin = eye;

    for (int row = scene.vRes - 1; row >= 0; row--) {
        for (int col = 0; col < scene.hRes; col++) {
            pixelColor = black;
            // Apply per-pixel sampling
            for (int i = 0; i < scene.numSamples; i++) {
                sampleUnitPoint = scene.samplerPtr->nextSquareSample();
                p.x = scene.pixelSize * (col - 0.5 * scene.hRes + sampleUnitPoint.x);
                p.y = scene.pixelSize * (row - 0.5 * scene.vRes + sampleUnitPoint.y);
                ray.dir = getRayDirection(p);
                pixelColor += scene.tracerPtr->traceRay(ray);
            }
            // Average the colors
            pixelColor /= scene.numSamples;
            pixelColor *= exposureTime;
            scene.displayPixel(pixelColor);
        }
    }
}

Vec3 Pinhole::getRayDirection(const Vec2 &p) {
    Vec3 dir = Vec3(p.x * u + p.y * v - distance * w);
    return dir.normalize();
}
