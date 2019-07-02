#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <Scene.h>
#include "LensScene.cpp"
#include "SpheresScene.cpp"

int main() {

    Scene* scene = new LensScene("render.ppm");
    scene->render();
}