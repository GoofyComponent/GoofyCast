#include "vec3.hpp"
#include <cmath>

Vec3::Vec3() {
    x = 0;
    y = 0;
    z = 0;
}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3::Vec3(const Vec3& v) {
    x = v.x;
    y = v.y;
    z = v.z;
}


Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(float s) const {
    return Vec3(x * s, y * s, z * s);
}

Vec3 Vec3::operator/(float s) const {
    return Vec3(x / s, y / s, z / s);
}

Vec3& Vec3::operator+=(const Vec3& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3& Vec3::operator*=(float s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Vec3& Vec3::operator/=(float s) {
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

Vec3 Vec3::operator-() const {
    return Vec3(-x, -y, -z);
}

float Vec3::dot(const Vec3& v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::cross(const Vec3& v) const {
    return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

float Vec3::length() const {
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    float l = length();
    return Vec3(x / l, y / l, z / l);
}
