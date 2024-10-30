#include "Camera.hpp"

Camera::Camera() : image(100, 100) {
    position = Vec3();
    lookAt = Vec3();
    aspectRatio = 0;
    width = 0;
}

Camera::Camera(const Vec3& position, const Vec3& lookAt, float aspectRatio, float width, Image image) : position(position), lookAt(lookAt), aspectRatio(aspectRatio), width(width), image(width, width / aspectRatio){
    this->position = position;
    this->lookAt = lookAt;
    this->aspectRatio = aspectRatio;
    this->width = width;
    float height = width / aspectRatio; 
    image = Image(width, height);
}

Camera::Camera(const Camera& c) : image(c.image) {
    position = c.position;
    lookAt = c.lookAt;
    aspectRatio = c.aspectRatio;
    width = c.width;
}

Vec3 Camera::createRay(float x, float y) {
    Vec3 ray = Vec3(x, y, 0);
    ray = ray.normalize();
    ray = ray * width;
    ray = ray + position;
    return ray;
}

void Camera::render() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            Vec3 ray = createRay(i, j);
            std::cout << "Ray: " << ray.x << " " << ray.y << " " << ray.z << std::endl;

            image.SetPixel(i, j, Color(1, 0, 0));
        }
    }

    image.WriteFile("../../../output/res.png");
}