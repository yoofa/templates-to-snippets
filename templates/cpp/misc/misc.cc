/*
 * misc.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

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
