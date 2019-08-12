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

static const std::vector<Syntax_Tree> restrictions = {cons_excl(
    cons_incl(
        cons_indep(
            cons_excl(
                cons_indep(
                    cons_excl(
                        cons_indep(cons_excl(cons_excl(cons_excl(events[34],
                                                                 events[5]),
                                                       events[21]),
                                             events[25]),
                                   events[1]),
                        events[41]),
                    events[31]),
                events[11]),
            events[0]),
        events[40]),
    events[27])};
static const std::vector<std::vector<float>> prob = {
    {0.97017,   0.447424, 0.460992, 0.92597,     0.361227, 0.842683,
     0.460363,  0.752755, 0.453357, 0.865053,    0.30144,  0.240132,
     0.462165,  0.114768, 0.995154, 0.862349,    0.438026, 0.47922,
     0.276321,  0.538554, 0.470069, 0.925274,    0.249537, 0.806315,
     0.652545,  0.977992, 0.382969, 0.553737,    0.575324, 0.277182,
     0.0701528, 0.781668, 0.266083, 0.950972,    0.657948, 0.838835,
     0.141384,  0.235077, 0.623462, 0.428125,    0.351177, 0.213581,
     0.101145,  0.528819, 0.86168,  0.000256483, 0.834977, 0.000420069,
     0.778506,  0.197866},
};

static const std::vector<float> costs = {
    178.568, 408.213, 902.724, 932.127, 968.132, 751.391, 680.331, 892.249,
    955.312, 426.083, 819.798, 256.15,  441.748, 75.2787, 939.436, 75.0347,
    415.753, 385.603, 916.935, 27.2867, 37.8237, 246.773, 581.199, 181.122,
    864.743, 355.217, 840.558, 538.686, 270.14,  939.573, 249.301, 744.392,
    789.327, 881.279, 296.348, 400.479, 996.214, 991.719, 637.182, 353.505,
    886.724, 685.76,  615.972, 150.657, 16.898,  50.3524, 140.006, 475.921,
    859.928, 727.238};

static const std::vector<float> min_impressions = {0.344432};

//
#endif
