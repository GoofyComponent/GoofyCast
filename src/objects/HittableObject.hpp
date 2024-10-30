#pragma once

#include "../raytrace/Raytrace.hpp"

class HittableObject {
public:
    virtual ~HittableObject() = default;

    virtual bool hit(const Raytrace& r, float t_min, float t_max, HitRecord& rec) const = 0;
};