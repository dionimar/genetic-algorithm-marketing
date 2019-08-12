#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 200;
static const int segments = 1;

static const std::vector<Syntax_Tree> events = {
    cons_event(0),   cons_event(1),   cons_event(2),   cons_event(3),
    cons_event(4),   cons_event(5),   cons_event(6),   cons_event(7),
    cons_event(8),   cons_event(9),   cons_event(10),  cons_event(11),
    cons_event(12),  cons_event(13),  cons_event(14),  cons_event(15),
    cons_event(16),  cons_event(17),  cons_event(18),  cons_event(19),
    cons_event(20),  cons_event(21),  cons_event(22),  cons_event(23),
    cons_event(24),  cons_event(25),  cons_event(26),  cons_event(27),
    cons_event(28),  cons_event(29),  cons_event(30),  cons_event(31),
    cons_event(32),  cons_event(33),  cons_event(34),  cons_event(35),
    cons_event(36),  cons_event(37),  cons_event(38),  cons_event(39),
    cons_event(40),  cons_event(41),  cons_event(42),  cons_event(43),
    cons_event(44),  cons_event(45),  cons_event(46),  cons_event(47),
    cons_event(48),  cons_event(49),  cons_event(50),  cons_event(51),
    cons_event(52),  cons_event(53),  cons_event(54),  cons_event(55),
    cons_event(56),  cons_event(57),  cons_event(58),  cons_event(59),
    cons_event(60),  cons_event(61),  cons_event(62),  cons_event(63),
    cons_event(64),  cons_event(65),  cons_event(66),  cons_event(67),
    cons_event(68),  cons_event(69),  cons_event(70),  cons_event(71),
    cons_event(72),  cons_event(73),  cons_event(74),  cons_event(75),
    cons_event(76),  cons_event(77),  cons_event(78),  cons_event(79),
    cons_event(80),  cons_event(81),  cons_event(82),  cons_event(83),
    cons_event(84),  cons_event(85),  cons_event(86),  cons_event(87),
    cons_event(88),  cons_event(89),  cons_event(90),  cons_event(91),
    cons_event(92),  cons_event(93),  cons_event(94),  cons_event(95),
    cons_event(96),  cons_event(97),  cons_event(98),  cons_event(99),
    cons_event(100), cons_event(101), cons_event(102), cons_event(103),
    cons_event(104), cons_event(105), cons_event(106), cons_event(107),
    cons_event(108), cons_event(109), cons_event(110), cons_event(111),
    cons_event(112), cons_event(113), cons_event(114), cons_event(115),
    cons_event(116), cons_event(117), cons_event(118), cons_event(119),
    cons_event(120), cons_event(121), cons_event(122), cons_event(123),
    cons_event(124), cons_event(125), cons_event(126), cons_event(127),
    cons_event(128), cons_event(129), cons_event(130), cons_event(131),
    cons_event(132), cons_event(133), cons_event(134), cons_event(135),
    cons_event(136), cons_event(137), cons_event(138), cons_event(139),
    cons_event(140), cons_event(141), cons_event(142), cons_event(143),
    cons_event(144), cons_event(145), cons_event(146), cons_event(147),
    cons_event(148), cons_event(149), cons_event(150), cons_event(151),
    cons_event(152), cons_event(153), cons_event(154), cons_event(155),
    cons_event(156), cons_event(157), cons_event(158), cons_event(159),
    cons_event(160), cons_event(161), cons_event(162), cons_event(163),
    cons_event(164), cons_event(165), cons_event(166), cons_event(167),
    cons_event(168), cons_event(169), cons_event(170), cons_event(171),
    cons_event(172), cons_event(173), cons_event(174), cons_event(175),
    cons_event(176), cons_event(177), cons_event(178), cons_event(179),
    cons_event(180), cons_event(181), cons_event(182), cons_event(183),
    cons_event(184), cons_event(185), cons_event(186), cons_event(187),
    cons_event(188), cons_event(189), cons_event(190), cons_event(191),
    cons_event(192), cons_event(193), cons_event(194), cons_event(195),
    cons_event(196), cons_event(197), cons_event(198), cons_event(199)};

static const std::vector<Syntax_Tree> restrictions = {cons_incl(
    cons_incl(
        cons_indep(cons_excl(cons_incl(events[28], events[40]), events[35]),
                   events[114]),
        events[102]),
    events[105])};

