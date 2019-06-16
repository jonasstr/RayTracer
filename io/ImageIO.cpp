#include <fstream>
#include <sstream>
#include "Vec3.h"

class ImageIO {

public:

    ImageIO(const std::string &imgPath, const int width, const int height)
            : imgPath(imgPath), out(imgPath) {
        out << "P3" << std::endl;
        out << width << " " << height << std::endl;
        out << "255" << std::endl;
    };

    void set(Vec3 pixelColor) {
        out << pixelColor.r() << " " << pixelColor.g() << " " << pixelColor.b() << std::endl;
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

