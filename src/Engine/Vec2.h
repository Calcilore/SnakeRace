#ifndef RAYGINE_VEC2_H
#define RAYGINE_VEC2_H


#include "raylib.h"

class Vec2 {
    public:
        float x;
        float y;

        Vec2(float x, float y);
        Vec2(Vector2 vec);
        Vec2();

        Vec2 operator+(const Vec2& other) const;
        Vec2 operator-(const Vec2& other) const;
        Vec2 operator*(const Vec2& other) const;
        Vec2 operator/(const Vec2& other) const;

        Vec2 operator+(const float& other) const;
        Vec2 operator-(const float& other) const;
        Vec2 operator*(const float& other) const;
        Vec2 operator/(const float& other) const;

        Vec2 operator+=(const Vec2& other);
        Vec2 operator-=(const Vec2& other);
        Vec2 operator*=(const Vec2& other);
        Vec2 operator/=(const Vec2& other);

        Vec2 operator+=(const float& other);
        Vec2 operator-=(const float& other);
        Vec2 operator*=(const float& other);
        Vec2 operator/=(const float& other);

        [[nodiscard]] Vec2 Normalized() const;
        void Normalize();
        [[nodiscard]] float Magnitude() const;
        [[nodiscard]] float Distance(const Vec2& other) const;

        Vector2 ToVector2();
};


#endif //RAYGINE_VEC2_H
