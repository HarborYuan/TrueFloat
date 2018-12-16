#include <iostream>
#include "truefloat.hpp"

int
main() {
  double a = 0.25;
  Truefloat32 test_tf32_1(a);
  std::cout << test_tf32_1 << std::endl;
  return 0;
}
