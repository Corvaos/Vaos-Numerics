#include <iostream>

#include "vaos/numerics/Matrix.h"
#include "vaos/numerics/Units.h"
#include "vaos/numerics/Random.h"

using namespace vaos::numerics;

int main()
{
  Random::seedExplicit(191);

  const Unit<double, 0, -1, 1> velocity = 10 + Random::random(-1, 1);
  const Unit<double, 1, -2, 1> force = 10 + Random::random(-1, 1);

  std::cout << Vector3((force*velocity).value) << std::endl;

  return 0;
}
