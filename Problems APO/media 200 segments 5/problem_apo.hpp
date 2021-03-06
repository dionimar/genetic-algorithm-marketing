#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <vector>

#include "matrix.hpp"

#define APO

static const int media = 200;
static const int segments = 5;

static const std::vector<std::vector<float>> restr_rep{
    {3, 6, 1, 5, 5},    {5, 6, 1, 5, 4},   {1, 5, 10, 8, 2},  {6, 3, 8, 8, 3},
    {2, 2, 3, 5, 2},    {2, 8, 8, 5, 5},   {9, 1, 5, 8, 5},   {7, 9, 7, 3, 5},
    {5, 5, 9, 8, 8},    {10, 4, 6, 5, 6},  {2, 4, 4, 8, 9},   {3, 10, 5, 7, 8},
    {8, 1, 2, 3, 8},    {3, 7, 7, 9, 8},   {7, 4, 2, 4, 8},   {1, 1, 7, 2, 4},
    {5, 3, 1, 8, 7},    {3, 4, 7, 8, 3},   {4, 5, 4, 8, 10},  {10, 9, 1, 6, 6},
    {5, 6, 4, 7, 4},    {5, 6, 4, 1, 4},   {3, 2, 4, 7, 4},   {8, 6, 8, 1, 6},
    {4, 2, 10, 8, 8},   {6, 8, 4, 7, 7},   {5, 10, 7, 4, 8},  {8, 1, 5, 9, 4},
    {9, 5, 5, 7, 10},   {2, 3, 10, 5, 5},  {1, 10, 6, 6, 4},  {4, 8, 6, 10, 9},
    {2, 9, 7, 9, 3},    {8, 1, 9, 4, 4},   {8, 6, 10, 10, 4}, {1, 7, 4, 4, 6},
    {2, 7, 9, 8, 4},    {8, 4, 9, 6, 9},   {10, 8, 8, 8, 3},  {6, 5, 4, 9, 6},
    {6, 3, 8, 9, 7},    {2, 4, 4, 10, 5},  {5, 10, 3, 6, 4},  {6, 2, 4, 4, 9},
    {2, 6, 3, 10, 3},   {3, 9, 2, 9, 10},  {9, 2, 9, 3, 3},   {4, 5, 2, 4, 4},
    {9, 5, 2, 3, 1},    {9, 7, 5, 4, 6},   {8, 3, 9, 9, 2},   {10, 8, 5, 10, 7},
    {7, 9, 8, 10, 4},   {10, 2, 5, 1, 8},  {2, 4, 9, 1, 4},   {9, 1, 3, 9, 7},
    {5, 10, 5, 9, 7},   {10, 9, 7, 5, 3},  {4, 8, 9, 5, 10},  {3, 4, 3, 5, 4},
    {7, 10, 6, 9, 3},   {3, 2, 10, 10, 6}, {10, 1, 6, 2, 9},  {5, 2, 9, 8, 2},
    {8, 1, 6, 3, 5},    {10, 8, 7, 1, 4},  {6, 10, 2, 7, 1},  {1, 4, 9, 8, 7},
    {8, 5, 1, 6, 1},    {5, 8, 2, 2, 5},   {1, 7, 8, 8, 6},   {4, 4, 7, 5, 7},
    {6, 2, 9, 9, 9},    {9, 3, 8, 1, 1},   {9, 2, 6, 1, 2},   {9, 4, 2, 1, 9},
    {4, 4, 9, 2, 9},    {5, 10, 4, 2, 4},  {1, 10, 1, 1, 8},  {9, 9, 2, 5, 7},
    {6, 2, 8, 5, 7},    {3, 2, 7, 9, 1},   {1, 2, 10, 8, 2},  {6, 6, 3, 8, 5},
    {7, 6, 10, 10, 10}, {2, 8, 4, 8, 3},   {6, 7, 4, 5, 1},   {3, 5, 6, 1, 2},
    {4, 10, 9, 9, 6},   {6, 6, 2, 4, 2},   {2, 10, 6, 8, 10}, {9, 3, 1, 2, 10},
    {2, 5, 7, 8, 10},   {9, 6, 9, 6, 6},   {2, 6, 5, 6, 1},   {7, 2, 10, 7, 2},
    {6, 1, 9, 4, 2},    {9, 1, 10, 8, 4},  {6, 5, 6, 10, 3},  {7, 4, 8, 4, 6},
    {1, 4, 6, 8, 6},    {5, 3, 5, 5, 10},  {7, 10, 6, 1, 8},  {10, 6, 9, 1, 8},
    {8, 10, 10, 3, 9},  {4, 3, 10, 4, 3},  {4, 2, 10, 2, 7},  {7, 7, 6, 2, 3},
    {2, 2, 1, 1, 9},    {1, 2, 1, 8, 9},   {1, 7, 5, 3, 7},   {7, 2, 10, 2, 4},
    {8, 2, 9, 3, 8},    {9, 4, 4, 4, 2},   {2, 9, 1, 5, 8},   {7, 2, 7, 6, 5},
    {3, 9, 8, 10, 3},   {4, 5, 5, 1, 4},   {9, 10, 6, 10, 1}, {3, 9, 7, 6, 4},
    {9, 2, 8, 8, 6},    {8, 10, 3, 4, 7},  {1, 4, 4, 7, 9},   {10, 8, 10, 7, 7},
    {4, 1, 10, 6, 1},   {2, 3, 3, 10, 3},  {8, 2, 10, 1, 10}, {5, 9, 8, 8, 8},
    {4, 10, 5, 9, 9},   {4, 10, 3, 2, 6},  {5, 3, 10, 9, 7},  {6, 9, 6, 9, 2},
    {8, 8, 6, 10, 1},   {2, 3, 2, 4, 10},  {6, 6, 4, 4, 5},   {7, 9, 2, 4, 10},
    {9, 4, 9, 6, 6},    {4, 7, 2, 7, 6},   {9, 5, 2, 5, 3},   {5, 9, 3, 2, 2},
    {3, 8, 8, 1, 4},    {10, 1, 4, 5, 7},  {7, 5, 1, 2, 2},   {8, 3, 7, 9, 9},
    {3, 6, 8, 2, 8},    {5, 4, 8, 4, 3},   {7, 6, 3, 2, 3},   {4, 10, 2, 8, 6},
    {10, 8, 10, 10, 3}, {8, 7, 7, 6, 4},   {10, 7, 7, 7, 2},  {8, 6, 2, 4, 2},
    {10, 3, 7, 4, 10},  {1, 8, 10, 9, 10}, {4, 3, 3, 8, 2},   {10, 7, 4, 4, 5},
    {1, 5, 2, 1, 7},    {8, 3, 9, 8, 4},   {3, 6, 2, 10, 7},  {3, 5, 2, 10, 1},
    {8, 9, 9, 6, 5},    {4, 5, 8, 6, 6},   {9, 2, 7, 5, 3},   {8, 6, 4, 8, 3},
    {9, 9, 7, 8, 1},    {3, 5, 6, 4, 9},   {2, 10, 10, 1, 9}, {7, 4, 3, 7, 3},
    {2, 10, 10, 7, 4},  {1, 1, 4, 6, 8},   {4, 6, 10, 1, 2},  {8, 6, 2, 10, 7},
    {9, 9, 3, 5, 1},    {2, 2, 8, 1, 8},   {3, 1, 9, 4, 5},   {8, 3, 8, 9, 7},
    {5, 2, 8, 5, 4},    {5, 5, 1, 5, 6},   {3, 7, 1, 3, 8},   {9, 3, 10, 4, 5},
    {4, 9, 5, 1, 9},    {1, 4, 6, 1, 10},  {9, 10, 5, 5, 9},  {5, 9, 7, 4, 7},
    {5, 3, 6, 2, 10},   {8, 6, 10, 1, 6},  {3, 9, 3, 7, 8},   {6, 2, 6, 9, 1},
    {3, 5, 6, 4, 3},    {5, 6, 8, 8, 5},   {7, 10, 4, 6, 4},  {3, 9, 10, 10, 9},
    {8, 2, 10, 4, 2},   {2, 3, 9, 6, 2},   {3, 9, 10, 4, 3},  {1, 7, 9, 6, 6},
    {4, 2, 7, 3, 4},    {7, 4, 9, 4, 7},   {10, 8, 10, 6, 8}, {4, 9, 5, 3, 2}};

