#pragma once
#include <iostream>
#include "Hittable.hpp"
#include "../vec3/Vec3.hpp"
#include "../raytrace/Raytrace.hpp"
#include "../gcast/GcastUtils.hpp"

class sphere : public hittable {
  public:
    sphere(const point3& center, double radius, const Material& material);
    bool hit(const raytrace& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
  private:
    point3 center;
    double radius;
    Material material;
};