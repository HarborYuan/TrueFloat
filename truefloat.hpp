#pragma once
#include <iostream>
#include <sstream>
#include <gmpxx.h>
#include <cmath>

const uint64_t frac_mask = 0x000fffffffffffff;
const uint64_t exp_mask = 0x7ff0000000000000;
const uint64_t sign_mask = 0x8000000000000000;
const mpz_class r = mpz_class("21888242871839275222246405745257275088548364400416034343698204186575808495617",10);

class TrueFloat32 {
 public:
  uint32_t value;
  bool valid;
  bool sign;
  explicit TrueFloat32(double input);
  friend std::ostream &operator<<(std::ostream &os, const TrueFloat32 &f32);
};
