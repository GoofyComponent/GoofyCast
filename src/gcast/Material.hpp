#pragma once 

#include "../vec3/Vec3.hpp"

struct Material {
    Material(const vec3 &a, const vec3 &color, const float &spec) : albedo(a), diffuse_color(color), specular_exponent(spec) {}
    Material() : albedo(1,0,0), diffuse_color(), specular_exponent() {}
    vec3 albedo;
    vec3 diffuse_color;
    float specular_exponent;
};
