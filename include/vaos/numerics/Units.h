#pragma once

#include <string>
#include <iostream>

namespace vaos::numerics
{
  /// @author Corvaos
  /// @brief A unit based on physical properties
  /// @tparam T the type of value stored
  /// @param mass the exponent of mass
  /// @param time the exponent of time
  /// @param length the exponent of length
  template <typename T, int mass, int time, int length>
  struct Unit
  {
    T value;

    Unit<T, mass, time, length>(T value) : value(value)
    {
    }

    // -------------------- RESULT OPERATORS --------------------
    [[nodiscard]] Unit<T, mass, time, length> operator+(const Unit<T, mass, time, length>& a) const
    {
      return Unit<T, mass, time, length>(value + a.value);
    }

    [[nodiscard]] Unit<T, mass, time, length> operator-(const Unit<T, mass, time, length>& a) const
    {
      return Unit<T, mass, time, length>(value - a.value);
    }

    template <int mass2, int time2, int length2>
    [[nodiscard]] Unit<T, mass + mass2, time + time2, length + length2> operator*(
      const Unit<T, mass2, time2, length2>& a) const
    {
      return Unit<T, mass + mass2, time + time2, length + length2>(value * a.value);
    }

    template <int mass2, int time2, int length2>
    [[nodiscard]] Unit<T, mass - mass2, time - time2, length - length2> operator/(
      const Unit<T, mass2, time2, length2>& a) const
    {
      return Unit<T, mass - mass2, time - time2, length - length2>(value / a.value);
    }

    // -------------------- IMMEDIATE OPERATORS --------------------
    void operator+=(const Unit<T, mass, time, length>& a)
    {
      value += a.value;
    }

    void operator-=(const Unit<T, mass, time, length>& a)
    {
      value -= a.value;
    }

    // -------------------- CONVERSIONS --------------------
    /// @author Corvaos
    /// @brief Converts the value to a string
    /// @return Value as a string
    [[nodiscard]] std::string toString() const
    {
      return std::to_string(value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Unit<T, mass, time, length>& a)
    {
      os << a.toString();
      return os;
    }
  };
}

