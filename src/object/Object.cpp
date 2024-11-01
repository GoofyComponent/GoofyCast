#include "Object.hpp"

sphere::sphere(const point3& center, double radius, const Material& material)
    : center(center), radius(radius), material(material) {}

bool sphere::hit(const raytrace& r, double ray_tmin, double ray_tmax, hit_record& rec) const {
    vec3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = h * h - a * c;
    if (discriminant < 0)
        return false;

    auto sqrtd = std::sqrt(discriminant);
    auto root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    //rec.normal = (rec.p - center) / radius;
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.material = std::make_shared<Material>(material);

    return true;
}