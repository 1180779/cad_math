/*
 * Created by Radosław Głasek on 21.10.2026
 * radoslaw.glasek@theworldlooksback.dev
 */

#ifndef CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_RAY4_HXX
#define CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_RAY4_HXX

#include "Vec4.hxx"
#include "Mat4.hxx"

namespace cadm {
struct Ray4 {
    Vec4 origin;
    Vec4 direction;

    constexpr Ray4(const Vec4& point, const Vec4& direction)
        : origin(point),
          direction(direction) {
    }

    friend constexpr bool operator==(const Ray4& a, const Ray4& b) {
        return a.direction == b.direction && a.origin == b.origin;
    }

    friend constexpr bool operator!=(const Ray4& a, const Ray4& b) {
        return !(a == b);
    }

    constexpr Ray4& operator*=(const Mat4& m) {
        origin = m * origin;
        direction = m * direction;
        return *this;
    }

    friend constexpr Ray4 operator*(const Mat4& m, Ray4 r) {
        r *= m;
        return r;
    }

    friend constexpr Ray4 operator*(const Ray4& r, const Mat4& m) {
        return m * r;
    }
};
}

#endif // CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_RAY4_HXX