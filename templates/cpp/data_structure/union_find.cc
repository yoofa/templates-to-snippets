/*
 * union_find.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

// @snippets-start
// @snippets-generate true
// @snippets-description union find data structure
// @snippets-prefix cp_union_find

class UnionFind {
public:
  UnionFind(int n) : size_(n) {
    parent_.resize(n);
    for (int i = 0; i < n; i++) {
      parent_[i] = i;
    }
  }

  void Union(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);
    if (root_x != root_y) {
      parent_[root_x] = root_y;
      size_--;
    }
  }

  int Find(int x) {
    if (parent_[x] != x) {
      parent_[x] = Find(parent_[x]);
    }
    return parent_[x];
  }

  bool Connected(int x, int y) { return Find(x) == Find(y); }

private:
  int size_;
  std::vector<int> parent_;
};

// @snippets-end
