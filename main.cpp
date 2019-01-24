#include "truefloat.hpp"
#include <vector>

int main() {
  std::vector<double> testNum = {
      0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7,
      0.2, 0.1, 0.2, 0.3, 0.4, 0.7, 0.6,
      0.3, 0.2, 0.1, 0.2, 0.3, 0.5, 0.4,
      -0.1, -0.2, -0.3, -0.4, -0.5, -0.1, 0.3,
      -0.2, -0.3, -0.4, -0.5, -0.6, -0.7, -0.8,

      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,

      0.1, 0.2, 0.3, 0.4, 0.5,
      0.2, 0.3, 0.4, 0.5, 0.6,
      0.3, 0.4, 0.5, 0.6, 0.7,
      -0.1, -0.2, -0.3, -0.4, -0.5,

      0.5, 0.5, 0.5, 0.5,

      0.01,

      0.5, 0.474399, 0.456703, 0.450813, 0.444928, 0.49212, 0.50591,
      0.50591, 0.474399, 0.454739, 0.450813, 0.446889, 0.511819, 0.529536,
      0.511819, 0.474399, 0.452775, 0.450813, 0.44885, 0.531504, 0.553111,
      0.5, 0.525601, 0.543297, 0.549188, 0.555072, 0.50788, 0.49409,

      0.694639, 0.688256, 0.68442, 0.683872, 0.683324, 0.697002, 0.700624

  };
  for (auto &i:testNum) {
    TrueFloat32 tmp(i);
    std::cout << tmp << std::endl;
  }

  std::vector<std::string> testStr = {
      "21888242871839274867156935916479251204139437783424933836233062663082391633921",
      "463245878483531755207897782820554673287608161641998478999552",
      "6905499175637879334813976791162357891523240675018682889630400",
      "21888242871839264873274358526720904104971816022459632263400108550085547356865"
  };
  for (auto &i:testStr) {
    TrueFloat32 tmp(i, 10, 192);
    std::cout << tmp.doubleOut() << std::endl;
  }

  return 0;
}