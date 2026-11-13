#pragma once

#include <random>
#include <ctime>

namespace vaos::numerics
{
  /// @author Corvaos
  /// @brief A pseudo-random number generator
  class Random
  {
    inline static std::mt19937 mt{
      static_cast<std::mersenne_twister_engine<unsigned long, 32, 624, 397, 31, 2567483615, 11, 4294967295, 7,
                                               2636928640, 15, 4022730752, 18, 1812433253>::result_type>(time(nullptr))
    };

  public:
    /// @author Corvaos
    /// @brief Sets a seed for the random number generator, establishing a fixed pattern of pseudo-random numbers
    /// @param seed: lower bound
    static void seed(const unsigned int seed)
    {
      mt.seed(seed);
    }

    /// @author Corvaos
    /// @brief Generates a pseudo-random value from 0 to max
    /// @param max: upper bound
    /// @returns A pseudo-random long between 0 and max
    static long random(const unsigned long max)
    {
      mt.discard(1);
      return mt() % max;
    }

    /// @author Corvaos
    /// @brief Generates a pseudo-random value from min to max
    /// @param min: lower bound
    /// @param max: upper bound
    /// @returns A pseudo-random long between min and max
    static long random(const unsigned long min, const unsigned long max)
    {
      mt.discard(1);
      return mt() % (max - min) + min;
    }
  };
}
