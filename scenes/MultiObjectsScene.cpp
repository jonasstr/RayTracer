#include "Scene.h"

#include "MultiObjects.h"
#include "primitives/Plane.h"

class MultiObjectsScene : public Scene {

protected:

    void setUp() override {

        hRes = 200;
        vRes = 200;
        pixelSize = 1.0;
        gamma = 1;
        tracerPtr = new MultiObjects(this);

        // Red sphere.
        Sphere *sphere = new Sphere(Vec3(0, -25, 0), 80);
        sphere->setColor(Vec3(1, 0, 0));
        addObject(sphere);

        // Yellow sphere.
        sphere = new Sphere(Vec3(0, 30, 0), 60);
        sphere->setColor(Vec3(1, 1, 0));
        addObject(sphere);

        // Green plane.
        Plane *plane = new Plane(Vec3(0), Vec3(0, 1, 1));
        plane->setColor(Vec3(0, 0.3, 0));
        addObject(plane);
    }
};

