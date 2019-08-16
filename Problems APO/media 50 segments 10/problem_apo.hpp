#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include <vector>

#include "matrix.hpp"

#define APO

static const int media = 50;
static const int segments = 10;

static const std::vector<std::vector<float>> restr_rep{
    {9, 1, 3, 6, 4, 2, 4, 5, 4, 9},     {4, 6, 8, 7, 8, 5, 2, 9, 5, 8},
    {10, 10, 7, 4, 4, 5, 4, 5, 3, 2},   {7, 3, 6, 1, 2, 3, 4, 8, 8, 4},
    {2, 6, 6, 5, 6, 1, 3, 4, 10, 4},    {7, 5, 1, 3, 8, 6, 5, 7, 6, 6},
    {3, 5, 2, 5, 5, 7, 4, 8, 9, 4},     {2, 4, 9, 3, 7, 8, 5, 9, 1, 7},
    {9, 7, 2, 6, 6, 8, 3, 8, 2, 6},     {6, 5, 8, 5, 1, 1, 1, 3, 1, 10},
    {6, 6, 8, 7, 9, 6, 1, 2, 6, 8},     {5, 5, 7, 2, 9, 6, 7, 5, 8, 9},
    {4, 1, 3, 7, 10, 7, 4, 10, 10, 7},  {6, 10, 5, 2, 6, 4, 4, 3, 3, 4},
    {3, 6, 7, 5, 9, 5, 9, 5, 3, 9},     {8, 9, 1, 10, 8, 5, 9, 8, 3, 7},
    {6, 7, 4, 2, 6, 6, 7, 3, 5, 5},     {8, 8, 5, 6, 7, 2, 9, 6, 4, 10},
    {1, 9, 9, 6, 6, 9, 6, 5, 8, 2},     {6, 2, 8, 1, 4, 6, 9, 2, 4, 2},
    {1, 5, 5, 2, 2, 5, 5, 6, 8, 4},     {8, 10, 5, 8, 3, 9, 6, 5, 7, 5},
    {10, 7, 8, 2, 2, 1, 3, 3, 1, 2},    {8, 10, 3, 5, 6, 2, 1, 3, 10, 7},
    {4, 2, 8, 4, 9, 7, 7, 9, 10, 7},    {2, 2, 10, 8, 10, 6, 1, 10, 1, 10},
    {8, 1, 9, 6, 2, 4, 3, 1, 4, 5},     {4, 1, 10, 8, 5, 4, 7, 9, 3, 5},
    {2, 7, 6, 6, 10, 10, 7, 10, 7, 1},  {8, 3, 3, 1, 9, 4, 3, 1, 8, 8},
    {3, 3, 7, 5, 4, 10, 6, 2, 5, 5},    {4, 8, 7, 8, 9, 9, 7, 4, 6, 5},
    {7, 1, 1, 6, 7, 7, 7, 3, 1, 4},     {3, 9, 2, 1, 8, 8, 6, 10, 7, 10},
    {5, 3, 7, 9, 6, 6, 1, 10, 10, 3},   {5, 7, 2, 2, 8, 8, 6, 1, 3, 4},
    {2, 7, 9, 1, 1, 8, 6, 5, 6, 5},     {4, 8, 9, 9, 7, 4, 4, 9, 1, 7},
    {9, 2, 9, 6, 3, 6, 6, 9, 5, 5},     {9, 6, 4, 2, 9, 8, 9, 7, 4, 1},
    {10, 10, 6, 10, 1, 7, 4, 4, 1, 10}, {3, 7, 4, 5, 3, 10, 10, 3, 2, 9},
    {9, 6, 9, 10, 1, 2, 7, 4, 4, 5},    {4, 1, 9, 5, 8, 5, 4, 3, 3, 7},
    {6, 5, 8, 1, 10, 6, 8, 9, 5, 2},    {4, 9, 5, 6, 9, 6, 2, 4, 9, 5},
    {7, 9, 10, 10, 8, 2, 9, 5, 1, 7},   {6, 9, 3, 10, 1, 7, 2, 3, 5, 3},
    {7, 8, 8, 2, 7, 7, 1, 5, 5, 5},     {8, 2, 10, 3, 4, 5, 7, 2, 9, 2}};

static const Matrix restrictions_aux = Matrix(restr_rep);

static const Matrix restrictions = restrictions_aux.transpose();

static const std::vector<float> costs = {
    597, 298, 166, 453, 62,  699, 933, 699, 42,  239, 876, 441, 174,
    726, 410, 639, 546, 786, 981, 266, 324, 518, 134, 602, 614, 306,
    361, 335, 8,   172, 447, 756, 218, 238, 707, 984, 935, 935, 30,
    863, 509, 747, 551, 186, 50,  287, 640, 619, 299, 507};

static const std::vector<float> min_impressions = {45, 24, 27, 13, 19,
                                                   41, 43, 24, 48, 45};

#endif