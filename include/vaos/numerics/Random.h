#pragma once

#include <random>

namespace vaos::numerics
{
  struct Random
  {
    inline static std::mt19937 gen{std::random_device{}()};

    static void seedExplicit(const unsigned int _seed)
    {
      gen = std::mt19937(_seed);
    }

    static void seedRandom()
    {
      std::random_device rd;
      gen = std::mt19937(rd());
    }

    static double random(const double min, const double max)
    {
      std::uniform_real_distribution<double> num(min, max);
      return num(gen);
    }
  };
}