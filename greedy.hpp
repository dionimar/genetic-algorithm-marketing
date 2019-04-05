#ifndef GREEDY_PAPO_H
#define GREEDY_PAPO_H

#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#include "problem.hpp"
#include "syntax_tree.hpp"
#include "matrix.hpp"

std::vector<bool>
greedy_papo(const std::vector<Syntax_Tree> &_terms_for_restrictions,
            const std::vector<float> &_restrictions,
            const std::vector<std::vector<float> > &probabilities);

std::vector<bool> greedy_apo(const int m, const Matrix &mat,
                             const std::vector<float> &_restrictions,
                             const std::vector<float> &_costs);

#endif // GREEDY_H
