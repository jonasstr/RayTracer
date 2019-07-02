#pragma once

class Vec2 {

public:

    Vec2() = default;

    Vec2(float x, float y)
            : x(x), y(y) {}

    inline Vec2 operator*(float s) {
        return {s * x, s * y};
    }

    float x, y;
};


