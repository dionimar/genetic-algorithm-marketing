#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 200;
static const int segments = 10;

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

static const std::vector<Syntax_Tree> restrictions = {
    cons_incl(
        cons_excl(
            cons_incl(
                cons_incl(
                    cons_excl(
                        cons_indep(
                            cons_indep(
                                cons_excl(cons_incl(cons_indep(events[154],
                                                               events[178]),
                                                    events[129]),
                                          events[68]),
                                events[55]),
                            events[180]),
                        events[188]),
                    events[84]),
                events[108]),
            events[10]),
        events[66]),
    cons_excl(
        cons_incl(
            cons_indep(
                cons_incl(
                    cons_indep(
                        cons_incl(cons_incl(cons_incl(cons_incl(cons_indep(
                                                                    events[99],
                                                                    events[68]),
                                                                events[58]),
                                                      events[154]),
                                            events[159]),
                                  events[158]),
                        events[10]),
                    events[21]),
                events[183]),
            events[178]),
        events[142]),
    cons_indep(
        cons_incl(
            cons_excl(
                cons_indep(
                    cons_incl(
                        cons_indep(
                            cons_indep(
                                cons_excl(cons_incl(cons_incl(events[156],
                                                              events[164]),
                                                    events[88]),
                                          events[141]),
                                events[8]),
                            events[117]),
                        events[93]),
                    events[167]),
                events[155]),
            events[37]),
        events[192]),
    cons_excl(
        cons_incl(
            cons_excl(
                cons_incl(
                    cons_indep(
                        cons_excl(cons_excl(cons_excl(cons_indep(
                                                          cons_excl(events[141],
                                                                    events[58]),
                                                          events[161]),
                                                      events[55]),
                                            events[127]),
                                  events[134]),
                        events[10]),
                    events[166]),
                events[181]),
            events[191]),
        events[185]),
    cons_excl(
        cons_incl(
            cons_indep(
                cons_incl(
                    cons_excl(
                        cons_incl(
                            cons_indep(
                                cons_indep(cons_indep(cons_incl(events[0],
                                                                events[180]),
                                                      events[12]),
                                           events[72]),
                                events[177]),
                            events[25]),
                        events[59]),
                    events[17]),
                events[189]),
            events[35]),
        events[106]),
    cons_indep(
        cons_excl(
            cons_incl(
                cons_indep(
                    cons_incl(
                        cons_indep(
                            cons_indep(
                                cons_incl(cons_indep(cons_indep(events[125],
                                                                events[138]),
                                                     events[91]),
                                          events[19]),
                                events[94]),
                            events[31]),
                        events[153]),
                    events[97]),
                events[49]),
            events[140]),
        events[149]),
    cons_indep(
        cons_indep(
            cons_incl(
                cons_excl(
                    cons_indep(
                        cons_indep(
                            cons_incl(
                                cons_excl(cons_indep(cons_incl(events[50],
                                                               events[111]),
                                                     events[145]),
                                          events[141]),
                                events[147]),
                            events[1]),
                        events[180]),
                    events[176]),
                events[101]),
            events[12]),
        events[163]),
    cons_excl(
        cons_incl(
            cons_excl(
                cons_incl(
                    cons_incl(
                        cons_indep(
                            cons_indep(
                                cons_incl(cons_indep(cons_indep(events[87],
                                                                events[106]),
                                                     events[38]),
                                          events[189]),
                                events[162]),
                            events[101]),
                        events[2]),
                    events[77]),
                events[181]),
            events[12]),
        events[137]),
    cons_excl(
        cons_excl(
            cons_excl(
                cons_excl(
                    cons_indep(
                        cons_incl(
                            cons_excl(
                                cons_incl(cons_indep(cons_incl(events[31],
                                                               events[176]),
                                                     events[129]),
                                          events[46]),
                                events[116]),
                            events[67]),
                        events[13]),
                    events[130]),
                events[61]),
            events[83]),
        events[186]),
    cons_excl(
        cons_indep(
            cons_incl(
                cons_incl(
                    cons_indep(
                        cons_excl(
                            cons_incl(
                                cons_indep(cons_incl(cons_incl(events[15],
                                                               events[177]),
                                                     events[43]),
                                           events[54]),
                                events[65]),
                            events[139]),
                        events[142]),
                    events[6]),
                events[118]),
            events[36]),
        events[174])};

