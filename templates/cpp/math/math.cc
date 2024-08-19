/*
 * math.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

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
    p >>= 1;
  }
  return mul;
}
// @snippets-end

/*
 * 2438. 二的幂数组中查询范围内的乘积
class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    while (n > 0) {
      auto p = std::upper_bound(v.begin(), v.end(), n) - 1;
      powers.push_back(*p);
      n -= *p;
    }
    std::reverse(powers.begin(), powers.end());

    vector<size_t> pre(powers.size() + 1);
    vector<int> inv(powers.size() + 1);
    pre[0] = 1;
    inv[0] = fastPow(1, MOD - 2);
    for (int i = 0; i < powers.size(); i++) {
      pre[i + 1] = pre[i] * powers[i] % MOD;
      inv[i + 1] = fastPow(pre[i + 1], MOD - 2);
    }

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      auto& l = queries[i][0];
      auto& r = queries[i][1];
      ans[i] = pre[r + 1] * inv[l] % MOD;
      ans[i] %= MOD;
 }
    return ans;
  }

 private:
  static constexpr int MOD = 1e9 + 7;
  int fastPow(size_t x, int p) {
    size_t mul = 1;
    while (p) {
      if (p & 1) {
        mul = mul * x % MOD;
      }
      p >>= 1;
      x = x * x % MOD;
    }
    return mul;
  }
};
*
*
*
*/

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

// @snippets-start
// @snippets-generate true
// @snippets-description matrix pow with mod
// @snippets-prefix cp_matrix_pow_mod

static constexpr int SIZE = 6;
using Matrix = array<array<int, SIZE>, SIZE>;
Matrix mul(const Matrix& a, const Matrix& b, int mod) {
  Matrix c;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      c[i][j] = 0;
      for (int k = 0; k < SIZE; k++) {
        c[i][j] = (c[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return c;
}

Matrix matrix_pow(const Matrix& a, int p, int mod) {
  Matrix res{};
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      res[i][j] = i == j;
    }
  }
  Matrix x = a;
  while (p) {
    if (p & 1) {
      res = mul(res, x, mod);
    }
    x = mul(x, x, mod);
    p >>= 1;
  }
  return res;
}

// @snippets-end
