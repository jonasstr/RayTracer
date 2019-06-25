#include "ImageIO.h"
#include "Ray.h"
#include "Scene.h"

void Scene::render(const std::string &outputPath) {

    // Call setUp() method implemented in subclasses.
    setUp();
    ImageIO img(outputPath, hRes, vRes);

    Vec3 pixelColor;
    Ray ray;
    double x, y;
    const float zw = 100.0;
    ray.dir = Vec3(0, 0, -1);

    for (int row = vRes - 1; row >= 0; row--) {
        for (int col = 0; col < hRes; col++) {

            x = pixelSize * (col - 0.5 * (hRes - 1.0));
            y = pixelSize * (row - 0.5 * (vRes - 1.0));
            ray.origin = Vec3(x, y, zw);
            pixelColor = tracerPtr->traceRay(ray);
            img.setPixel(pixelColor);
        }
    }
    img.open();
}