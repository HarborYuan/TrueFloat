#include "truefloat.hpp"
#include <vector>

int main() {
  std::vector<double> testNum = {0.125, -0.125};
  for (auto i:testNum) {
    TrueFloat32 tmp(i);
    std::cout << tmp << std::endl;
  }
}