static const std::vector<std::vector<float>> prob = {
    {0.802994,   0.404206,  0.0978378, 0.919626,  0.0148684, 0.9063,
     0.957283,   0.552958,  0.25714,   0.432495,  0.284842,  0.485095,
     0.454026,   0.532431,  0.196847,  0.240635,  0.176771,  0.0938956,
     0.816485,   0.180643,  0.0552688, 0.406015,  0.667306,  0.441491,
     0.971162,   0.128057,  0.0070873, 0.0502681, 0.383171,  0.0467387,
     0.214967,   0.613821,  0.300243,  0.0939238, 0.808848,  0.249193,
     0.524782,   0.593561,  0.92253,   0.449859,  0.71151,   0.830946,
     0.471094,   0.602458,  0.789684,  0.317197,  0.38177,   0.331142,
     0.235055,   0.565186,  0.601609,  0.923544,  0.289091,  0.445662,
     0.499427,   0.222685,  0.335044,  0.0795241, 0.937054,  0.0508015,
     0.946257,   0.445676,  0.230293,  0.906219,  0.787661,  0.741393,
     0.438646,   0.128214,  0.329608,  0.562798,  0.385266,  0.735948,
     0.194658,   0.756104,  0.339455,  0.107878,  0.0633278, 0.990921,
     0.381976,   0.108706,  0.438377,  0.647749,  0.528705,  0.795755,
     0.727003,   0.471204,  0.262556,  0.033295,  0.303669,  0.265198,
     0.597029,   0.527582,  0.451574,  0.60526,   0.774754,  0.640825,
     0.469483,   0.233614,  0.736121,  0.730129,  0.980834,  0.774797,
     0.349901,   0.147818,  0.471615,  0.885543,  0.0394348, 0.463263,
     0.36539,    0.0207049, 0.343444,  0.173909,  0.171683,  0.687585,
     0.597211,   0.839401,  0.316451,  0.49809,   0.0678895, 0.0389334,
     0.692477,   0.884256,  0.700021,  0.538642,  0.43528,   0.550418,
     0.902186,   0.235685,  0.188245,  0.888085,  0.706874,  0.735609,
     0.776656,   0.551632,  0.984279,  0.984701,  0.783651,  0.844962,
     0.908707,   0.819263,  0.22472,   0.240007,  0.295957,  0.11714,
     0.213879,   0.315999,  0.543367,  0.823281,  0.456695,  0.970545,
     0.744041,   0.917904,  0.75194,   0.848088,  0.467001,  0.446072,
     0.621075,   0.56771,   0.299249,  0.789508,  0.449119,  0.147051,
     0.00616095, 0.514677,  0.283271,  0.453094,  0.175788,  0.715497,
     0.595366,   0.0444768, 0.0870583, 0.724944,  0.454294,  0.385938,
     0.986767,   0.262944,  0.562242,  0.295168,  0.301767,  0.980095,
     0.557605,   0.765284,  0.810195,  0.472939,  0.704517,  0.844657,
     0.794226,   0.987218,  0.660921,  0.823667,  0.471943,  0.117029,
     0.916666,   0.516621,  0.432661,  0.143096,  0.88253,   0.945039,
     0.876581,   0.572572},
};

static const std::vector<float> costs = {
    665.475, 524.272, 134.757, 317.198, 93.8903, 536.748, 251.895, 55.1859,
    373.405, 137.769, 400.731, 179.452, 841.006, 146.418, 554.443, 500.449,
    709.762, 702.533, 588.268, 800.535, 926.448, 238.683, 228.67,  645.699,
    622.015, 40.9174, 485.111, 649.997, 950.954, 296.052, 907.005, 747.759,
    674.76,  922.463, 436.653, 476.046, 312.28,  295.237, 619.075, 704.826,
    63.0835, 798.086, 612.259, 537.669, 650.065, 927.297, 513.875, 77.594,
    530.105, 263.485, 111.687, 483.341, 48.178,  922.613, 474.081, 117.602,
    881.033, 775.048, 466.937, 86.5686, 446.949, 143.428, 580.43,  241.852,
    890.859, 266.961, 144.539, 444.47,  783.176, 898.563, 93.5247, 916.881,
    897.799, 989.436, 342.332, 449.02,  843.42,  302.405, 532.423, 912.907,
    715.777, 467.798, 871.949, 169.578, 918.014, 458.772, 667.128, 540.716,
    139.067, 514.73,  671.899, 643.315, 98.5319, 892.504, 176.076, 30.334,
    302.36,  799.391, 358.204, 303.787, 789.3,   256.277, 973.346, 406.612,
    713.275, 848.44,  604.031, 502.106, 499.685, 730.336, 272.283, 62.8188,
    590.09,  632.016, 691.27,  681.928, 45.2753, 48.3114, 806.097, 288.908,
    642.971, 255.673, 330.153, 265.884, 701.811, 536.649, 719.099, 553.771,
    402.374, 290.205, 225.52,  716.839, 817.722, 342.939, 456.512, 808.763,
    871.299, 825.857, 728.617, 92.6687, 455.886, 425.118, 863.317, 700.049,
    238.67,  645.258, 115.066, 889.059, 862.235, 684.124, 960.013, 451.109,
    718.228, 781.262, 631.974, 771.393, 491.953, 942.432, 852.762, 770.904,
    61.0648, 723.993, 204.492, 453.434, 575.057, 94.9624, 395.735, 205.578,
    940.207, 339.601, 208.408, 862.558, 882.377, 456.082, 107.084, 86.6124,
    569.815, 150.209, 838.333, 211.796, 798.467, 205.041, 654.713, 489.899,
    331.002, 31.1235, 329.498, 481.292, 896.933, 326.96,  380.049, 95.7832,
    108.88,  799.597, 874.7,   76.8639, 835.703, 54.4,    328.464, 166.051};

static const std::vector<float> min_impressions = {0.474216};

//
#endif
