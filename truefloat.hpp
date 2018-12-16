#pragma once
#include <iostream>

const uint64_t frac_mask = 0x000fffffffffffff;
const uint64_t exp_mask = 0x7ff0000000000000;
const uint64_t sign_mask = 0x8000000000000000;

class TrueFloat32 {
 public:
  uint32_t value;
  bool valid;
  bool isPositive;
  explicit TrueFloat32(double input);
  friend std::ostream &
  operator<<(std::ostream &os, const TrueFloat32 &f32);
  std::string
  formatOut(uint bitNum);
};
