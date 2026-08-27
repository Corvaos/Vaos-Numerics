#pragma once

#include <cmath>

namespace vaos::numerics
{
  template <typename type>
  // Restrict possible types to the following:
  concept NumericScalar =
    std::is_same_v<type, int> ||
    std::is_same_v<type, float> ||
    std::is_same_v<type, double>;

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
      const double b = static_cast<double>(a);
      x /= b;
      y /= b;
      z /= b;
    }

    // -------------------- VECTOR OPERATIONS --------------------
    [[nodiscard]] T length() const
    {
      return static_cast<T>(std::sqrt(static_cast<double>(squareLength())));
    }

    [[nodiscard]] T squareLength() const
    {
      return x * x + y * y + z * z;
    }

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
