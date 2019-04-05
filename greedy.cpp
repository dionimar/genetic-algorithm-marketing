#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "greedy.hpp"
#include "matrix.hpp"
#include "problem.hpp"
#include "syntax_tree.hpp"

bool greedy_compare(const std::vector<float> &u, const std::vector<float> &v) {
  auto it_u = u.begin();
  auto it_v = v.begin();
  bool result = false;

  while (result == false && it_u != u.end() && it_v != v.end()) {
    result = (*it_u) > (*it_v);
    ++it_u;
    ++it_v;
  }

  return result;
}

std::vector<bool>
greedy_papo(const std::vector<Syntax_Tree> &_terms_for_restrictions,
            const std::vector<float> &_restrictions,
            const std::vector<std::vector<float>> &probabilities) {
  const int n = probabilities.at(0).size(); // media
  const int m = probabilities.size();       // segments
  auto x = std::vector<bool>(n, false);
  auto to_cover = _restrictions;
  auto ceros = std::vector<float>(m, 0);
  auto contribution = std::vector<float>(n, 0);

  while (greedy_compare(to_cover, ceros)) {
    for (int k = 0; k < n; k++) {
      if (x.at(k) == false) {
        auto xK = x;
        xK.at(k) = true;
        for (int i = 0; i < m; i++) {
          const float x1 = watching_Ad(_terms_for_restrictions.at(i), xK,
                                       probabilities.at(i));
          const float x2 = watching_Ad(_terms_for_restrictions.at(i), x,
                                       probabilities.at(i));
          contribution.at(k) += std::min(to_cover.at(i), x1 - x2);
        }
      }
    }

    std::vector<std::pair<int, float>> pairs;
    for (int i = 0; i < n; i++) {
      if (x.at(i) == 0) {
        pairs.push_back(std::pair<int, float>(i, contribution.at(i)));
      }
    }

    const int k =
        std::max_element(pairs.begin(), pairs.end(),
                         [](std::pair<int, float> a, std::pair<int, float> b) {
                           return a.second < b.second;
                         })
            ->first;
    auto xK = x;
    xK.at(k) = true;

    for (int i = 0; i < m; i++) {
      const float x1 =
          watching_Ad(_terms_for_restrictions.at(i), xK, probabilities.at(i));
      const float x2 =
          watching_Ad(_terms_for_restrictions.at(i), x, probabilities.at(i));
      to_cover.at(i) -= std::min(to_cover.at(i), x1 - x2);
    }
    
    x.at(k) = true;
  }
  return x;
}

std::vector<bool> greedy_apo(const int n, const Matrix &mat,
                             const std::vector<float> &_restrictions,
                             const std::vector<float> &_costs) {
  //auto M = mat.transpose();
  auto M = mat;
  //M.normalize();
  M.point_divide(_restrictions);
  const int m = _restrictions.size();
  auto x = std::vector<bool>(n, false);
  auto to_cover = std::vector<float>(m, 1);
  auto ceros = std::vector<float>(m, 0);
  
  while (greedy_compare(to_cover, ceros)) {
    std::vector<std::pair<int, float> > pairs;
    for (int k = 0; k < n; k++) {
      float sum = 0;
      for (int i = 0; i < m; i++) {
        sum += (M[i][k] / costs.at(k));
      }
      pairs.push_back(std::pair<int, float>(k, sum));
    }
    
    const int k =
        std::max_element(pairs.begin(), pairs.end(),
                         [](std::pair<int, float> a, std::pair<int, float> b) {
                           return a.second < b.second;
                         })
            ->first;
    x.at(k) = true;

    for (int i = 0; i < m; i++) {
      to_cover.at(i) -= M[i][k];
      M[i][k] = 0;
    }
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        M[i][j] = std::min(M[i][j], to_cover.at(i));
      }
    }
    
    // for (auto &&elem : to_cover) {
    //   std::cout << elem << " ";
    // }
    // std::cout << std::endl;
    // for(auto&& xi : x){
    //   std::cout<<xi;
    // }
    std::cout<<std::endl;
  }
  return x;
}
