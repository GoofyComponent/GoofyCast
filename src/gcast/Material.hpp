#pragma once 

#include "../vec3/Vec3.hpp"

struct Material {
    Material(float a_x, float a_y, const vec3 &color, float spec) 
        : albedo_x(a_x), albedo_y(a_y), diffuse_color(color), specular_exponent(spec) {}

    Material() 
        : albedo_x(1.0), albedo_y(0.0), diffuse_color(), specular_exponent() {}

    float albedo_x;
    float albedo_y;
    vec3 diffuse_color;
    float specular_exponent;
};
