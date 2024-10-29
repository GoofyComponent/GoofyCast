#pragma once
#include "../vec3/Vec3.hpp"

class raytrace {
  public:
    raytrace();
    raytrace(const point3& origin, const vec3& direction);

    const point3& origin() const;
    const vec3& direction() const;

    point3 at(double t) const;

  private:
    point3 orig;
    vec3 dir;
};