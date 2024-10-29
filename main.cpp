#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>
#include "Color.hpp"
#include "Image.hpp"
#include "Uinputs.hpp"
#include "Vec3.hpp"
#include "Raytrace.hpp"

using namespace std;

std::string getCurrentTime() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    return oss.str();
}

bool hit_sphere(const point3& center, double radius, const raytrace& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}

color ray_color(const raytrace& r) {
    if (hit_sphere(point3(0,0,-1), 0.5, r))
        return color(1, 0, 0);

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
    std::string filePath = "../../../output/image_[time].png";
    std::string currentTime = getCurrentTime();
    size_t pos = filePath.find("[time]");
    if (pos != std::string::npos) {
        filePath.replace(pos, 6, currentTime);
    }

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    Image image(image_width, image_height);


    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            raytrace r(camera_center, ray_direction);

            color pixel_color = ray_color(r);

            // Log des indices et des dimensions de l'image
            std::clog << "i: " << i << ", j: " << j << ", image_width: " << image_width << ", image_height: " << image_height << "\n";

            // Vérification des indices avant de définir le pixel
            if (i >= 0 && i < image_width && j >= 0 && j < image_height) {
                image.SetPixel(i, j, pixel_color);
            } else {
                std::cerr << "Index invalide: (" << i << ", " << j << ")\n";
            }
        }
    }

    image.WriteFile(filePath.c_str());
    std::clog << "\rDone.                 \n";
}