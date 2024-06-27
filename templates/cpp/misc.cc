/*
 * misc.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "cp.h"

// misc lambda start
int main(int argc, char *argv[]) {

  // @snippets-start
  // @snippets-generate true
  // @snippets-description dfs function
  // @snippets-prefix cp_dfs
  auto dfs = [&](auto &&dfs, int i) {
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



