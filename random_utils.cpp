#include <cmath>
#include <limits>
#include <mutex>
#include <random>
#include <stdio.h>
#include <stdlib.h>

#include "config.hpp"
#include "random_utils.hpp"

std::random_device r_device2;
std::mt19937 gen2(r_device2());

std::random_device generator;
#ifdef MUTATION_RATE
std::bernoulli_distribution distribution(MUTATION_RATE);
#else
std::bernoulli_distribution distribution(0.5);
#endif

std::random_device generator2;
std::bernoulli_distribution distribution2(0.5);

#ifdef PAR
static std::mutex m;
#endif

// return float in [a,b)
float random_float_in(float a, float b) {
#ifdef PAR
  std::lock_guard<std::mutex> guard(m);
#endif
  std::uniform_real_distribution<> dist_real(a, b);
  return dist_real(gen2);
}

// return int in [a,b]
int random_int_in(long long int a, long long int b) {
#ifdef PAR
  std::lock_guard<std::mutex> guard(m);
#endif
  long long int bb;

  if (b >= std::numeric_limits<int>::max() or b < 0) {
    bb = std::numeric_limits<int>::max() - 1;
  } else {
    bb = std::abs(b);
  }

  std::uniform_int_distribution<> dist_int(a, bb);
  return dist_int(gen2);
}

bool random_mutation() { return distribution(generator); }

bool random_choice() { return distribution2(generator2); }
