#pragma once 

#include "../vec3/Vec3.hpp"

class Light {
    public:
        Light(const vec3& position, const vec3& color, float intensity) : position(position), color(color), intensity(intensity) {}

        vec3 position;
        vec3 color;
        float intensity;
};