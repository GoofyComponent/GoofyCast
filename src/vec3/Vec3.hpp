#pragma once
#include <iostream>
#include <cmath>  

class vec3 {
  public:
    float e[3];

    vec3();
    vec3(float e0, float e1, float e2);

    float x() const;
    float y() const;
    float z() const;

    vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i);

    vec3& operator+=(const vec3& v);
    vec3& operator*=(float t);
    vec3& operator/=(float t);

    float length() const;
    float length_squared() const;
};

using point3 = vec3;

std::ostream& operator<<(std::ostream& out, const vec3& v);
vec3 operator+(const vec3& u, const vec3& v);
vec3 operator-(const vec3& u, const vec3& v);
vec3 operator*(const vec3& u, const vec3& v);
vec3 operator*(float t, const vec3& v);
vec3 operator*(const vec3& v, float t);
vec3 operator/(const vec3& v, float t);
float dot(const vec3& u, const vec3& v);
vec3 cross(const vec3& u, const vec3& v);
vec3 unit_vector(const vec3& v);
