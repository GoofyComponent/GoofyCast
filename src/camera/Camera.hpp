#pragma once

#include <iostream>
#include "../vec3/vec3.hpp"
#include "../rayimage/Image.hpp"

class Camera {
    public:
        Camera();
        Camera(const Vec3& position, const Vec3& lookAt, float aspectRatio, float width, Image image);
        Camera(const Camera& c);

        Vec3 position;
        Vec3 lookAt;
        float aspectRatio;
        float width;
        Image image;

        //Create the ray 
        Vec3 createRay(float x, float y);
        //Render the scene
        void render();
};

