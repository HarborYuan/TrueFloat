#include <iostream>
#include <sstream>
#include "truefloat.hpp"

std::string
TrueFloat32::formatOut(uint bitNum) {
  if (bitNum < 32) {
    std::cout << "TrueFloat32 :: formatOut() : bitNum is too small!";
    return std::string();
  }
  std::ostringstream output;
  output << "0x";
  output << std::string((bitNum - 32) / 4, isPositive ? '0' : 'f');
  output << std::noshowbase << std::hex << *this << std::endl;
  return output.str();
}

std::ostream &
operator<<(std::ostream &os, const TrueFloat32 &f32) {
  if (f32.valid) {
    os << std::hex << f32.value << std::dec;
  } else {
    os << "TrueFloat32 : Invalid Number";
  }
  return os;
}

TrueFloat32::TrueFloat32(double input) {
  uint64_t input_u64 = reinterpret_cast<uint64_t &>(input);
  uint64_t frac = frac_mask & input_u64;
  int64_t exp = (exp_mask & input_u64) >> 52;
  bool sign = bool((sign_mask & input_u64) >> 63);
  valid = exp < 1023;
  if (exp - 1023 + 11 >= 0) {
    uint64_t mid_value = (frac | ((uint64_t) (1) << 52)) << (exp - 1023 + 11);
    value = static_cast<uint32_t >(mid_value >> 32);
  } else if (exp - 1023 + 11 < 0 && exp - 1023 + 11 >= -52) {
    uint64_t mid_value = (frac | ((uint64_t) (1) << 52)) >> -(exp - 1023 + 11);
    value = static_cast<uint32_t >(mid_value >> 32);
  } else {
    value = 0;
  }
  isPositive = !sign;
  value = isPositive ? value : ~value + 1;
}

int
main() {
  TrueFloat32 test_tf32_1(0.25);
  std::cout << test_tf32_1.formatOut(36) << std::endl;
  return 0;
}
