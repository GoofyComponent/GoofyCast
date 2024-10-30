#include <iostream>

#include "Camera.hpp"
#include "Image.hpp"

using namespace std;

int main() {
    Camera c = Camera(Vec3(0, 0, 0), Vec3(0, 0, 1), 1.0, 800, Image(800, 600));
    c.render();

    return 0;
}