#pragma once 

#include "../vec3/Vec3.hpp"

struct Material {
    Material(const vec3 &color) : diffuse_color(color) {}
    Material() : diffuse_color() {}
    vec3 diffuse_color;
};
