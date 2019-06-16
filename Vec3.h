#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

class Vec3 {

public:

    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    explicit Vec3(float s) : x(s), y(s), z(s) {}

    inline float r() const { return x; }

    inline float g() const { return y; }

    inline float b() const { return z; }

    inline const Vec3 &operator+() const {
        return *this;
    }

    inline Vec3 operator+(float s) {
        // Perform component-wise addition.
        return {x + s, y + s, z + s};
    }

    inline Vec3 operator-() const {
        return {-x, -y, -z};
    }

    inline Vec3 operator-(float s) {
        // Perform component-wise subtraction.
        return {x - s, y - s, z - s};
    }

    inline Vec3 operator*(Vec3 v) const {
        return {x * v.x, y * v.y, z * v.z};
    }

    inline Vec3 operator*(float s) {
        // Perform component-wise multiplication.
        return {x * s, y * s, z * s};
    }

    inline Vec3 operator/(Vec3 v) const {
        return {x / v.x, y / v.y, z / v.z};
    }

    inline Vec3 operator/(float s) {
        // Perform component-wise division.
        return {x / s, y / s, z / s};
    }

    inline float &operator[](int i) {
        switch (i) {
            case 0:
                return x;
                break;
            case 1:
                return y;
                break;
            case 2:
                return z;
                break;
            default:
                throw std::invalid_argument("Invalid array index");
        }
    }

    inline Vec3 &operator+=(const Vec3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    };

    inline Vec3 &operator-=(const Vec3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    };

    inline Vec3 &operator*=(const Vec3 &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    };

    inline Vec3 &operator*=(const float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    };

    inline Vec3 &operator/=(const Vec3 &v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    };

    inline Vec3 &operator/=(const float s) {
        const float k = 1 / s;
        x /= k;
        y /= k;
        z /= k;
        return *this;
    };

    inline std::istream &operator>>(std::istream &is) {
        is >> x >> y >> z;
        return is;
    }

    inline std::ostream &operator<<(std::ostream &os) {
        os << x << " " << y << " " << z;
        return os;
    }

    inline float length() const {
        return sqrt(x * x + y * y + z * z);
    }

    inline float squaredLength() const {
        return x * x + y * y + z * z;
    }

    inline Vec3 normalize() {
        return operator/(length());
    }

    float x, y, z;
};

inline float dot(const Vec3 &v1, const Vec3 &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
    return {(v1.y * v2.z - v1.z * v2.y),
            (-(v1.x * v2.z - v1.z * v2.x)),
            (v1.x * v2.y - v1.y * v2.x)};
}

#endif
