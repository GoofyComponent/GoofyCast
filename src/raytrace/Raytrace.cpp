#include "Raytrace.hpp" 

Raytrace::Raytrace() {
    origin = Vec3();
    direction = Vec3();
}

Raytrace::Raytrace(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {}

const Vec3& Raytrace::getOrigin() const {
    return origin;
}

const Vec3& Raytrace::getDirection() const {
    return direction;
}

Vec3 Raytrace::at(float t) const {
    return origin + direction * t;
}
