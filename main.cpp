#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <Scene.h>
#include "SamplerScene.cpp"

#include "ImageIO.h"

int main() {

    Scene* scene = new SamplerScene();
    scene->render("render.ppm");
}