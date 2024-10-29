#pragma once
#include "../vec3/Vec3.hpp"

class Raytrace {

public:
  Raytrace(){};
  Raytrace(const point3& orig, const vec3& dir): orig_(orig), dir_(dir){}

  const point3& origin() const { return orig_; }
  const vec3& direction() const { return dir_; }

  point3 at(float t) const { return orig_ + dir_ * t; }

private:
  point3 orig_;
  vec3 dir_;
};