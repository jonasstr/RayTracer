#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <Scene.h>
#include "LensScene.cpp"
#include "SpheresScene.cpp"
#include "FishEyeScene.cpp"

int main() {

    Scene* scene = new FishEyeScene("render.ppm");
    scene->render();
}