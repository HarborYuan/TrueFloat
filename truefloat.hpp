#pragma once
#include <iostream>
#include <sstream>
#include <gmpxx.h>
#include <cmath>

const uint64_t frac_mask = 0x000fffffffffffff;
const uint64_t exp_mask = 0x7ff0000000000000;
const uint64_t sign_mask = 0x8000000000000000;

class TrueFloat32 {
 public:
  uint32_t value;
  bool valid;
  bool sign;
  static const mpz_class r;
  explicit TrueFloat32(double input);
  explicit TrueFloat32(std::string input, int base, int shift);
  friend std::ostream &operator<<(std::ostream &os, const TrueFloat32 &f32);
  double doubleOut();
};
