#include <iostream>
#include "Color.hpp"

Color::Color() : color(0, 0, 0) {}

Color::Color(float iR, float iG, float iB) : color(iR, iG, iB) {}
Color::Color(const vec3& vec) : color(vec) {}

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

Color operator*(double t, const Color& col) {
    return Color(t * col.R(), t * col.G(), t * col.B());
}

Color operator*(const Color& col, double t) {
    return Color(t * col.R(), t * col.G(), t * col.B());
}

std::ostream& operator<<(std::ostream& _stream, const Color& col) {
    return _stream << "(" << col.R() << ", " << col.G() << ", " << col.B() << ")";
}