static const std::vector<std::vector<float>> prob = {
    {0.423628,  0.922702,   0.0249643, 0.221393,  0.215129,  0.395946,
     0.365262,  0.361723,   0.630605,  0.474386,  0.382365,  0.557584,
     0.700096,  0.459835,   0.929706,  0.542978,  0.0572068, 0.784864,
     0.344385,  0.651498,   0.600433,  0.165219,  0.604671,  0.343133,
     0.880429,  0.815386,   0.347226,  0.490366,  0.608989,  0.436565,
     0.937585,  0.306383,   0.771685,  0.553786,  0.91089,   0.885906,
     0.554833,  0.827826,   0.364447,  0.042546,  0.794588,  0.0223372,
     0.628731,  0.161251,   0.324707,  0.0841056, 0.0170308, 0.343198,
     0.403606,  0.387986,   0.5929,    0.849092,  0.33517,   0.00076184,
     0.806334,  0.505634,   0.78515,   0.824985,  0.730191,  0.052995,
     0.159748,  0.81505,    0.230544,  0.161066,  0.45631,   0.563674,
     0.365633,  0.753843,   0.238548,  0.799893,  0.167536,  0.191955,
     0.231692,  0.546308,   0.664643,  0.466964,  0.226133,  0.201693,
     0.724694,  0.929999,   0.362905,  0.674459,  0.796118,  0.106507,
     0.828149,  0.849753,   0.73739,   0.0143191, 0.39077,   0.218956,
     0.0124766, 0.135939,   0.657738,  0.8965,    0.55664,   0.259401,
     0.737883,  0.501189,   0.791698,  0.506116,  0.902287,  0.417198,
     0.930921,  0.387342,   0.596277,  0.756965,  0.4366,    0.304645,
     0.446397,  0.828375,   0.661166,  0.472749,  0.777501,  0.259956,
     0.570966,  0.838941,   0.367624,  0.075134,  0.0318752, 0.952269,
     0.0658264, 0.0835968,  0.55172,   0.44466,   0.0597475, 0.591679,
     0.720912,  0.126091,   0.0350499, 0.426722,  0.348713,  0.169172,
     0.414014,  0.708079,   0.528541,  0.876526,  0.170166,  0.397576,
     0.291979,  0.166485,   0.0828228, 0.23301,   0.0412242, 0.497109,
     0.266699,  0.806796,   0.152963,  0.359231,  0.484757,  0.0745036,
     0.414267,  0.848025,   0.197384,  0.360757,  0.0279617, 0.0830474,
     0.942317,  0.192006,   0.227794,  0.480513,  0.614248,  0.852386,
     0.501647,  0.0367501,  0.93528,   0.915088,  0.291087,  0.819374,
     0.695219,  0.488064,   0.358278,  0.0473981, 0.711508,  0.418795,
     0.166922,  0.431413,   0.904345,  0.755309,  0.648654,  0.956845,
     0.040717,  0.00903266, 0.288296,  0.641673,  0.334326,  0.588966,
     0.0176268, 0.310844,   0.529989,  0.552657,  0.141732,  0.305579,
     0.920019,  0.460426,   0.179172,  0.942597,  0.314333,  0.52907,
     0.591456,  0.346174},
    {0.371871,   0.343608,  0.789207,   0.149638,  0.859859, 0.387242,
     0.0458133,  0.74219,   0.675104,   0.803048,  0.605541, 0.621811,
     0.173639,   0.116071,  0.263903,   0.707517,  0.493838, 0.95199,
     0.315185,   0.817573,  0.917014,   0.525811,  0.154447, 0.835485,
     0.13413,    0.962111,  0.088701,   0.819741,  0.24427,  0.915916,
     0.490873,   0.323792,  0.224879,   0.653327,  0.308355, 0.525967,
     0.285388,   0.213868,  0.607033,   0.686689,  0.712532, 0.818846,
     0.642049,   0.758256,  0.756384,   0.0959878, 0.314969, 0.661921,
     0.342529,   0.70423,   0.0918405,  0.427731,  0.062658, 0.116341,
     0.973882,   0.852355,  0.0697115,  0.987019,  0.962449, 0.919718,
     0.00596175, 0.512365,  0.875041,   0.69098,   0.784523, 0.256553,
     0.739708,   0.94647,   0.140606,   0.292385,  0.56149,  0.255441,
     0.386837,   0.403569,  0.36519,    0.611388,  0.940116, 0.286969,
     0.958542,   0.95248,   0.896904,   0.301113,  0.13561,  0.202688,
     0.92345,    0.426207,  0.599619,   0.809868,  0.87899,  0.131452,
     0.964092,   0.377954,  0.568555,   0.414928,  0.636632, 0.627235,
     0.696427,   0.854041,  0.483294,   0.930101,  0.237268, 0.876296,
     0.500768,   0.176859,  0.616273,   0.207005,  0.873674, 0.195921,
     0.824897,   0.17773,   0.229184,   0.695762,  0.605066, 0.94489,
     0.055325,   0.216655,  0.425716,   0.061859,  0.786472, 0.911384,
     0.307128,   0.539693,  0.0228611,  0.715611,  0.518981, 0.718586,
     0.0798926,  0.526837,  0.748713,   0.21742,   0.884881, 0.614049,
     0.537631,   0.200168,  0.0253228,  0.0503417, 0.21246,  0.975224,
     0.781047,   0.498088,  0.0664255,  0.642763,  0.903427, 0.681319,
     0.280046,   0.985238,  0.790589,   0.0998219, 0.363896, 0.290681,
     0.692336,   0.418897,  0.00134302, 0.296767,  0.287263, 0.844826,
     0.23538,    0.746671,  0.58805,    0.755885,  0.808392, 0.395715,
     0.823606,   0.147159,  0.490218,   0.472873,  0.863399, 0.266918,
     0.41326,    0.030329,  0.36241,    0.837612,  0.699246, 0.121587,
     0.67372,    0.0943108, 0.171686,   0.76088,   0.217616, 0.713906,
     0.15642,    0.101745,  0.895915,   0.396545,  0.229342, 0.989578,
     0.517032,   0.0607472, 0.384295,   0.881738,  0.742,    0.963362,
     0.746334,   0.294695,  0.352441,   0.256921,  0.460071, 0.450144,
     0.328294,   0.00479801},
    {0.287188, 0.042198, 0.729983,   0.388853,   0.725652,  0.936275,
     0.449476, 0.296827, 0.267011,   0.956421,   0.295488,  0.749408,
     0.124752, 0.555527, 0.266335,   0.289216,   0.344306,  0.677303,
     0.16646,  0.392846, 0.46529,    0.426843,   0.52272,   0.517709,
     0.601146, 0.4748,   0.603374,   0.339719,   0.763048,  0.248596,
     0.847996, 0.207307, 0.495521,   0.796082,   0.721652,  0.528979,
     0.785132, 0.98097,  0.204878,   0.508125,   0.588183,  0.729849,
     0.79894,  0.220766, 0.0645439,  0.423877,   0.0526898, 0.84403,
     0.200431, 0.677404, 0.689339,   0.621443,   0.155741,  0.501713,
     0.707853, 0.727516, 0.896228,   0.763264,   0.507469,  0.779134,
     0.426472, 0.131173, 0.457271,   0.650024,   0.380505,  0.249599,
     0.192399, 0.287883, 0.620103,   0.796293,   0.697072,  0.372707,
     0.47705,  0.919592, 0.406077,   0.301963,   0.795217,  0.784555,
     0.975309, 0.145116, 0.607204,   0.448648,   0.162363,  0.850466,
     0.465238, 0.609753, 0.564966,   0.273627,   0.663476,  0.681882,
     0.272639, 0.785363, 0.171208,   0.789897,   0.950688,  0.0284813,
     0.345123, 0.790443, 0.310015,   0.998327,   0.205289,  0.390859,
     0.64544,  0.989649, 0.574711,   0.45623,    0.0230847, 0.376842,
     0.56331,  0.970964, 0.678655,   0.606817,   0.839272,  0.795151,
     0.982457, 0.622667, 0.383578,   0.968308,   0.805782,  0.727636,
     0.467694, 0.015519, 0.713101,   0.505137,   0.923698,  0.822721,
     0.99605,  0.439833, 0.0184323,  0.00202714, 0.045851,  0.516189,
     0.560033, 0.712488, 0.994192,   0.40676,    0.0444378, 0.339369,
     0.11288,  0.633883, 0.86888,    0.941749,   0.264647,  0.204916,
     0.583528, 0.48095,  0.00784108, 0.827057,   0.886218,  0.108475,
     0.571914, 0.39789,  0.963655,   0.368278,   0.276458,  0.795572,
     0.802133, 0.25361,  0.192267,   0.577178,   0.51304,   0.144901,
     0.844948, 0.217299, 0.386265,   0.0364622,  0.188956,  0.478731,
     0.57702,  0.572573, 0.396273,   0.276887,   0.860695,  0.661842,
     0.635883, 0.997063, 0.530151,   0.469081,   0.951945,  0.34386,
     0.630541, 0.779461, 0.00284012, 0.627097,   0.697054,  0.114321,
     0.850643, 0.380941, 0.602039,   0.467818,   0.353364,  0.483652,
     0.481399, 0.546778, 0.346312,   0.829714,   0.448612,  0.443041,
     0.765666, 0.834279},
    {0.863297,  0.640281,  0.83764,  0.018126,  0.606623,  0.74415,  0.45665,
     0.421372,  0.133692,  0.586866, 0.172174,  0.925698,  0.687563, 0.198563,
     0.833436,  0.613135,  0.238272, 0.880526,  0.302243,  0.285444, 0.482994,
     0.711306,  0.403103,  0.779697, 0.973071,  0.321351,  0.303049, 0.166268,
     0.103445,  0.515962,  0.403826, 0.128536,  0.172845,  0.573285, 0.270646,
     0.106368,  0.486795,  0.635932, 0.821843,  0.0435134, 0.788954, 0.900999,
     0.35968,   0.536242,  0.749799, 0.115683,  0.193801,  0.502093, 0.57405,
     0.0426801, 0.284806,  0.099364, 0.971621,  0.951921,  0.824088, 0.364264,
     0.342279,  0.383748,  0.540822, 0.0205891, 0.743741,  0.516314, 0.238118,
     0.919401,  0.283265,  0.906564, 0.644726,  0.732136,  0.733246, 0.244295,
     0.492703,  0.19817,   0.804178, 0.307881,  0.911903,  0.85292,  0.609973,
     0.0587619, 0.645686,  0.64538,  0.655259,  0.185925,  0.963888, 0.497671,
     0.356212,  0.635162,  0.252466, 0.345647,  0.569704,  0.519659, 0.794423,
     0.376822,  0.233524,  0.869759, 0.160295,  0.776335,  0.229306, 0.147602,
     0.570922,  0.317342,  0.369032, 0.88626,   0.671808,  0.421343, 0.155113,
     0.6114,    0.910556,  0.134292, 0.504714,  0.120261,  0.379573, 0.0355555,
     0.109488,  0.961064,  0.661231, 0.842106,  0.646645,  0.41638,  0.85452,
     0.186176,  0.918801,  0.729347, 0.863613,  0.458458,  0.158431, 0.946707,
     0.127232,  0.654008,  0.997813, 0.944505,  0.694887,  0.302389, 0.0264859,
     0.725731,  0.872068,  0.407415, 0.695397,  0.0529791, 0.25391,  0.476609,
     0.792119,  0.424489,  0.360137, 0.508649,  0.148529,  0.39453,  0.820356,
     0.667207,  0.763141,  0.160794, 0.26622,   0.89949,   0.220048, 0.946507,
     0.822803,  0.3155,    0.386005, 0.439956,  0.338811,  0.272267, 0.326622,
     0.601642,  0.228485,  0.291183, 0.758581,  0.345929,  0.462848, 0.997782,
     0.269303,  0.124952,  0.204375, 0.194693,  0.328727,  0.126359, 0.893854,
     0.956063,  0.0596231, 0.978911, 0.950051,  0.372059,  0.427635, 0.661243,
     0.217975,  0.0137502, 0.443535, 0.270451,  0.884971,  0.61748,  0.703623,
     0.63413,   0.665031,  0.660648, 0.289576,  0.891905,  0.841584, 0.523614,
     0.855232,  0.399126,  0.850256, 0.394866},
    {0.0214722,  0.215191,  0.625432,  0.488827,  0.00408229, 0.751722,
     0.00684382, 0.286439,  0.368428,  0.0700822, 0.913353,   0.626849,
     0.140081,   0.939082,  0.104412,  0.51834,   0.555815,   0.773719,
     0.58277,    0.633955,  0.275879,  0.79359,   0.744908,   0.109978,
     0.605316,   0.938522,  0.231827,  0.472676,  0.804862,   0.449797,
     0.380839,   0.590368,  0.511046,  0.824295,  0.460197,   0.495098,
     0.657367,   0.234255,  0.819732,  0.946684,  0.45272,    0.0779692,
     0.135464,   0.589831,  0.937638,  0.627786,  0.488556,   0.603472,
     0.358881,   0.695271,  0.529622,  0.918647,  0.830512,   0.0839436,
     0.662078,   0.148383,  0.439125,  0.835462,  0.196027,   0.835655,
     0.512147,   0.121949,  0.272432,  0.258671,  0.815033,   0.264499,
     0.819257,   0.287458,  0.845515,  0.0215276, 0.363547,   0.781683,
     0.97809,    0.724678,  0.242683,  0.223214,  0.143024,   0.850055,
     0.687183,   0.143089,  0.877079,  0.961058,  0.291821,   0.89879,
     0.984958,   0.932757,  0.75972,   0.35405,   0.665985,   0.261977,
     0.193629,   0.297262,  0.787459,  0.815005,  0.749169,   0.473661,
     0.72099,    0.277588,  0.703019,  0.0174704, 0.558546,   0.372731,
     0.450682,   0.952853,  0.659192,  0.486565,  0.591358,   0.000524745,
     0.771413,   0.743611,  0.240752,  0.749184,  0.524109,   0.0111487,
     0.771829,   0.550319,  0.332947,  0.74239,   0.448748,   0.306443,
     0.546551,   0.34457,   0.845968,  0.42927,   0.284844,   0.00303674,
     0.942425,   0.489207,  0.437029,  0.832701,  0.069245,   0.843542,
     0.157649,   0.498115,  0.235869,  0.371688,  0.567417,   0.101529,
     0.473271,   0.692049,  0.18752,   0.32898,   0.437307,   0.524626,
     0.0811939,  0.936161,  0.426543,  0.818862,  0.691768,   0.329766,
     0.658754,   0.72299,   0.459177,  0.308475,  0.756433,   0.0665216,
     0.598805,   0.209691,  0.486848,  0.385704,  0.229274,   0.588556,
     0.18631,    0.857415,  0.22316,   0.471697,  0.536587,   0.165245,
     0.136791,   0.997377,  0.951656,  0.196363,  0.305766,   0.816761,
     0.818016,   0.0932438, 0.0706744, 0.688578,  0.154463,   0.979681,
     0.104695,   0.558436,  0.0787954, 0.337845,  0.77957,    0.808663,
     0.871496,   0.9946,    0.425282,  0.160029,  0.0101777,  0.822802,
     0.968069,   0.206854,  0.296905,  0.219611,  0.852961,   0.585628,
     0.633118,   0.772876},
    {0.766569,  0.961089,   0.174333,  0.171875,  0.569951,   0.658561,
     0.941201,  0.540155,   0.812733,  0.317939,  0.244125,   0.552319,
     0.125191,  0.08874,    0.478587,  0.440353,  0.670609,   0.172317,
     0.509271,  0.596642,   0.567439,  0.0542707, 0.669423,   0.0380609,
     0.449718,  0.548754,   0.350057,  0.648565,  0.0855966,  0.910137,
     0.764894,  0.686815,   0.716062,  0.95531,   0.620761,   0.494898,
     0.338713,  0.37351,    0.121197,  0.785766,  0.23217,    0.00275124,
     0.198963,  0.549233,   0.0641999, 0.161329,  0.642173,   0.0432965,
     0.45073,   0.0649845,  0.316268,  0.477387,  0.692651,   0.900084,
     0.934928,  0.904929,   0.276523,  0.462592,  0.332584,   0.491853,
     0.983992,  0.658353,   0.742177,  0.0765054, 0.61679,    0.546447,
     0.622551,  0.587115,   0.0437899, 0.362554,  0.634708,   0.61678,
     0.639164,  0.0415373,  0.270619,  0.523902,  0.618164,   0.379994,
     0.634956,  0.937499,   0.394918,  0.20818,   0.884564,   0.0596302,
     0.647857,  0.849683,   0.182345,  0.0427606, 0.188475,   0.225092,
     0.659222,  0.0402895,  0.024197,  0.942037,  0.0856246,  0.976179,
     0.361058,  0.332489,   0.804518,  0.0170821, 0.0720434,  0.121495,
     0.742625,  0.746131,   0.757757,  0.245029,  0.147677,   0.368322,
     0.814038,  0.899136,   0.374217,  0.496848,  0.101845,   0.90522,
     0.130741,  0.0311171,  0.307633,  0.227801,  0.875579,   0.198881,
     0.246437,  0.741375,   0.176735,  0.914142,  0.25892,    0.26225,
     0.800189,  0.195374,   0.790502,  0.356618,  0.793001,   0.485552,
     0.450876,  0.591562,   0.771123,  0.14528,   0.00495222, 0.191447,
     0.2513,    0.340139,   0.0791127, 0.739925,  0.359799,   0.541772,
     0.622734,  0.553751,   0.811032,  0.987568,  0.812623,   0.331356,
     0.423249,  0.252257,   0.349974,  0.277867,  0.277466,   0.250893,
     0.0917787, 0.0235801,  0.576662,  0.657167,  0.358926,   0.386548,
     0.0268895, 0.77943,    0.862884,  0.968034,  0.570071,   0.276513,
     0.731297,  0.640371,   0.538992,  0.64189,   0.378317,   0.466443,
     0.265974,  0.695551,   0.475045,  0.242427,  0.230434,   0.747531,
     0.100869,  0.996629,   0.695841,  0.864279,  0.0542236,  0.791541,
     0.21845,   0.00724663, 0.249888,  0.495808,  0.0939095,  0.18173,
     0.672028,  0.134726,   0.472811,  0.851028,  0.286224,   0.951855,
     0.667075,  0.127771},
    {0.134449,  0.718518,    0.779628,  0.773183,    0.586957,  0.755479,
     0.0999017, 0.870047,    0.709483,  0.612617,    0.541847,  0.588363,
     0.785415,  0.945319,    0.122181,  0.53388,     0.303078,  0.361472,
     0.18501,   0.178585,    0.619884,  0.31392,     0.509508,  0.931548,
     0.519817,  0.395407,    0.118758,  0.936082,    0.0543235, 0.386236,
     0.894903,  0.145325,    0.56178,   0.590838,    0.976462,  0.237928,
     0.972672,  0.549218,    0.833371,  0.644822,    0.111179,  0.978087,
     0.0253759, 0.0511572,   0.255244,  0.471647,    0.727917,  0.572123,
     0.209358,  0.28608,     0.4452,    0.979816,    0.184399,  0.0203336,
     0.264966,  0.662233,    0.0225369, 0.789128,    0.304506,  0.717151,
     0.0930221, 0.527198,    0.627083,  0.640407,    0.684257,  0.824598,
     0.314382,  0.522499,    0.791171,  0.0306567,   0.109267,  0.878017,
     0.311762,  0.830084,    0.258351,  0.702944,    0.906294,  0.898195,
     0.81597,   0.396372,    0.912264,  0.22941,     0.145036,  0.00383395,
     0.08647,   0.211422,    0.560308,  0.367195,    0.22049,   0.911299,
     0.718345,  0.0217072,   0.812503,  0.672601,    0.762672,  0.554154,
     0.563647,  0.942569,    0.0470714, 0.291945,    0.248553,  0.544931,
     0.116195,  0.000723893, 0.178439,  0.561161,    0.177946,  0.826971,
     0.51557,   0.853266,    0.130726,  0.412308,    0.028304,  0.756657,
     0.859053,  0.864068,    0.0855092, 0.641641,    0.0506908, 0.20425,
     0.511209,  0.462488,    0.249729,  0.179857,    0.419772,  0.0954196,
     0.0946383, 0.0758727,   0.0340758, 0.120313,    0.928109,  0.28784,
     0.918358,  0.77621,     0.111978,  0.440554,    0.558309,  0.417402,
     0.290477,  0.261678,    0.0230194, 0.993258,    0.504107,  0.532505,
     0.0377729, 0.424735,    0.189859,  0.571203,    0.577828,  0.875389,
     0.0146955, 0.417194,    0.365765,  0.332846,    0.0860698, 0.523081,
     0.911015,  0.233071,    0.179576,  0.14205,     0.171023,  0.151935,
     0.361656,  0.792872,    0.782316,  0.93938,     0.7748,    0.32355,
     0.284068,  0.819871,    0.211825,  0.813257,    0.0904989, 0.823944,
     0.307751,  0.884175,    0.211666,  0.955764,    0.728598,  0.985048,
     0.992403,  0.0114441,   0.565399,  0.407367,    0.11905,   0.969464,
     0.839061,  0.00291545,  0.795435,  0.809132,    0.112986,  0.923361,
     0.900158,  0.920193,    0.751823,  0.000532912, 0.729607,  0.998227,
     0.519071,  0.29597},
    {0.591638,    0.636289,  0.422768, 0.395866,   0.211963,   0.247561,
     0.873861,    0.826076,  0.405578, 0.836911,   0.19576,    0.612142,
     0.18546,     0.510143,  0.758867, 0.680525,   0.303096,   0.343223,
     0.635574,    0.297095,  0.714433, 0.542134,   0.65419,    0.415042,
     0.0203925,   0.81565,   0.35969,  0.34546,    0.188946,   0.316695,
     0.0506854,   0.308055,  0.623375, 0.779122,   0.763023,   0.469727,
     0.217242,    0.558964,  0.758596, 0.0507151,  0.875032,   0.257227,
     0.293436,    0.668918,  0.287161, 0.965594,   0.610805,   0.983815,
     0.423725,    0.372691,  0.646755, 0.67113,    0.408597,   0.12956,
     0.518326,    0.147778,  0.654971, 0.0380787,  0.235283,   0.520791,
     0.982096,    0.801053,  0.209694, 0.132911,   0.81271,    0.126016,
     0.000823383, 0.245849,  0.951413, 0.921352,   0.787548,   0.600685,
     0.384549,    0.0364564, 0.317536, 0.0750908,  0.601381,   0.844494,
     0.753705,    0.711868,  0.170619, 0.335501,   0.811165,   0.262743,
     0.0243641,   0.539878,  0.71371,  0.342767,   0.290609,   0.835519,
     0.721345,    0.876943,  0.84867,  0.319245,   0.162595,   0.437271,
     0.19737,     0.76698,   0.183234, 0.155428,   0.183469,   0.63555,
     0.103769,    0.223141,  0.415432, 0.0665388,  0.00797002, 0.325325,
     0.880343,    0.658112,  0.122086, 0.546389,   0.0888305,  0.80826,
     0.552814,    0.556473,  0.800364, 0.754823,   0.469252,   0.163692,
     0.188445,    0.865722,  0.768626, 0.44635,    0.424309,   0.815645,
     0.835375,    0.697429,  0.60281,  0.371962,   0.274619,   0.8149,
     0.0331627,   0.897103,  0.208711, 0.283816,   0.0696402,  0.226151,
     0.0907355,   0.67835,   0.835561, 0.909564,   0.605946,   0.20477,
     0.703696,    0.459131,  0.549814, 0.00917075, 0.415014,   0.061494,
     0.87852,     0.0593261, 0.594275, 0.474482,   0.390311,   0.721786,
     0.273103,    0.583405,  0.488876, 0.402945,   0.694147,   0.546671,
     0.25904,     0.829721,  0.750718, 0.540117,   0.426444,   0.831752,
     0.854278,    0.990353,  0.62652,  0.191534,   0.493501,   0.318053,
     0.946845,    0.886603,  0.175397, 0.49797,    0.358406,   0.151143,
     0.277542,    0.56471,   0.895831, 0.892485,   0.358059,   0.346329,
     0.117409,    0.923212,  0.658857, 0.666974,   0.192667,   0.777487,
     0.44156,     0.626614,  0.224419, 0.31146,    0.757435,   0.844472,
     0.8116,      0.0472695},
    {0.39431,    0.547262,  0.448347,   0.45024,   0.166339,  0.865365,
     0.410324,   0.877727,  0.841359,   0.863944,  0.723107,  0.103615,
     0.0650918,  0.340912,  0.31339,    0.686768,  0.539059,  0.423542,
     0.626467,   0.232913,  0.17608,    0.136728,  0.466456,  0.689392,
     0.0954863,  0.3073,    0.238049,   0.879872,  0.246813,  0.0195305,
     0.419536,   0.813977,  0.397819,   0.7883,    0.687234,  0.422725,
     0.533351,   0.721639,  0.032945,   0.600207,  0.661527,  0.0614829,
     0.909136,   0.0143667, 0.897914,   0.345017,  0.0863976, 0.489777,
     0.0553691,  0.0416336, 0.864652,   0.672873,  0.728746,  0.307559,
     0.656241,   0.467472,  0.152018,   0.709557,  0.176419,  0.157512,
     0.757657,   0.848782,  0.302478,   0.504098,  0.848058,  0.839425,
     0.0240872,  0.994071,  0.931477,   0.727619,  0.942591,  0.720556,
     0.196745,   0.777894,  0.54076,    0.498661,  0.396181,  0.723608,
     0.845694,   0.871391,  0.558211,   0.926431,  0.988746,  0.43516,
     0.209795,   0.0964158, 0.378823,   0.528744,  0.133892,  0.831603,
     0.732419,   0.8419,    0.3076,     0.182955,  0.702511,  0.771428,
     0.0885248,  0.888234,  0.324568,   0.0121888, 0.689718,  0.909797,
     0.582541,   0.480069,  0.368366,   0.437386,  0.437186,  0.35191,
     0.409932,   0.661422,  0.00995849, 0.0990186, 0.699594,  0.976366,
     0.487516,   0.376438,  0.0485558,  0.335864,  0.162081,  0.468969,
     0.00525685, 0.492157,  0.0439198,  0.17505,   0.636044,  0.685866,
     0.311211,   0.731265,  0.524531,   0.218513,  0.0866065, 0.0565639,
     0.982473,   0.0370698, 0.619762,   0.228532,  0.364461,  0.788542,
     0.319818,   0.260687,  0.363064,   0.221964,  0.680899,  0.41695,
     0.342358,   0.647487,  0.375685,   0.708301,  0.0806305, 0.362588,
     0.622694,   0.0365345, 0.533612,   0.609536,  0.673393,  0.052741,
     0.20313,    0.0771774, 0.474029,   0.31372,   0.897913,  0.962481,
     0.244322,   0.157342,  0.877621,   0.836768,  0.257154,  0.836631,
     0.126502,   0.18961,   0.537619,   0.451673,  0.206085,  0.058476,
     0.900746,   0.24398,   0.26526,    0.495436,  0.331819,  0.419546,
     0.697457,   0.109725,  0.366156,   0.482683,  0.558423,  0.381347,
     0.316513,   0.0883416, 0.656767,   0.382156,  0.905291,  0.160704,
     0.590566,   0.29787,   0.289635,   0.382696,  0.265138,  0.00751033,
     0.213664,   0.725723},
    {0.435547,  0.106154,   0.264738,  0.652204,  0.579838, 0.627526,
     0.478684,  0.263754,   0.484047,  0.0786758, 0.440299, 0.0290185,
     0.730877,  0.847697,   0.498738,  0.936971,  0.412352, 0.611171,
     0.907529,  0.21118,    0.36095,   0.926856,  0.424362, 0.381634,
     0.036057,  0.382316,   0.364709,  0.391857,  0.787946, 0.630612,
     0.0575748, 0.0174192,  0.0549202, 0.787212,  0.453513, 0.668383,
     0.454617,  0.610677,   0.822714,  0.791853,  0.193041, 0.000166261,
     0.517035,  0.0122621,  0.275708,  0.145649,  0.83023,  0.0959619,
     0.528566,  0.623962,   0.822993,  0.734642,  0.214382, 0.461908,
     0.668286,  0.00128942, 0.147739,  0.712636,  0.407792, 0.225428,
     0.719759,  0.630664,   0.386077,  0.71469,   0.636657, 0.483029,
     0.55586,   0.91259,    0.210285,  0.730003,  0.311946, 0.15151,
     0.991987,  0.255514,   0.254148,  0.797331,  0.100663, 0.497052,
     0.104883,  0.298844,   0.444006,  0.0967915, 0.490322, 0.0166496,
     0.563637,  0.752482,   0.299515,  0.148524,  0.134678, 0.388523,
     0.85626,   0.39231,    0.0743322, 0.122436,  0.78777,  0.0335901,
     0.359498,  0.686882,   0.956408,  0.18208,   0.732442, 0.452594,
     0.803986,  0.133088,   0.734421,  0.680263,  0.166912, 0.367866,
     0.581568,  0.932467,   0.58589,   0.134837,  0.969066, 0.950252,
     0.167576,  0.794432,   0.543111,  0.17031,   0.187708, 0.540931,
     0.959345,  0.0219591,  0.0977137, 0.303224,  0.212556, 0.718865,
     0.0445721, 0.231226,   0.207803,  0.59964,   0.746299, 0.189915,
     0.347533,  0.273147,   0.67543,   0.631082,  0.205583, 0.849562,
     0.882352,  0.450059,   0.319302,  0.65942,   0.394617, 0.87023,
     0.981822,  0.388044,   0.790815,  0.745017,  0.149024, 0.206558,
     0.423275,  0.225311,   0.0264265, 0.625038,  0.194572, 0.0730115,
     0.873562,  0.888333,   0.52873,   0.558154,  0.398733, 0.0371469,
     0.411828,  0.58328,    0.553325,  0.307813,  0.296486, 0.678687,
     0.984544,  0.754887,   0.460109,  0.138306,  0.66067,  0.801133,
     0.1397,    0.186334,   0.112219,  0.517365,  0.86614,  0.751432,
     0.584105,  0.528555,   0.627648,  0.433243,  0.512529, 0.633978,
     0.987266,  0.644459,   0.921432,  0.673418,  0.260498, 0.957565,
     0.399846,  0.223005,   0.30514,   0.924137,  0.195977, 0.658929,
     0.218698,  0.871597},
};

