#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <vector>

#include "matrix.hpp"

#define APO

static const int media = 100;
static const int segments = 10;

static const std::vector<std::vector<float>> restr_rep{
    {2, 8, 9, 10, 5, 10, 2, 3, 4, 6},   {6, 4, 5, 2, 7, 10, 5, 7, 7, 10},
    {5, 1, 10, 10, 10, 5, 10, 9, 9, 5}, {7, 7, 3, 5, 2, 2, 4, 10, 8, 2},
    {3, 4, 7, 5, 1, 7, 10, 3, 3, 6},    {1, 6, 6, 4, 1, 8, 4, 4, 2, 5},
    {6, 9, 7, 6, 10, 9, 9, 3, 7, 1},    {8, 4, 2, 1, 8, 9, 2, 7, 10, 1},
    {6, 1, 5, 10, 2, 4, 10, 4, 6, 9},   {9, 4, 9, 1, 4, 7, 10, 7, 2, 4},
    {4, 1, 4, 10, 10, 4, 8, 10, 8, 5},  {5, 2, 3, 9, 3, 3, 5, 4, 4, 4},
    {3, 8, 9, 10, 1, 10, 5, 8, 9, 10},  {5, 2, 7, 1, 10, 6, 5, 9, 3, 9},
    {5, 9, 6, 7, 6, 2, 7, 4, 4, 5},     {5, 8, 3, 10, 4, 5, 4, 1, 5, 5},
    {9, 2, 4, 3, 7, 4, 2, 4, 4, 5},     {3, 5, 6, 3, 4, 9, 3, 3, 2, 1},
    {2, 3, 9, 4, 5, 2, 9, 9, 5, 3},     {2, 9, 6, 7, 6, 9, 7, 3, 5, 9},
    {7, 7, 8, 8, 9, 2, 10, 4, 5, 6},    {8, 10, 9, 3, 10, 4, 3, 1, 8, 3},
    {4, 9, 4, 5, 10, 6, 8, 2, 6, 3},    {6, 10, 8, 9, 9, 9, 5, 10, 8, 3},
    {10, 4, 2, 4, 9, 5, 3, 2, 7, 10},   {3, 9, 5, 2, 8, 9, 8, 7, 10, 7},
    {2, 4, 9, 5, 7, 1, 3, 6, 5, 7},     {10, 7, 5, 10, 7, 9, 4, 7, 5, 1},
    {5, 10, 5, 9, 8, 2, 3, 9, 8, 10},   {6, 1, 5, 3, 5, 3, 5, 1, 1, 4},
    {5, 6, 8, 9, 1, 5, 10, 5, 9, 1},    {10, 3, 2, 1, 4, 10, 2, 4, 8, 8},
    {4, 10, 8, 1, 2, 4, 6, 6, 6, 3},    {8, 8, 5, 1, 4, 4, 4, 9, 2, 9},
    {9, 1, 5, 9, 8, 10, 7, 2, 5, 3},    {10, 9, 2, 9, 8, 8, 3, 8, 7, 4},
    {8, 5, 5, 5, 1, 1, 6, 9, 7, 3},     {8, 4, 10, 1, 2, 8, 1, 6, 3, 2},
    {7, 9, 8, 8, 5, 10, 7, 4, 1, 8},    {7, 2, 8, 10, 3, 1, 7, 3, 4, 1},
    {3, 5, 9, 8, 1, 5, 6, 3, 10, 7},    {9, 9, 4, 7, 6, 4, 8, 5, 9, 4},
    {4, 10, 7, 9, 5, 6, 7, 1, 5, 2},    {7, 5, 8, 4, 2, 3, 4, 8, 2, 2},
    {2, 6, 5, 4, 9, 1, 10, 5, 10, 8},   {10, 7, 6, 10, 10, 10, 2, 8, 2, 6},
    {6, 5, 9, 7, 2, 10, 3, 8, 1, 8},    {7, 2, 10, 3, 6, 2, 9, 7, 10, 1},
    {8, 7, 10, 9, 10, 1, 8, 2, 4, 2},   {6, 6, 10, 3, 5, 6, 4, 5, 1, 7},
    {1, 7, 9, 8, 3, 5, 2, 3, 6, 2},     {10, 6, 2, 5, 9, 2, 8, 10, 9, 7},
    {2, 9, 4, 9, 4, 6, 2, 6, 5, 4},     {5, 7, 5, 3, 7, 2, 7, 9, 3, 2},
    {2, 2, 9, 7, 1, 1, 6, 4, 9, 5},     {2, 5, 5, 4, 3, 4, 3, 4, 3, 4},
    {5, 3, 6, 4, 4, 9, 8, 2, 10, 6},    {3, 2, 7, 10, 10, 10, 2, 10, 5, 6},
    {6, 9, 7, 10, 4, 6, 2, 7, 3, 10},   {8, 8, 10, 6, 6, 8, 9, 5, 6, 2},
    {10, 1, 7, 2, 10, 8, 6, 10, 8, 3},  {7, 5, 4, 3, 4, 1, 5, 9, 1, 9},
    {5, 3, 5, 8, 3, 2, 7, 5, 10, 8},    {3, 3, 5, 8, 7, 6, 1, 1, 10, 9},
    {2, 5, 4, 5, 5, 6, 6, 3, 2, 1},     {2, 10, 1, 4, 5, 9, 6, 6, 1, 2},
    {9, 4, 9, 2, 6, 3, 3, 4, 8, 9},     {5, 9, 7, 7, 6, 3, 7, 8, 10, 2},
    {7, 3, 9, 9, 5, 1, 1, 9, 10, 8},    {7, 1, 1, 9, 6, 1, 1, 1, 1, 8},
    {1, 1, 1, 7, 10, 1, 3, 6, 1, 7},    {4, 1, 1, 6, 6, 1, 3, 1, 8, 4},
    {2, 3, 7, 1, 6, 1, 2, 4, 6, 1},     {1, 7, 7, 3, 5, 7, 3, 3, 7, 2},
    {5, 2, 10, 10, 2, 9, 4, 3, 6, 7},   {4, 7, 8, 5, 2, 6, 3, 2, 3, 2},
    {4, 9, 6, 2, 5, 6, 4, 7, 6, 10},    {6, 5, 2, 7, 7, 3, 4, 9, 1, 2},
    {8, 7, 7, 10, 8, 4, 7, 1, 2, 4},    {9, 1, 2, 6, 6, 6, 5, 9, 8, 9},
    {5, 5, 6, 7, 4, 2, 3, 7, 5, 4},     {2, 5, 1, 4, 6, 8, 3, 7, 6, 3},
    {8, 2, 6, 9, 4, 4, 3, 8, 1, 2},     {3, 1, 2, 6, 9, 9, 6, 8, 8, 8},
    {3, 9, 6, 3, 1, 1, 2, 4, 9, 9},     {8, 3, 1, 7, 6, 10, 1, 8, 7, 5},
    {5, 5, 5, 9, 10, 4, 7, 7, 8, 8},    {4, 1, 9, 2, 1, 9, 7, 6, 1, 6},
    {4, 4, 9, 10, 1, 5, 9, 4, 8, 6},    {1, 7, 8, 4, 5, 4, 9, 7, 7, 6},
    {5, 1, 3, 2, 2, 6, 5, 9, 10, 3},    {2, 6, 1, 10, 6, 8, 8, 6, 8, 5},
    {6, 6, 8, 6, 2, 10, 3, 8, 2, 8},    {6, 1, 8, 10, 3, 4, 4, 2, 9, 1},
    {7, 4, 3, 9, 2, 8, 3, 9, 3, 8},     {3, 3, 5, 8, 3, 3, 8, 1, 6, 4},
    {9, 7, 3, 9, 9, 9, 3, 9, 7, 7},     {3, 6, 9, 7, 2, 6, 9, 2, 4, 4},
    {3, 8, 8, 10, 5, 5, 3, 5, 2, 4},    {3, 5, 2, 3, 10, 1, 4, 5, 4, 6}};

static const Matrix restrictions_aux = Matrix(restr_rep);

static const Matrix restrictions = restrictions_aux.transpose();

static const std::vector<float> costs = {
    715, 671, 583, 928, 50,  114, 892, 927, 801, 233, 858, 131, 336, 827, 335,
    475, 878, 349, 689, 572, 298, 697, 647, 651, 554, 727, 818, 972, 327, 254,
    97,  762, 133, 779, 61,  794, 659, 601, 842, 982, 741, 774, 83,  44,  471,
    223, 175, 685, 192, 994, 730, 585, 354, 3,   887, 117, 187, 891, 810, 738,
    11,  212, 883, 163, 150, 698, 595, 767, 131, 815, 57,  964, 899, 614, 528,
    849, 260, 707, 906, 798, 891, 457, 796, 618, 686, 426, 580, 286, 212, 129,
    198, 100, 688, 848, 811, 429, 310, 826, 993, 61};

static const std::vector<float> min_impressions = {16, 74, 51, 57, 68,
                                                   14, 24, 51, 34, 59};

#endif
