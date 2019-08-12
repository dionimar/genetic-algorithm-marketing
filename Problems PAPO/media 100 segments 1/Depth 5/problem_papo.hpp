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

static const std::vector<Syntax_Tree> restrictions = {cons_excl(
    cons_indep(
        cons_indep(cons_excl(cons_incl(events[97], events[84]), events[49]),
                   events[7]),
        events[95]),
    events[42])};

static const std::vector<std::vector<float>> prob = {
    {0.103963,  0.767697,  0.435467, 0.0514365, 0.256591,  0.914245,  0.549528,
     0.372024,  0.802364,  0.619465, 0.835604,  0.72142,   0.0239952, 0.857403,
     0.798121,  0.926945,  0.248414, 0.412713,  0.111092,  0.156314,  0.729798,
     0.569609,  0.191142,  0.511098, 0.593227,  0.30809,   0.660805,  0.489708,
     0.938844,  0.0672577, 0.166379, 0.641048,  0.635663,  0.382628,  0.538849,
     0.18759,   0.576352,  0.779903, 0.369556,  0.926101,  0.47662,   0.912932,
     0.430549,  0.908772,  0.926326, 0.0765315, 0.0260989, 0.94001,   0.260929,
     0.330882,  0.472697,  0.41744,  0.128665,  0.789067,  0.456209,  0.675856,
     0.903383,  0.533673,  0.915501, 0.960746,  0.673607,  0.719215,  0.216374,
     0.195932,  0.335018,  0.976231, 0.438809,  0.459491,  0.27364,   0.24318,
     0.463507,  0.283979,  0.711406, 0.536263,  0.791403,  0.851489,  0.995999,
     0.363835,  0.491611,  0.821798, 0.985845,  0.608404,  0.979448,  0.348757,
     0.205553,  0.824893,  0.783494, 0.592125,  0.0224523, 0.238436,  0.480869,
     0.415432,  0.712563,  0.87532,  0.166666,  0.593526,  0.324084,  0.474184,
     0.0369712, 0.635658},
};

static const std::vector<float> costs = {
    549.966, 608.712, 44.4555, 208.344, 624.817, 277.767, 882.967, 813.765,
    96.3308, 489.147, 642.742, 154.137, 28.9372, 847.382, 443.003, 149.138,
    810.78,  11.2526, 432.157, 636.153, 443.793, 603.051, 309.977, 611.812,
    556.174, 242.424, 18.8682, 265.365, 546.181, 129.238, 480.161, 463.907,
    76.696,  162.344, 174.24,  109.091, 372.145, 172.495, 507.638, 621.613,
    439.252, 992.221, 519.867, 690.625, 274.281, 263.107, 469.69,  612.589,
    564.704, 857.028, 330.712, 719.075, 769.571, 667.556, 882.27,  679.301,
    873.266, 637.093, 391.967, 651.205, 397.898, 190.237, 340.455, 821.067,
    206.709, 878.538, 98.341,  242.513, 897.267, 974.898, 246.821, 828.766,
    515.388, 542.762, 495.809, 205.379, 230.881, 457.026, 7.52727, 300.6,
    394.94,  231.257, 111.154, 204.198, 141.13,  202.509, 734.397, 652.967,
    49.3922, 772.489, 132.622, 714.761, 259.853, 849.047, 309.045, 198.734,
    432.718, 506.238, 374.773, 260.184};

static const std::vector<float> min_impressions = {0.747638};

//
#endif
