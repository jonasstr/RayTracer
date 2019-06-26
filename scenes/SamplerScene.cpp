
#include <NRooks.h>
#include "MultiObjects.h"
#include "Regular.h"
#include "Scene.h"
#include "Jittered.h"

class SamplerScene : public Scene {

protected:

    void setUp() override {

        const int numSamples = 128;
        hRes = 200;
        vRes = 200;
        tracerPtr = new MultiObjects(this);
        setSampler(new NRooks(numSamples));

        // Yellow sphere.
        Sphere *sphere = new Sphere(Vec3(0, 0, 0), 100);
        sphere->setColor(Vec3(1, 1, 0));
        addObject(sphere);
    }
};
