/*
 * Created by Radosław Głasek on 21.10.2026
 * radoslaw.glasek@theworldlooksback.dev
 */

#ifndef CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_VEC3_HXX
#define CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_VEC3_HXX

#include <array>
#include <span>

#include "VecBase.hxx"

namespace cadm {
template <typename T>
struct Vec<T, 3> : VecBase<T, 3, Vec<T, 3>> {
    union {
        struct {
            T x, y, z;
        };

        struct {
            T r, g, b;
        };

        std::array<T, 3> data;
    };

    constexpr Vec(const std::initializer_list<T> values)
        : data{} {
        std::size_t i = 0;
        for (const T v : values) {
            if (i == 3) {
                break;
            }
            data[i++] = v;
        }
    }

    explicit constexpr Vec(T v)
        : x{v},
          y{v},
          z{v} {
    }

    constexpr Vec()
        : x(T{0}),
          y(T{0}),
          z(T{0}) {
    }

    constexpr Vec(const T x, const T y, const T z)
        : x(x),
          y(y),
          z(z) {
    }

    constexpr static Vec unitX() noexcept {
        return {T{1}, T{0}, T{0}};
    }

    constexpr static Vec unitY() noexcept {
        return {T{0}, T{1}, T{0}};
    }

    constexpr static Vec unitZ() noexcept {
        return {T{0}, T{0}, T{1}};
    }

    [[nodiscard]] constexpr Vec cross(const Vec& other) const {
        return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
    }

    [[nodiscard]] constexpr std::span<T, 3> flatView() const {
        return data;
    }

    /// @brief Component indices for operator[] access
    struct Index {
        /// @brief X component
        static constexpr std::size_t X = 0;

        /// @brief Y component
        static constexpr std::size_t Y = 1;

        /// @brief Z component
        static constexpr std::size_t Z = 2;
    };
};

using Vec3 = Vec<cadf, 3>;
using Vec3I = Vec<int, 3>;
}


#endif // CAD_MATH_HEADER_SRC_INCLUDE_CAD_MATH_VEC3_HXX