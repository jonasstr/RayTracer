#include <fstream>
#include <sstream>
#include "Vec3.h"

class ImageIO {

public:

    explicit ImageIO(const std::string &imgPath)
            : imgPath(imgPath), out(imgPath) {}

    ImageIO(const std::string &imgPath, const int width, const int height)
            : imgPath(imgPath), out(imgPath) {
        setDimensions(width, height);
    };

    void setDimensions(const int width, const int height) {
        out << "P3" << std::endl;
        out << width << " " << height << std::endl;
        out << "255" << std::endl;
    }

    void setPixel(Vec3 pixelColor) {
        const int r = int(pixelColor.r() * 255.99);
        const int g = int(pixelColor.g() * 255.99);
        const int b = int(pixelColor.b() * 255.99);
        out << r << " " << g << " " << b << std::endl;
    }

    void open() {
        std::stringstream ss;
        ss << "xdg-open " << imgPath;
        system(ss.str().c_str());
    }

    const std::string imgPath;

private:

    std::ofstream out;
};

