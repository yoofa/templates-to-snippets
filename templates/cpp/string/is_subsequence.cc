/*
 * is_subsequence.cc
 * Copyright (C) 2024 youfa <vsyfar@gmail.com>
 *
 * Distributed under terms of the GPLv2 license.
 */

#include "../cp.h"

// @snippets-start
// @snippets-generate true
// @snippets-prefix cp_is_subsequence
// @snippets-description check if sub is a subsequence of main
// {
// return true if sub is a subsequence of main
bool is_subsequence(const std::string &sub, const std::string &main) {
  int i = 0;
  int j = 0;
  while (i < sub.size() && j < main.size()) {
    if (sub[i] == main[j]) {
      i++;
    }
    j++;
  }
  return i == sub.size();
}
// }
// @snippets-end