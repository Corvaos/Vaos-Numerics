#pragma once

#include "vaos/numerics/Matrix.h"
#include "vaos/numerics/Vector3.h"

namespace vaos::numerics
{
  struct Transform
  {
    Vector3 translation{};
    Vector3 rotation{};
    Vector3 scale{};

    Transform()
      : translation(Vector3(0.0, 0.0, 0.0)),
        rotation(Vector3(0.0, 0.0, 0.0)),
        scale(Vector3(1.0, 1.0, 1.0))
    {
    }

    explicit Transform(const Vector3& translation)
      : translation(translation),
        rotation(Vector3(0.0, 0.0, 0.0)),
        scale(Vector3(1.0, 1.0, 1.0))
    {
    }


    Transform(const Vector3& translation, const double rot, const double scale)
      : translation(translation),
        rotation(Vector3(rot, rot, rot)),
        scale(Vector3(scale, scale, scale))
    {
    }

    Transform(const Vector3& translation, const Vector3& rotation, const double scale)
      : translation(translation),
        rotation(rotation),
        scale(Vector3(scale, scale, scale))
    {
    }

    Transform(const Vector3& translation, const Vector3& rotation, const Vector3& scale)
      : translation(translation),
        rotation(rotation),
        scale(scale)
    {
    }

    [[nodiscard]] Transform operator+(const Transform& a) const
    {
      return {translation + a.translation, rotation + a.rotation, scale + a.scale};
    }

    [[nodiscard]] Transform operator-(const Transform& a) const
    {
      return {translation - a.translation, rotation - a.rotation, scale - a.scale};
    }

    [[nodiscard]] Transform operator*(const double& a) const
    {
      return {translation * a, rotation * a, scale * a};
    }

    [[nodiscard]] Transform operator/(const double& a) const
    {
      return {translation / a, rotation / a, scale / a};
    }

    void operator+=(const Transform& a)
    {
      translation += a.translation;
      rotation += a.rotation;
      scale += a.scale;
    }

    void operator-=(const Transform& a)
    {
      translation -= a.translation;
      rotation -= a.rotation;
      scale -= a.scale;
    }

    void operator*=(const double& a)
    {
      translation *= a;
      rotation *= a;
      scale *= a;
    }

    void operator/=(const double& a)
    {
      translation /= a;
      rotation /= a;
      scale /= a;
    }

    [[nodiscard]] Matrix4 matrix() const
    {
      return Matrix4::translate(translation)
        * Matrix4::rotate(rotation)
        * Matrix4::scale(scale);
    }
  };
} // namespace vaos::numerics