static const std::vector<float> costs = {
    526.996, 465.418, 717.076, 469.406, 741.764, 141.945, 670.951, 153.968,
    108.571, 377.586, 535.011, 338.59,  654.503, 451.487, 805.469, 880.876,
    648.74,  320.629, 169.238, 205.096, 622.668, 347.488, 885.28,  764.058,
    982.845, 477.737, 928.441, 306.516, 568.51,  75.1759, 526.205, 224.092,
    693.71,  207.292, 302.555, 801.724, 596.049, 556.878, 102.571, 182.047,
    954.894, 742.984, 988.127, 864.088, 865.441, 829.416, 489.048, 506.983,
    627.27,  332.116, 316.277, 62.2874, 306.691, 847.312, 618.82,  975.084,
    975.169, 342.466, 455.351, 38.9985, 918.42,  76.8792, 482.816, 747.871,
    349.028, 575.064, 664.057, 655.501, 690.355, 543.75,  185.91,  834.892,
    486.158, 976.762, 614.691, 244.933, 782.91,  416.506, 705.864, 519.771,
    565.236, 746.62,  503.077, 656.874, 632.707, 349.927, 293.344, 573.553,
    539.654, 423.63,  994.67,  796.744, 182.341, 273.129, 155.04,  568.693,
    747.608, 167.37,  629.054, 929.504, 946.209, 848.861, 25.0838, 42.9434,
    180.275, 940.566, 447.489, 777.155, 859.781, 656.1,   250.96,  989.305,
    754.617, 983.134, 123.575, 553.381, 178.484, 814.594, 587.722, 746.104,
    819.689, 344.098, 662.455, 174.66,  285.461, 572.919, 829.168, 290.751,
    581.264, 367.214, 553.023, 186.284, 316.19,  937.196, 59.1581, 974.272,
    291.577, 30.3794, 753.033, 99.3955, 451.62,  457.88,  339.217, 866.964,
    628.019, 3.44008, 233.508, 947.408, 966.867, 770.796, 625.564, 440.388,
    540.425, 505.777, 758.754, 938.68,  854.584, 36.4228, 353.92,  723.541,
    488.899, 464.898, 943.101, 900.451, 360.087, 259.795, 925.979, 820.23,
    182.19,  779.671, 922.625, 391.649, 76.1197, 370.845, 688.757, 538.554,
    64.5752, 940.919, 133.591, 707.412, 192.271, 410.152, 490.862, 638.072,
    541.896, 967.492, 657.479, 917.044, 287.333, 569.839, 803.32,  593.237,
    394.441, 927.122, 449.202, 800.01,  269.112, 712.508, 930.232, 400.302};

static const std::vector<float> min_impressions = {
    0.237999,  0.659373, 0.872503, 0.770638, 0.282655,
    0.0680171, 0.65466,  0.18719,  0.919096, 0.620676};

//
#endif
