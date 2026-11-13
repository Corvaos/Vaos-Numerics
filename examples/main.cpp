#include <iostream>

#include "vaos/numerics/Matrix.h"
#include "vaos/numerics/Units.h"
#include "vaos/numerics/Random.h"

using namespace vaos::numerics;

int main()
{
  // Random::seed(191);

  const Unit<long, 0, -1, 1> velocity = 10 + Random::random(-100, 100);
  const Unit<long, 1, -2, 1> force = 10 + Random::random( 100);
{}
  std::cout << velocity << " " << force << std::endl;
  std::cout << velocity * force << std::endl;
  return 0;
}
