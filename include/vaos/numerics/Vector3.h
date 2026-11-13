#pragma once

#include <cmath>

#include "Units.h"

namespace vaos::numerics
{
  /// @author Corvaos
  /// @brief A type-enforcer that allows integers, floats, doubles, and longs.
  template <typename type>
  // Restrict possible types to the following:
  concept NumericScalar =
    std::is_same_v<type, int> ||
    std::is_same_v<type, float> ||
    std::is_same_v<type, double> ||
    std::is_same_v<type, long>;

  /// @author Corvaos
  /// @brief A Three-Dimensional Vector
  template <NumericScalar T>
  struct Vector3
  {
    T x{};
    T y{};
    T z{};

    // -------------------- CONSTRUCTORS --------------------
    Vector3() = default;

    explicit Vector3(const T a) : x(a), y(a), z(a)
    {
    }

    Vector3(const T x, const T y, const T z) : x(x), y(y), z(z)
    {
    }

    template <NumericScalar T2>
    Vector3(const Vector3<T2>& a)
    {
      x = a.x;
      y = a.y;
      z = a.z;
    }

    // -------------------- RESULT OPERATORS --------------------
    Vector3 operator+(const Vector3& a) const { return {x + a.x, y + a.y, z + a.z}; }

    Vector3 operator-(const Vector3& a) const { return {x - a.x, y - a.y, z - a.z}; }

    Vector3 operator*(const T a) const { return {x * a, y * a, z * a}; }

    Vector3 operator/(const T a) const { return {x / a, y / a, z / a}; }

    // -------------------- IMMEDIATE OPERATORS --------------------
    void operator+=(const Vector3& a)
    {
      x += a.x;
      y += a.y;
      z += a.z;
    }

    void operator-=(const Vector3& a)
    {
      x -= a.x;
      y -= a.y;
      z -= a.z;
    }

    void operator*=(const T a)
    {
      x *= a;
      y *= a;
      z *= a;
    }

    void operator/=(const T a)
    {
      const auto b = static_cast<double>(a);
      x /= b;
      y /= b;
      z /= b;
    }

    // -------------------- VECTOR OPERATIONS --------------------
    /// @author Corvaos
    /// @brief Solves for the unit vector of the original
    /// @return Unit vector of the original
    [[nodiscard]] Vector3 normalize() const
    {
      Vector3 result = {x, y, z};
      return result / result.length();
    }

    // -------------------- SCALAR OPERATIONS --------------------
    /// @author Corvaos
    /// @brief Solves for the length using Pythagorean Theorem
    /// @return Length of the vector
    [[nodiscard]] T length() const
    {
      return static_cast<T>(std::sqrt(static_cast<double>(squareLength())));
    }

    /// @author Corvaos
    /// @brief Solves for the square of the length using Pythagorean Theorem
    /// @return Squared length of the vector
    [[nodiscard]] T squareLength() const
    {
      return x * x + y * y + z * z;
    }

    /// @author Corvaos
    /// @brief Solves for the dot product of the original and another vector
    /// @param a Other Vector3 to dot product against
    /// @return Scalar value of dot product
    [[nodiscard]] T dot(const Vector3& a) const
    {
      return x * a.x + y * a.y + z * a.z;
    }

    // -------------------- CONVERSIONS --------------------
    [[nodiscard]] std::string toString() const
    {
      return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3& a)
    {
      os << a.toString();
      return os;
    }
  };
} // namespace vaos::numerics
