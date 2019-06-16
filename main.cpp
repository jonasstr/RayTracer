#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "ImageIO.cpp"

int main() {

    const int width = 255;
    const int height = 255;

    ImageIO img("test.ppm", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            const int r = x % 255;
            const int g = y % 255;
            const int b = y * x % 255;
            img.set(Vec3(r, g, b));
        }
    }
    img.open();
}