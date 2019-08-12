#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <vector>

#include "matrix.hpp"

#define APO

static const int media = 50;
static const int segments = 1;

static const std::vector<std::vector<float>> restr_rep{
    {10}, {6}, {1},  {6}, {5}, {8}, {7}, {2}, {10}, {5}, {6}, {9},  {9},
    {1},  {5}, {10}, {9}, {8}, {5}, {7}, {6}, {3},  {4}, {6}, {5},  {8},
    {7},  {6}, {10}, {3}, {4}, {2}, {5}, {4}, {3},  {8}, {6}, {10}, {2},
    {3},  {4}, {8},  {9}, {3}, {9}, {3}, {5}, {5},  {4}, {1}};

static const Matrix restrictions_aux = Matrix(restr_rep);

static const Matrix restrictions = restrictions_aux.transpose();

static const std::vector<float> costs = {
    740, 111, 636, 281, 974, 698, 299, 158, 561, 82,  434, 179, 486,
    159, 530, 757, 593, 997, 74,  274, 399, 262, 430, 68,  679, 462,
    269, 431, 904, 211, 585, 837, 278, 134, 984, 945, 330, 300, 728,
    503, 978, 983, 532, 192, 130, 483, 278, 675, 740, 74};

static const std::vector<float> min_impressions = {46};

#endif
