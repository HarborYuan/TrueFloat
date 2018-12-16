#pragma once
#include <iostream>

const uint64_t frac_mask = 0x000fffffffffffff;
const uint64_t exp_mask = 0x7ff0000000000000;
const uint64_t sign_mask = 0x8000000000000000;

class Truefloat32 {
 public:
  uint32_t value;
  bool valid;
  explicit Truefloat32(double input) {
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
    value = sign ? ~value + 1 : value;
  }

  friend std::ostream &
  operator<<(std::ostream &os, const Truefloat32 &f32) {
    if (f32.valid) {
      os << std::hex << f32.value << std::oct;
    } else {
      os << "Truefloat32 : Invalid Number";
    }
    return os;
  }
};