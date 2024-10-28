#include <iostream>
#include "Color.hpp"

Color::Color() : color(0, 0, 0) {}

Color::Color(float iR, float iG, float iB) : color(iR, iG, iB) {}

Color::~Color() {}

float Color::R() const { return color.x(); }
float Color::G() const { return color.y(); }
float Color::B() const { return color.z(); }

Color Color::operator+(const Color& col) const {
    vec3 result = color + col.color;
    return Color(fmax(fmin(result.x(), 1), 0), fmax(fmin(result.y(), 1), 0), fmax(fmin(result.z(), 1), 0));
}

Color& Color::operator=(const Color& col) {
    if (this != &col) {
        color = col.color;
    }
    return *this;
}

Color Color::operator*(double scalar) const {
    return Color(color.x() * scalar, color.y() * scalar, color.z() * scalar);
}

Color Color::ray_color(const Raytrace& r) const {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

    return Color(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}

std::ostream& operator<<(std::ostream& _stream, const Color& col) {
    return _stream << "(" << col.R() << ", " << col.G() << ", " << col.B() << ")";
}
