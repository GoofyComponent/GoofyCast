#include "main.hpp"

color ray_color(const raytrace& r, const hittable& world, const std::vector<Light> &lights) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        //return 0.5 * (rec.normal + color(1,1,1));
        //return rec.material->diffuse_color;

        float diffuse_intensity = 0.0;
        for (auto light : lights) {
            vec3 light_direction = unit_vector(light.position - rec.p);
            float light_distance = (light.position - rec.p).length();
            raytrace shadow_ray = raytrace(rec.p, light_direction);
            hit_record shadow_rec;
            if (world.hit(shadow_ray, 0.001, light_distance, shadow_rec)) {
                diffuse_intensity += 0.0;
            } else {
                diffuse_intensity += light.intensity * std::max(0.0f, static_cast<float>(dot(rec.normal, light_direction)));
            }
        }
        return rec.material->diffuse_color * diffuse_intensity;
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    //return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0); //Background color - blend blue and white
    //Make a cyan only background
    //return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.0, 1.0, 1.0);
    //Make a black only background
    return color(0, 0, 0);
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
    int image_width = 2440;
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
    Material mat1(vec3(0.8, 0.3, 0.3));
    Material ivory(vec3(0.4, 0.4, 0.3));
    Material red_rubber(vec3(0.3, 0.1, 0.1));
    scene.add(make_shared<sphere>(point3(0, 0, -1), 0.2, ivory));
    //Make a sphere with a radius of 0.5 on the right side of the screen
    scene.add(make_shared<sphere>(point3(1, 0, -1), 0.5, red_rubber));
    //Make a sphere with a radius of 0.5 on the left side of the screen
    scene.add(make_shared<sphere>(point3(-1, 0, -1), 0.5, mat1));
    scene.add(make_shared<sphere>(point3(-.8, 0, -2), .7, red_rubber));

    Light light1(vec3(0, 0, 0), point3(0, 0, -1), 0.5);
    Light light2(vec3(1, 1, 1), point3(0, 0, -1), 0.5);



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

        color pixel_color = ray_color(r, scene, {light1, light2});

        if (i >= 0 && i < image_width && j >= 0 && j < image_height) {
            image.SetPixel(i, j, pixel_color);
        }
    }
}


    image.WriteFile(filePath.c_str());
    std::clog << "\rDone.                 \n";
}