static const Matrix restrictions_aux = Matrix(restr_rep);

static const Matrix restrictions = restrictions_aux.transpose();

static const std::vector<float> costs = {
    207, 151, 848, 450, 423, 892, 990, 908, 209, 946, 967, 641, 922, 420, 367,
    469, 395, 857, 585, 256, 752, 43,  660, 146, 570, 435, 931, 128, 919, 975,
    713, 630, 746, 41,  735, 979, 62,  655, 648, 574, 427, 178, 111, 482, 421,
    857, 140, 998, 632, 271, 605, 499, 790, 932, 918, 948, 156, 356, 770, 908,
    296, 484, 624, 521, 544, 482, 548, 635, 382, 515, 289, 875, 372, 780, 477,
    742, 232, 369, 394, 844, 964, 387, 443, 56,  217, 240, 908, 815, 124, 556,
    27,  1,   219, 997, 59,  157, 211, 394, 425, 293, 507, 343, 802, 325, 363,
    616, 573, 884, 575, 606, 542, 94,  968, 978, 790, 326, 269, 817, 173, 982,
    970, 305, 805, 515, 222, 30,  742, 607, 6,   926, 134, 965, 901, 624, 731,
    873, 684, 485, 245, 2,   532, 581, 989, 121, 169, 659, 317, 284, 139, 167,
    202, 861, 2,   485, 300, 848, 519, 160, 641, 727, 482, 305, 609, 729, 107,
    904, 964, 171, 345, 378, 108, 430, 553, 117, 334, 570, 541, 2,   536, 744,
    869, 221, 651, 967, 870, 960, 830, 410, 581, 134, 100, 920, 707, 736, 61,
    95,  643, 155, 403, 132};

static const std::vector<float> min_impressions = {127, 125, 90, 120, 180};

#endif
