#include "truefloat.hpp"
#include <vector>

int main() {
  std::vector<double> testNum = {0.1, 0.2, 0.3, 0.4, 0.19, 0.4, 0.3, 0.2, 0.1, 0.01};
  for (auto &i:testNum) {
    TrueFloat32 tmp(i);
    std::cout << tmp << std::endl;
  }

  std::vector<std::string> testStr = {"34024833821028765580868612722405776608"};
  for (auto &i:testStr) {
    TrueFloat32 tmp(i, 10, 96);
    std::cout << tmp.doubleOut() << std::endl;
  }

  return 0;
}