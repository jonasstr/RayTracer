#include <SingleSphere.h>
#include "Scene.h"

class RedSphereScene : public Scene {

protected:

    void setUp() override {

        hRes = 200;
        vRes = 200;
        pixelSize = 1.0;
        gamma = 1;
        tracerPtr = new SingleSphere(this);

        sphere.setCenter(Vec3(0));
        sphere.setRadius(85.0);
    }
};
