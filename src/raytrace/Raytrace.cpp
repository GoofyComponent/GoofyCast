#include "Raytrace.hpp"

raytrace::raytrace() {}

raytrace::raytrace(const point3& origin, const vec3& direction) 
    : orig(origin), dir(direction) {}

const point3& raytrace::origin() const {
    return orig;
}

const vec3& raytrace::direction() const {
    return dir;
}

point3 raytrace::at(double t) const {
    return orig + t * dir;
}


