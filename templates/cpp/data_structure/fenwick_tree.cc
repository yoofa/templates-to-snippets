/*
 * fenwick_tree.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

// @snippets-start
// @snippets-generate true
// @snippets-description fenwick tree
// @snippets-prefix cp_fenwick_tree

class FenwickTree {
public:
  FenwickTree(int n) : max_(n), sums_(max_ + 1, 0) {}

  FenwickTree(vector<int> nums) : max_(nums.size()), sums_(max_ + 1) {
    for (int i = 1; i <= max_; i++) {
      sums_[i] += nums[i - 1];
      int next = i + lowbit(i);
      if (next <= max_) {
        sums_[next] += sums_[i];
      }
    }
  }

  void add(int i, int delta) {
    while (i <= max_) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int prefSum(int i, int j) { return prefSum(j) - prefSum(i - 1); }

private:
  int prefSum(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

  inline int lowbit(int x) { return x & -x; }
  int max_;
  vector<int> sums_;
};

// @snippets-end
