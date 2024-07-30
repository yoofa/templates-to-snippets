/*
 * geometry.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

// @snippets-start
// @snippets-generate true
// @snippets-description euclidean distance square
// @snippets-prefix cp_euclidean_distance_square
inline int euclidean_distance_square(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description ecuclidean distance square pair
// @snippets-prefix cp_euclidean_distance_square_pair
inline int euclidean_distance_square(std::pair<int, int>& a, std::pair<int, int>& b) {
  return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
// @snippets-end


// @snippets-start
// @snippets-generate true
// @snippets-description euclidean distance
// @snippets-prefix cp_euclidean_distance
inline double euclidean_distance(int x1, int y1, int x2, int y2) {
  return sqrt(euclidean_distance_square(x1, y1, x2, y2));
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description education distance pair
// @snippets-prefix cp_euclidean_distance_pair
inline double euclidean_distance(std::pair<int, int>& a, std::pair<int, int>& b) {
  return sqrt(euclidean_distance_square(a, b));
}
// @snippets-end

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
// @snippets-description chebyshev distance
// @snippets-prefix cp_chebyshev_distance
inline int chebyshev_distance(int x1, int y1, int x2, int y2) {
  return max(abs(x1 - x2), abs(y1 - y2));
}
// @snippets-end

// @snippets-start
// @snippets-generate true
// @snippets-description chebysev distance pair
// @snippets-prefix cp_chebyshev_distance_pair
inline int chebyshev_distance(pair<int, int>& a, pair<int, int>& b) {
  return max(abs(a.first - b.first), abs(a.second - b.second));
}
// @snippets-end
