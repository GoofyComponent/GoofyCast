#pragma once


class Vec3 {
    public:
        float x, y, z;

        Vec3();
        Vec3(float x, float y, float z);
        Vec3(const Vec3& v);

        Vec3 operator+(const Vec3& v) const;
        Vec3 operator-(const Vec3& v) const;
        Vec3 operator*(float s) const;
        Vec3 operator/(float s) const;

        Vec3& operator+=(const Vec3& v);
        Vec3& operator-=(const Vec3& v);
        Vec3& operator*=(float s);
        Vec3& operator/=(float s);

        Vec3 operator-() const;

        float dot(const Vec3& v) const;
        Vec3 cross(const Vec3& v) const;
        float length() const;
        Vec3 normalize() const;
};