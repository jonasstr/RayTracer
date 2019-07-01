#include <SingleSphere.h>
#include <Pinhole.h>
#include <MultiObjects.h>
#include "Scene.h"

class RedSphereScene : public Scene {

public:

    explicit RedSphereScene(const std::string &outputPath)
            : Scene(outputPath) {}

protected:

    void setUp() override {

        hRes = 300;
        vRes = 300;
        auto* camera = new Pinhole();
        camera->setViewDistance(500);
        setCamera(camera);

        tracerPtr = new MultiObjects(this);
        auto* yellowSphere = new Sphere();
        yellowSphere->setColor(Vec3(1, 1, 0));
        yellowSphere->setRadius(55);
        addObject(yellowSphere);

        auto* redSphere = new Sphere();
        redSphere->setCenter(Vec3(150, -40, 0));
        redSphere->setColor(Vec3(0.8, 0.2, 0));
        redSphere->setRadius(85);
        addObject(redSphere);

        auto* blueSphere = new Sphere();
        blueSphere->setCenter(Vec3(-45, 0, 100));
        blueSphere->setColor(Vec3(0, 0.2, 0.8));
        blueSphere->setRadius(20);
        addObject(blueSphere);
        setSamples(128);
    }
};
