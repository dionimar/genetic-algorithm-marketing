#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 50;
static const int segments = 1;

static const std::vector<Syntax_Tree> events = {
    cons_event(0),  cons_event(1),  cons_event(2),  cons_event(3),
    cons_event(4),  cons_event(5),  cons_event(6),  cons_event(7),
    cons_event(8),  cons_event(9),  cons_event(10), cons_event(11),
    cons_event(12), cons_event(13), cons_event(14), cons_event(15),
    cons_event(16), cons_event(17), cons_event(18), cons_event(19),
    cons_event(20), cons_event(21), cons_event(22), cons_event(23),
    cons_event(24), cons_event(25), cons_event(26), cons_event(27),
    cons_event(28), cons_event(29), cons_event(30), cons_event(31),
    cons_event(32), cons_event(33), cons_event(34), cons_event(35),
    cons_event(36), cons_event(37), cons_event(38), cons_event(39),
    cons_event(40), cons_event(41), cons_event(42), cons_event(43),
    cons_event(44), cons_event(45), cons_event(46), cons_event(47),
    cons_event(48), cons_event(49)};

static const std::vector<Syntax_Tree> restrictions = {cons_incl(
    cons_excl(
        cons_excl(cons_incl(cons_indep(events[12], events[17]), events[35]),
                  events[43]),
        events[22]),
    events[23])};
static const std::vector<std::vector<float>> prob = {
    {0.622818,  0.636168, 0.680523, 0.786131, 0.611122,  0.236803,  0.124941,
     0.32452,   0.638297, 0.407224, 0.888544, 0.594648,  0.915377,  0.147017,
     0.164546,  0.160988, 0.11748,  0.403792, 0.653807,  0.579842,  0.893611,
     0.0788085, 0.431988, 0.848517, 0.341242, 0.413958,  0.096206,  0.23725,
     0.0188791, 0.846725, 0.925342, 0.638896, 0.493284,  0.326942,  0.53444,
     0.631996,  0.785282, 0.538862, 0.478055, 0.88586,   0.0235995, 0.986349,
     0.971343,  0.592835, 0.410123, 0.151735, 0.0963565, 0.652324,  0.120626,
     0.764107},
};

static const std::vector<float> costs = {
    91.9439, 45.1786, 798.607, 868.279, 401.533, 703.785, 113.459, 154.5,
    295.47,  803.288, 636.806, 757.066, 687.908, 20.9084, 785.859, 427.878,
    323.79,  435.96,  958.346, 550.534, 673.052, 543.894, 53.0348, 75.8105,
    436.863, 257.664, 267.8,   373.713, 350.082, 490.606, 626.403, 66.6996,
    483.053, 298.601, 624.718, 574.827, 818.669, 967.443, 41.0804, 685.959,
    2.32157, 671.702, 141.18,  519.821, 75.3321, 901.725, 327.673, 973.35,
    492.886, 736.209};

static const std::vector<float> min_impressions = {0.65156};

//
#endif
