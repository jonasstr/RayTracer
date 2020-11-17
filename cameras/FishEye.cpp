#include "Constants.h"
#include "Ray.h"
#include "FishEye.h"
#include "Scene.h"

FishEye::FishEye()
        : Camera(),
          psiMax(120) {}

void FishEye::render(Scene &scene) {

    Vec2 sampleUnitPoint{}; // Sample point on the unit square
    Vec2 p{}; // Sample point on a pixel
    Vec3 pixelColor{};
    Ray ray;

    float rSquared = 0; // Sum of squares of normalized device coordinates
    const int vRes = scene.vRes;
    const int hRes = scene.hRes;
    const float pixelSize = scene.pixelSize;
    ray.origin = eye;

    for (int row = scene.vRes - 1; row >= 0; row--) {
        for (int col = 0; col < scene.hRes; col++) {
            pixelColor = black;
            // Apply per-pixel sampling
            for (int i = 0; i < scene.numSamples; i++) {
                sampleUnitPoint = scene.samplerPtr->nextSquareSample();
                p.x = pixelSize * (col - 0.5 * hRes + sampleUnitPoint.x);
                p.y = pixelSize * (row - 0.5 * vRes + sampleUnitPoint.y);
                ray.dir = getRayDirection(p, hRes, vRes, pixelSize, rSquared);

                if (rSquared <= 1.0)
                    pixelColor += scene.tracerPtr->traceRay(ray);
            }
            pixelColor /= scene.numSamples;
            pixelColor *= exposureTime;
            scene.displayPixel(pixelColor);
        }
    }
}

Vec3 FishEye::getRayDirection(const Vec2 &p, const int hRes, const int vRes, const float pixelSize,
                              float rSquared) {

    Vec2 pn(2.0 / (pixelSize * hRes) * p.x, 2.0 / (pixelSize * vRes) * p.y);
    rSquared = pn.x * pn.x + pn.y * pn.y;

    if (rSquared <= 1.0) {
        float r = sqrt(rSquared);
        float psi = r * psiMax * PI_OVER_180;
        float sinPsi = sin(psi);
        float cosPsi = cos(psi);
        float sinAlpha = pn.y / r;
        float cosAlpha = pn.x / r;
        return (sinPsi * cosAlpha * u + sinPsi * sinAlpha * v - cosPsi * w);
    }
    return Vec3(0);
}
