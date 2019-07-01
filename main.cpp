#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <Scene.h>
#include "SamplerScene.cpp"
#include "SpheresScene.cpp"

int main() {

    Scene* scene = new RedSphereScene("render.ppm");
    scene->render();
}