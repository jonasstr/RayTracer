#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <Scene.h>
#include "MultiObjectsScene.cpp"

#include "ImageIO.h"

int main() {

    Scene* scene = new MultiObjectsScene();
    scene->render("render.ppm");
}