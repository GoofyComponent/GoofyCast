#include "main.hpp"

vec3 reflect(const vec3 &I, const vec3 &N) {
     vec3 unit_N = unit_vector(N); // Normalise la normale
    return I - unit_N * 2.f * dot(I, unit_N);
    //return I - N*2.f*(I*N);
}

color ray_color(const raytrace& r, const hittable& world, const std::vector<Light> &lights, int depth=0) {
    hit_record rec;
    rec.normal = unit_vector(rec.normal);

    if (world.hit(r, 0.001, infinity, rec) && depth < 4) {
        vec3 diffuse_intensity(0.0f, 0.0f, 0.0f); 
        vec3 specular_light_intensity(0.0f, 0.0f, 0.0f); 

        vec3 reflection_direction = reflect(unit_vector(r.direction()), rec.normal);
        vec3 reflect_origin = dot(reflection_direction, rec.normal) < 0 
            ? rec.p - rec.normal * 0.01 
            : rec.p + rec.normal * 0.01;
        raytrace reflection_ray(reflect_origin, reflection_direction);
        color reflect_color = ray_color(reflection_ray, world, lights, depth + 1);

        for (auto light : lights) {
            vec3 light_direction = unit_vector(light.position - rec.p);
            float light_distance = (light.position - rec.p).length();
            raytrace shadow_ray = raytrace(rec.p + rec.normal * 0.001, light_direction);
            hit_record shadow_rec;
            if (world.hit(shadow_ray, 0.001, light_distance, shadow_rec)) {
                continue;
            } else {
                vec3 light_color_intensity = light.color * light.intensity;
                diffuse_intensity += light_color_intensity * std::max(0.0f, static_cast<float>(dot(rec.normal, light_direction)));
                specular_light_intensity += powf(std::max(0.0f, static_cast<float>(dot(-reflect(-light_direction, rec.normal), unit_vector(r.direction())))), rec.material->specular_exponent) * light_color_intensity;
            }
        }
        return rec.material->diffuse_color * diffuse_intensity * rec.material->albedo.x() 
            + vec3(1., 1., 1.) * specular_light_intensity * rec.material->albedo.y() 
            + reflect_color * rec.material->albedo.z();
    }
    
    //return color(0, 0, 0);
    //return blue sky
    return vec3(0.2, 0.7, 0.8);
}

int main() {
    std::string filePath = "../../../output/image_[time].png";
    std::string currentTime = getCurrentTime();
    size_t pos = filePath.find("[time]");
    if (pos != std::string::npos) {
        filePath.replace(pos, 6, currentTime);
    }

    double fov = 90.0; 

    double theta = degrees_to_radians(fov);

    
    //auto aspect_ratio = 1.0 / 1.0;
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 1920;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    Image image(image_width, image_height);

    double viewport_height = 2.0 * tan(theta / 2.0);
    auto viewport_width = viewport_height * aspect_ratio;
    auto focal_length = 2.0;
    auto camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    hittable_list scene;
    Material ivory(vec3(0.6, 0.3, 0.1),vec3(0.4, 0.4, 0.3), 50.0);
    Material red_rubber(vec3(0.9, 0.1, 0.0), vec3(0.3, 0.1, 0.1), 10.0);
    Material metal(vec3(0.8, 0.6, 0.2), vec3(0.8, 0.8, 0.8), 1425.0);
    Material mirror(vec3(0.0, 10.0, 0.8), vec3(1.0, 1.0, 1.0), 1425.);
    Material yellow_mat(vec3(0.9, 0.1, 0.0), vec3(1.0, 1.0, 0.0), 10.);
    scene.add(make_shared<sphere>(point3(0, 0, -1), 0.2, mirror));
    scene.add(make_shared<sphere>(point3(1.0, 0, -1), 0.5, ivory));
    scene.add(make_shared<sphere>(point3(0.0, -100.5, -1), 100, red_rubber));
    scene.add(make_shared<sphere>(point3(0, 0, 1), 0.5, yellow_mat));



    std::vector<Light>  lights;
    lights.push_back(Light(point3(1, 1, 0), vec3(1, 0, 0), 1.0));
    lights.push_back(Light(point3(-1, 1, 0), vec3(0, 1, 0), 1.0));
    lights.push_back(Light(point3(0, 1.5, -3), vec3(0, 0, 1), 1.0));
    lights.push_back(Light(point3(0, 6, 6), vec3(1, 1, 1), 1.0));



    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
 for (int j = image_height - 1; j >= 0; j--) { 
    std::clog << "\rScanlines remaining: " << (j + 1) << ' ' << std::flush;
    for (int i = 0; i < image_width; i++) {
        // Calcule les coordonnées normalisées (u, v) pour chaque pixel
        auto u = double(i) / (image_width - 1);
        auto v = double(j) / (image_height - 1);

        // Détermine le centre du pixel en fonction de u et v
        auto pixel_center = viewport_upper_left + u * viewport_u + v * viewport_v;
        auto ray_direction = unit_vector(pixel_center - camera_center); 
        raytrace r(camera_center, ray_direction);

        color pixel_color = ray_color(r, scene, lights, 0);

        if (i >= 0 && i < image_width && j >= 0 && j < image_height) {
            image.SetPixel(i, j, pixel_color);
        }
    }
}


    image.WriteFile(filePath.c_str());
    std::clog << "\rDone.                 \n";
}