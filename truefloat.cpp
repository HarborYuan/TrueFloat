#include "truefloat.hpp"
const mpz_class
    TrueFloat32::r = mpz_class("21888242871839275222246405745257275088548364400416034343698204186575808495617", 10);

std::ostream &operator<<(std::ostream &os, const TrueFloat32 &f32) {
  if (f32.valid) {
    if (f32.sign) {
      os << std::hex << TrueFloat32::r - mpz_class(f32.value) << std::dec;
    } else {
      os << std::hex << f32.value << std::dec;
    }
  } else {
    os << "TrueFloat32 : Invalid Number";
  }
  return os;
}

TrueFloat32::TrueFloat32(double input) {
  uint64_t input_u64 = reinterpret_cast<uint64_t &>(input);
  uint64_t frac = frac_mask & input_u64;
  int64_t exp = (exp_mask & input_u64) >> 52;
  sign = bool((sign_mask & input_u64) >> 63);
  valid = exp < 1023;
  if (exp - 1023 + 12 >= 0) {
    uint64_t mid_value = (frac | ((uint64_t) (1) << 52)) << (exp - 1023 + 12);
    value = static_cast<uint32_t >(mid_value >> 32);
  } else if (exp - 1023 + 12 < 0 && exp - 1023 + 12 >= -52) {
    uint64_t mid_value = (frac | ((uint64_t) (1) << 52)) >> -(exp - 1023 + 12);
    value = static_cast<uint32_t >(mid_value >> 32);
  } else {
    value = 0;
  }
}

TrueFloat32::TrueFloat32(const std::string input, const int base, const int shift) {
  mpz_class num = mpz_class(input, base);
  valid = true;
  if (num >= TrueFloat32::r / 2) {
    sign = true;
    mpz_class tmp = r - num;
    tmp >>= shift;
    value = static_cast<uint32_t> (tmp.get_ui());
  } else {
    sign = false;
    num >>= shift;
    value = static_cast<uint32_t> (num.get_ui());
  }
}

double TrueFloat32::doubleOut() {
  double div = sign ? -pow(2,32):pow(2,32);
  return value / div;
}
