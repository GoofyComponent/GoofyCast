#pragma once

#include "../gcast/GcastUtils.hpp"
#include "../vec3/Vec3.hpp"
#include "../raytrace/Raytrace.hpp"


class hit_record {
  public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    std::shared_ptr<Material> material;

    void set_face_normal(const raytrace& r, const vec3& outward_normal);
};

class hittable {
  public:
    virtual ~hittable() = default;

    virtual bool hit(const raytrace& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};