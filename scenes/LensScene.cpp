
#include <MultiObjects.h>
#include <Pinhole.h>
#include <Regular.h>
#include <Random.h>
#include "ThinLens.h"
#include "Jittered.h"
#include "Scene.h"

class LensScene : public Scene {

public:

    explicit LensScene(const std::string &outputPath)
            : Scene(outputPath) {}

protected:

    void setUp() override {

        hRes = 300;
        vRes = 300;

        const int numSamples = 100;
        setSamples(numSamples);

        auto* lens = new ThinLens();
        lens->setSampler(new Jittered(numSamples));
        lens->setZoom(2);
        lens->setPosition(0, 0, 150);
        lens->setLensRadius(30);
        lens->setViewDistance(110.0);
        lens->setFocalDistance(150.0);
        setCamera(lens);

        tracerPtr = new MultiObjects(this);

        auto* redSphere = new Sphere();
        redSphere->setCenter(Vec3(-50, 0, 45));
        redSphere->setColor(Vec3(1, 0, 0));
        redSphere->setRadius(40);
        addObject(redSphere);

        auto* greenSphere = new Sphere();
        greenSphere->setCenter(Vec3(0, 0, -55));
        greenSphere->setColor(Vec3(0, 1, 0));
        greenSphere->setRadius(40);
        addObject(greenSphere);

        auto* blueSphere = new Sphere();
        greenSphere->setCenter(Vec3(80, 0, -45));
        blueSphere->setColor(Vec3(0, 0, 1));
        blueSphere->setRadius(40);
        addObject(blueSphere);
    }
};

