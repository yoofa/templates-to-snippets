/*
 * misc.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "cp.h"

// misc lambda start
int main(int argc, char* argv[]) {
  // @snippets-start
  // @snippets-generate true
  // @snippets-description dfs function
  // @snippets-prefix cp_dfs
  auto dfs = [&](auto&& dfs, int i) {
    //
    return 0;
  };
  // @snippets-end

  // misc lambda end
  return 0;
}

// @snippets-start
// @snippets-generate true
// @snippets-description manhattan distance
// @snippets-prefix cp_manhattan_distance
inline int manhattan_distance(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description manhattan distance pair
// @snippets-prefix cp_manhattan_distance_pair
inline int manhattan_distance(pair<int, int>& a, pair<int, int>& b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description is_prime
// @snippets-prefix cp_is_prime
bool is_prime(int n) {
  if (n < 2) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description get primes under n
// @snippets-prefix cp_get_primes
vector<int> get_primes(int n) {
  vector<bool> is_prime(n + 1, true);
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description get primes set under n
// @snippets-prefix cp_get_primes_set
std::unordered_set<int> primes_set(int n) {
  std::vector<bool> is_prime(n + 1, true);
  std::unordered_set<int> primes;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) {
      primes.insert(i);
      for (int j = i + i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes vector under 100
// @snippets-prefix cp_primes_v_100
const std::vector<int> primes_v_100 = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                       29, 31, 37, 41, 43, 47, 53, 59, 61,
                                       67, 71, 73, 79, 83, 89, 97};

// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes array under 100
// @snippets-prefix cp_primes_100
const std::array<int, 25> primes_100 = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                        29, 31, 37, 41, 43, 47, 53, 59, 61,
                                        67, 71, 73, 79, 83, 89, 97};
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes set under 100
// @snippets-prefix cp_primes_set_100
const std::unordered_set<int> primes_set_100 = {
    2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes vector under 1000
// @snippets-prefix cp_primes_v_1000
const std::vector<int> primes_v_1000 = {
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes array under 1000
// @snippets-prefix cp_primes_1000
const std::array<int, 168> primes_1000 = {
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description primes set under 1000
// @snippets-prefix cp_primes_set_1000

const std::unordered_set<int> primes_set_1000 = {
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
    439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
    523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
    617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
    709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
    907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description is square number
// @snippets-prefix cp_is_square_number

bool is_square_number(int n) {
  int x = sqrt(n);
  return x * x == n;
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description fast pow
// @snippets-prefix cp_fast_pow
int fast_pow(size_t x, int p) {
  size_t mul = 1;
  while (p) {
    if (p & 1) {
      mul *= x;
    }
    x *= x;
    x >>= 1;
  }
  return mul;
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description fast pow with mod
// @snippets-prefix cp_fast_pow_mod
int fast_pow_mod(size_t x, int p, int mod) {
  size_t mul = 1;
  while (p) {
    if (p & 1) {
      mul = mul * x % mod;
    }
    x = x * x % mod;
    p >>= 1;
  }
  return mul;
}
// @snippets-end

//
