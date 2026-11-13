#pragma once

#include "vaos/numerics/Vector3.h"

#include <array>
#include <cmath>

namespace vaos::numerics
{
  template <typename T, std::size_t Rows, std::size_t Columns>
  class Matrix
  {
    std::array<T, Rows * Columns> data;

  public:
    // -------------------- IDENTITY MATRIX --------------------
    Matrix()
    {
      data.fill(0);
      for (int i = 0; i < Rows; i++)
      {
        data[i * Columns + i] = 1;
      }
    }

    // -------------------- RESULT OPERATORS --------------------
    [[nodiscard]] Matrix operator+(const Matrix& a) const
    {
      Matrix<T, Rows, Columns> output;

      for (int i = 0; i < Rows * Columns; i++)
      {
        output.data[i] = data[i] + a.data[i];
      }

      return output;
    }

    [[nodiscard]] Matrix operator-(const Matrix& a) const
    {
      Matrix<T, Rows, Columns> output;

      for (int i = 0; i < Rows * Columns; i++)
      {
        output.data[i] = data[i] - a.data[i];
      }

      return output;
    }

    [[nodiscard]] Matrix operator*(const double& a) const
    {
      Matrix<T, Rows, Columns> output;

      for (int i = 0; i < Rows * Columns; i++)
      {
        output.data[i] = data[i] * a;
      }

      return output;
    }

    [[nodiscard]] Matrix operator/(const double& a) const
    {
      Matrix<T, Rows, Columns> output;

      for (int i = 0; i < Rows * Columns; i++)
      {
        output.data[i] = data[i] / a;
      }

      return output;
    }

    // -------------------- IMMEDIATE OPERATORS --------------------
    void operator+=(const Matrix& a)
    {
      for (int i = 0; i < Rows * Columns; i++)
      {
        data[i] += a.data[i];
      }
    }

    void operator-=(const Matrix& a)
    {
      for (int i = 0; i < Rows * Columns; i++)
      {
        data[i] -= a.data[i];
      }
    }

    void operator*=(const float& a)
    {
      for (int i = 0; i < Rows * Columns; i++)
      {
        data[i] *= a;
      }
    }

    void operator/=(const float& a)
    {
      for (int i = 0; i < Rows * Columns; i++)
      {
        data[i] /= a;
      }
    }

    // -------------------- MATRIX MULTIPLICATION --------------------
    /// @author Corvaos
    /// @brief Multiplies two matrices of dimensions M x N and N x O
    /// @param a Matrix to be multiplied against
    /// @return Returns the product of the two matrices
    template <size_t z>
    [[nodiscard]] Matrix<T, Rows, z> operator*(const Matrix<T, Columns, z>& a)
    {
      Matrix<T, Rows, z> output;

      for (int row = 0; row < Rows; row++)
      {
        for (int column = 0; column < z; column++)
        {
          float sum = 0;

          for (size_t i = 0; i < Columns; i++)
          {
            sum += data[row + i * Rows] * a.data[i + column * Columns];
          }

          output.data[row + column * Rows] = sum;
        }
      }

      return output;
    }

    // -------------------- TRANSFORMS --------------------

    // Vector Types
    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with scale
    /// @param a Vector3 as the scale in all dimensions
    /// @return Returns the scaled matrix
    [[nodiscard]] static Matrix<float, 4, 4> scale(const Vector3<VectorType>& a)
    {
      Matrix<float, 4, 4> output;
      output.data[0] = a.x;
      output.data[5] = a.y;
      output.data[10] = a.z;
      return output;
    }

    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with rotation around the x-axis
    /// @param a Vector3 as the rotation in all dimensions
    /// @return Returns the x-rotated matrix
    [[nodiscard]] static Matrix<float, 4, 4> rotateX(const Vector3<VectorType>& a)
    {
      Matrix<float, 4, 4> output;

      const float c = std::cos(a.x);
      const float s = std::sin(a.x);
      output.data[5] *= c;
      output.data[6] *= s;
      output.data[9] *= -s;
      output.data[10] *= c;

      return output;
    }

    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with rotation around the y-axis
    /// @param a Vector3 as the rotation in all dimensions
    /// @return Returns the y-rotated matrix
    [[nodiscard]] static Matrix<float, 4, 4> rotateY(const Vector3<VectorType>& a)
    {
      Matrix<float, 4, 4> output;

      const float c = std::cos(a.y);
      const float s = std::sin(a.y);
      output.data[0] = c;
      output.data[2] = -s;
      output.data[8] = s;
      output.data[10] = c;

      return output;
    }

    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with rotation around the z-axis
    /// @param a Vector3 as the rotation in all dimensions
    /// @return Returns the z-rotated matrix
    [[nodiscard]] static Matrix<float, 4, 4> rotateZ(const Vector3<VectorType>& a)
    {
      Matrix<float, 4, 4> output;

      const float c = std::cos(a.z);
      const float s = std::sin(a.z);
      output.data[0] = c;
      output.data[1] = s;
      output.data[4] = -s;
      output.data[5] = c;

      return output;
    }

    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with rotation around all axes
    /// @param a Vector3 as the rotation in all dimensions
    /// @return Returns the rotated matrix
    [[nodiscard]] static Matrix<float, 4, 4> rotate(const Vector3<VectorType>& a)
    {
      return rotateZ(a) * rotateY(a) * rotateX(a);
    }

    template <NumericScalar VectorType>
    /// @author Corvaos
    /// @brief Creates a new matrix with translation around the origin
    /// @param a Vector3 as the translation in all dimensions
    /// @return Returns the translated matrix
    [[nodiscard]] static Matrix<float, 4, 4> translate(const Vector3<VectorType>& a)
    {
      Matrix<float, 4, 4> output;
      output.data[12] = a.x;
      output.data[13] = a.y;
      output.data[14] = a.z;
      return output;
    }


    /// @author Corvaos
    /// @brief Creates a new matrix with projection under a specified aspect
    /// @param aspect Float as the aspect ratio of the matrix
    /// @return Returns the projected matrix
    [[nodiscard]] static Matrix<float, 4, 4> projection(const float& aspect)
    {
      Matrix<float, 4, 4> output;
      if (aspect > 1)
      {
        output.data[0] = 1.0f / aspect;
      }
      else
      {
        output.data[5] = aspect;
      }
      return output;
    }

    // -------------------- CONVERSION --------------------

    /// @author Corvaos
    /// @brief Converts the matrix into a std::string
    /// @return Matrix as a string
    [[nodiscard]] std::string toString() const
    {
      std::string output;
      for (int i = 0; i < Rows; i++)
      {
        output += "[ ";
        for (int j = 0; j < Columns; j++)
        {
          output += data[i + j * Columns];
          output += ' ';
        }
        output += "] \n";
      }
      return output;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T, Rows, Columns>& a)
    {
      os << a.toString();
      return os;
    }

    // -------------------- GETTERS --------------------
    [[nodiscard]] T& valueAt(const int row, const int column) const
    {
      return data[row + Columns * column];
    }

    [[nodiscard]] T& valueAt(const int id) const
    {
      return data[id];
    }

    [[nodiscard]] std::array<T, Rows*Columns> getData() const
    {
      return data;
    }
  };

  using Matrix2 = Matrix<float, 2, 2>;
  using Matrix3 = Matrix<float, 3, 3>;
  using Matrix4 = Matrix<float, 4, 4>;
} // namespace vaos::numerics
