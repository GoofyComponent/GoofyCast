#pragma once

#include "../vec3/vec3.hpp"

class Raytrace {
public:
    Raytrace();

    Raytrace(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {}

    const Vec3& getOrigin() const;
    const Vec3& getDirection() const;

    Vec3 at(float t) const;

private:
    Vec3 origin;
    Vec3 direction;
};