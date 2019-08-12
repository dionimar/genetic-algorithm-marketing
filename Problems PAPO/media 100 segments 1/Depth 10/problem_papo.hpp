#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 100;
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
    cons_event(48), cons_event(49), cons_event(50), cons_event(51),
    cons_event(52), cons_event(53), cons_event(54), cons_event(55),
    cons_event(56), cons_event(57), cons_event(58), cons_event(59),
    cons_event(60), cons_event(61), cons_event(62), cons_event(63),
    cons_event(64), cons_event(65), cons_event(66), cons_event(67),
    cons_event(68), cons_event(69), cons_event(70), cons_event(71),
    cons_event(72), cons_event(73), cons_event(74), cons_event(75),
    cons_event(76), cons_event(77), cons_event(78), cons_event(79),
    cons_event(80), cons_event(81), cons_event(82), cons_event(83),
    cons_event(84), cons_event(85), cons_event(86), cons_event(87),
    cons_event(88), cons_event(89), cons_event(90), cons_event(91),
    cons_event(92), cons_event(93), cons_event(94), cons_event(95),
    cons_event(96), cons_event(97), cons_event(98), cons_event(99)};

static const std::vector<Syntax_Tree> restrictions = {cons_indep(
    cons_indep(
        cons_indep(
            cons_indep(
                cons_excl(
                    cons_indep(
                        cons_incl(cons_indep(cons_indep(cons_incl(events[0],
                                                                  events[62]),
                                                        events[37]),
                                             events[84]),
                                  events[20]),
                        events[5]),
                    events[85]),
                events[97]),
            events[52]),
        events[90]),
    events[79])};

static const std::vector<std::vector<float>> prob = {
    {0.298095,  0.286233, 0.52587,  0.969926, 0.529767, 0.113869,  0.105502,
     0.795723,  0.519437, 0.757007, 0.357672, 0.251899, 0.689572,  0.347097,
     0.373699,  0.616918, 0.758128, 0.065493, 0.447511, 0.0878847, 0.170373,
     0.109019,  0.544594, 0.276781, 0.969223, 0.734659, 0.942994,  0.574463,
     0.316532,  0.453992, 0.771282, 0.369046, 0.822305, 0.653068,  0.285396,
     0.230866,  0.266122, 0.216516, 0.422601, 0.637652, 0.738441,  0.413742,
     0.0311693, 0.295229, 0.626684, 0.518866, 0.470558, 0.944244,  0.332258,
     0.782453,  0.242661, 0.976416, 0.616505, 0.757635, 0.761098,  0.47907,
     0.771432,  0.764344, 0.530695, 0.719139, 0.425984, 0.264754,  0.717376,
     0.271438,  0.202528, 0.112237, 0.30858,  0.320314, 0.053608,  0.715729,
     0.365622,  0.721065, 0.610322, 0.479553, 0.315652, 0.420161,  0.07623,
     0.961489,  0.741013, 0.386397, 0.595698, 0.169625, 0.58214,   0.939608,
     0.518947,  0.564879, 0.602969, 0.274547, 0.220637, 0.272462,  0.619011,
     0.550514,  0.822199, 0.866,    0.409644, 0.277746, 0.498202,  0.317331,
     0.0358347, 0.41928},
};

static const std::vector<float> costs = {
    617.362, 843.159, 404.217, 358.984, 843.417, 53.7269, 776.209, 549.625,
    762.352, 992.416, 36.5518, 375.538, 308.289, 418.985, 692.174, 92.962,
    973.494, 36.4736, 351.137, 56.5022, 699.206, 914.203, 153.742, 302.099,
    37.2896, 979.859, 427.232, 644.286, 533.56,  879.401, 214.096, 997.341,
    313.502, 750.922, 798.646, 141.502, 155.864, 623.34,  367.007, 380.337,
    691.746, 552.871, 758.991, 937.001, 849.285, 807.427, 223.987, 135.644,
    62.3246, 759.556, 720.857, 872.102, 471.951, 74.247,  245.18,  36.8117,
    797.512, 761.762, 60.059,  992.975, 747.56,  509.248, 227.406, 149.009,
    240.416, 574.608, 326.023, 207.214, 134.257, 353.952, 375.409, 720.651,
    880.939, 446.203, 18.313,  480.95,  147.54,  65.8694, 800.487, 256.67,
    348.168, 115.464, 775.586, 201.452, 119.601, 248.903, 688.707, 620.331,
    868.625, 202.72,  188.506, 222.199, 75.9391, 240.803, 631.559, 983.294,
    293.019, 57.1022, 656.409, 654.85};

static const std::vector<float> min_impressions = {0.0703863};

//
#endif
