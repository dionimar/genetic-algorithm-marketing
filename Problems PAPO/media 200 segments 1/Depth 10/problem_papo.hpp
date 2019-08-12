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

static const std::vector<Syntax_Tree> restrictions = {cons_indep(
    cons_excl(
        cons_excl(
            cons_incl(
                cons_incl(
                    cons_indep(
                        cons_incl(cons_excl(cons_indep(cons_incl(events[113],
                                                                 events[27]),
                                                       events[5]),
                                            events[87]),
                                  events[42]),
                        events[72]),
                    events[118]),
                events[59]),
            events[110]),
        events[40]),
    events[111])};

static const std::vector<std::vector<float>> prob = {
    {0.951367,  0.191038,  0.955728,  0.272358,   0.669386,   0.46076,
     0.402699,  0.417604,  0.557853,  0.4833,     0.251776,   0.424609,
     0.68959,   0.653643,  0.628448,  0.990332,   0.356594,   0.786676,
     0.436467,  0.54933,   0.689852,  0.45863,    0.188498,   0.660142,
     0.780128,  0.118875,  0.883176,  0.188817,   0.518095,   0.973115,
     0.826112,  0.957536,  0.840478,  0.0973551,  0.442474,   0.067407,
     0.673164,  0.596194,  0.220383,  0.855889,   0.198169,   0.405316,
     0.156127,  0.293035,  0.937423,  0.0424795,  0.428822,   0.0844209,
     0.964111,  0.847133,  0.259968,  0.292723,   0.601961,   0.0779282,
     0.123456,  0.643612,  0.993679,  0.817389,   0.00797984, 0.79275,
     0.485392,  0.447379,  0.216514,  0.167368,   0.865978,   0.827074,
     0.444659,  0.536382,  0.364318,  0.888527,   0.184224,   0.448455,
     0.894804,  0.681011,  0.830153,  0.552408,   0.767775,   0.36704,
     0.450557,  0.180845,  0.107018,  0.0140845,  0.640612,   0.103744,
     0.12612,   0.161757,  0.64177,   0.985327,   0.436034,   0.559955,
     0.200619,  0.200071,  0.99485,   0.747712,   0.398782,   0.284717,
     0.614502,  0.207975,  0.529656,  0.732665,   0.169648,   0.63003,
     0.320693,  0.0968654, 0.750404,  0.12699,    0.514345,   0.0409714,
     0.231721,  0.66769,   0.954718,  0.317405,   0.87351,    0.71807,
     0.41679,   0.466639,  0.445359,  0.504223,   0.846452,   0.624596,
     0.677845,  0.988035,  0.420681,  0.850471,   0.759203,   0.593617,
     0.590231,  0.291727,  0.181084,  0.485805,   0.601635,   0.630495,
     0.176266,  0.322772,  0.906103,  0.380142,   0.864171,   0.389936,
     0.588697,  0.524082,  0.605966,  0.254057,   0.856687,   0.429752,
     0.143468,  0.412131,  0.989929,  0.00352416, 0.671227,   0.201682,
     0.264373,  0.728253,  0.395948,  0.282532,   0.677426,   0.071593,
     0.773541,  0.461265,  0.0679494, 0.762565,   0.40732,    0.664146,
     0.567127,  0.789875,  0.0952451, 0.806333,   0.30258,    0.488824,
     0.0918582, 0.599641,  0.765797,  0.647922,   0.449081,   0.655022,
     0.785211,  0.926198,  0.723287,  0.821935,   0.598079,   0.855484,
     0.573262,  0.755056,  0.521303,  0.408698,   0.827575,   0.584768,
     0.952539,  0.628695,  0.304661,  0.776904,   0.998224,   0.902508,
     0.054279,  0.510601,  0.805377,  0.77404,    0.626825,   0.448104,
     0.516843,  0.609175},
};

static const std::vector<float> costs = {
    612.445, 895.292, 925.841, 825.405, 958.582, 968.011, 430.938, 968.683,
    944.399, 380.323, 510.475, 883.492, 305.131, 101.865, 881.386, 844.856,
    762.234, 108.711, 301.436, 557.701, 438.866, 736.467, 527.191, 275.529,
    181.082, 386.299, 764.704, 533.937, 453.5,   448.767, 670.776, 92.5027,
    668.107, 638.282, 303.861, 941.395, 814.085, 570.41,  909.194, 529.41,
    41.1629, 241.423, 861.508, 333.082, 262.477, 289.001, 212.18,  894.658,
    465.915, 236.795, 128.077, 519.917, 825.513, 575.761, 11.9384, 141.792,
    930.298, 414.468, 773.223, 289.29,  608.025, 843.484, 400.987, 434.639,
    905.04,  207.023, 551.361, 104.457, 957.267, 711.73,  501.003, 322.529,
    455.395, 835.195, 647.482, 152.324, 255.79,  296.387, 937.839, 451.112,
    937.982, 464.943, 980.074, 141.91,  435.65,  575.772, 363.289, 154.186,
    975.905, 932.035, 379.35,  976.787, 361.928, 219.385, 874.502, 760.431,
    339.43,  442.081, 607.091, 854.099, 211.81,  46.6103, 268.891, 791.276,
    214.722, 318.956, 176.583, 568.162, 302.051, 678.133, 320.656, 465.058,
    560.248, 514.567, 800.237, 24.5254, 592.488, 206.836, 636.274, 393.639,
    820.45,  744.091, 142.992, 236.552, 657.251, 260.623, 786.088, 445.486,
    650.5,   643.977, 758.612, 197.869, 664.459, 759.797, 284.052, 570.152,
    417.376, 1.86707, 215.913, 85.331,  745.374, 492.53,  300.909, 332.812,
    831.933, 75.037,  923.534, 492.632, 211.96,  180.332, 829.786, 855.502,
    715.455, 437.327, 83.3007, 10.715,  474.945, 830.564, 24.6936, 997.913,
    252.25,  487.949, 639.9,   195.643, 104.296, 768.185, 500.746, 647.422,
    896.676, 879.669, 809.465, 893.42,  481.754, 600.663, 249.647, 753.316,
    497.838, 662.552, 207.155, 549.067, 693.424, 331.229, 818.9,   666.645,
    282.073, 877.827, 595.353, 199.501, 752.519, 100.45,  895.71,  915.345,
    274.68,  642.772, 640.404, 835.428, 138.482, 213.17,  129.78,  581.116};

static const std::vector<float> min_impressions = {0.384838};

//
#endif
