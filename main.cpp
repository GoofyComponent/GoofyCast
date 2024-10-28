#include <iostream>
#include "Color.hpp"
#include "Image.hpp"
#include "Uinputs.hpp"
#include "Vec3.hpp"
#include "Raytrace.hpp"

using namespace std;


int main()
{    

    UserInputs userInputs;

    int WIDTH = userInputs.AskIntInput("Enter the width of the image : ");
    int HEIGHT = userInputs.AskIntInput("Enter the height of the image : ");

    auto focal_length = userInputs.AskFloatInput("Enter the focal length of the camera : ");
    Image image(WIDTH, HEIGHT, Color(0, 0, 0));
    auto viewport_height = 2;
    auto viewport_width = 2;
    auto camera_center = point3(0, 0, 0);

    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, viewport_height, 0);

    auto pixel_delta_u = viewport_u / viewport_width;
    auto pixel_delta_v = viewport_v / viewport_height;

    auto viewport_uper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel_0_0_loc = viewport_uper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    std::cout << "Pixel 0,0 location : " << pixel_0_0_loc << std::endl;
    std::cout << "image size :" << WIDTH << " x " << HEIGHT << std::endl;

    for(int y = 0; y < HEIGHT; y++) {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Percentage calculated : " << (y * 100) / HEIGHT << "%" << std::endl;
        for(int x = 0; x < WIDTH; x++) {
            auto pixel_center = pixel_0_0_loc + pixel_delta_u * x + pixel_delta_v * y;
            auto ray_direction = pixel_center - camera_center;
            Raytrace r(camera_center, ray_direction);
            std::cout << ray_direction << std::endl;

            Color color_instance;
            Color pixel_color = color_instance.ray_color(r);
            image.SetPixel(x, y, pixel_color);
        }
    }

    std::cout << "Image saved to disk" << std::endl;
    image.WriteFile("../../../circle.png"); 
    }
