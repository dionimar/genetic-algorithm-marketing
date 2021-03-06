#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 50;
static const int segments = 5;

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

static const std::vector<Syntax_Tree> restrictions = {
    cons_excl(
        cons_indep(
            cons_indep(cons_indep(cons_incl(events[49], events[35]), events[2]),
                       events[25]),
            events[5]),
        events[15]),
    cons_excl(cons_excl(cons_indep(cons_excl(cons_incl(events[44], events[28]),
                                             events[43]),
                                   events[29]),
                        events[30]),
              events[3]),
    cons_indep(cons_incl(cons_excl(cons_incl(cons_indep(events[38], events[42]),
                                             events[35]),
                                   events[6]),
                         events[13]),
               events[30]),
    cons_incl(cons_indep(cons_incl(cons_incl(cons_indep(events[45], events[44]),
                                             events[47]),
                                   events[13]),
                         events[32]),
              events[30]),
    cons_excl(cons_indep(cons_excl(cons_excl(cons_incl(events[37], events[1]),
                                             events[28]),
                                   events[13]),
                         events[24]),
              events[6])};
static const std::vector<std::vector<float>> prob = {
    {0.395483,  0.358102,  0.388387,   0.944465,  0.744715,  0.0722365,
     0.950366,  0.503565,  0.00200949, 0.823198,  0.513395,  0.577191,
     0.913247,  0.0458295, 0.532805,   0.960602,  0.0444249, 0.312818,
     0.63309,   0.50517,   0.17869,    0.515277,  0.192345,  0.588826,
     0.358062,  0.895236,  0.96319,    0.360232,  0.248041,  0.91078,
     0.110762,  0.826159,  0.593823,   0.534437,  0.0241896, 0.775434,
     0.0646443, 0.0418864, 0.0558874,  0.0968255, 0.444951,  0.0925684,
     0.0356602, 0.369406,  0.590773,   0.938558,  0.0867119, 0.282771,
     0.653181,  0.0570366},
    {0.453957,  0.677508, 0.361121, 0.31221,   0.582569, 0.199149,  0.0585782,
     0.92928,   0.552174, 0.346329, 0.0640236, 0.489698, 0.888135,  0.0398071,
     0.0885787, 0.285499, 0.227843, 0.405668,  0.175598, 0.492572,  0.0764381,
     0.637076,  0.268702, 0.878859, 0.639841,  0.858479, 0.0254911, 0.272318,
     0.466803,  0.838419, 0.511381, 0.733341,  0.724814, 0.0973975, 0.954233,
     0.928667,  0.705869, 0.587916, 0.705989,  0.794917, 0.348675,  0.332724,
     0.099444,  0.78289,  0.157164, 0.0134912, 0.725334, 0.666239,  0.63027,
     0.846904},
    {0.35245,  0.960873, 0.655785, 0.230552, 0.505254, 0.792125, 0.477008,
     0.775921, 0.304361, 0.995316, 0.353031, 0.731458, 0.115313, 0.957551,
     0.623569, 0.606627, 0.233684, 0.458099, 0.484315, 0.102144, 0.47893,
     0.025149, 0.314406, 0.866994, 0.547923, 0.887064, 0.264677, 0.580605,
     0.250844, 0.105256, 0.892514, 0.247865, 0.943016, 0.206935, 0.778935,
     0.485658, 0.699173, 0.848833, 0.249882, 0.477761, 0.401643, 0.01462,
     0.708224, 0.330701, 0.838361, 0.670729, 0.686326, 0.777053, 0.852799,
     0.987215},
    {0.0584479, 0.969923, 0.0430027, 0.0889077, 0.385188,  0.798225,  0.933463,
     0.403684,  0.275175, 0.678207,  0.278914,  0.68747,   0.505628,  0.650581,
     0.0935185, 0.532575, 0.993707,  0.309516,  0.916947,  0.382082,  0.990762,
     0.231967,  0.750016, 0.625608,  0.716253,  0.628854,  0.68211,   0.240291,
     0.285825,  0.415397, 0.843539,  0.573452,  0.226539,  0.221766,  0.82494,
     0.69395,   0.198209, 0.78505,   0.942918,  0.542368,  0.658796,  0.408433,
     0.709612,  0.202817, 0.882895,  0.988619,  0.0775872, 0.0379998, 0.850398,
     0.195516},
    {0.306022, 0.932229, 0.597909,  3.44015e05, 0.36725,   0.244937,  0.821835,
     0.751869, 0.261768, 0.917823,  0.992511,   0.0873741, 0.804719,  0.829107,
     0.520693, 0.692165, 0.583884,  0.19159,    0.230305,  0.0210758, 0.245204,
     0.797917, 0.195343, 0.870403,  0.0354215,  0.0984865, 0.527088,  0.161765,
     0.495027, 0.885001, 0.0296022, 0.508168,   0.701082,  0.38888,   0.683797,
     0.440938, 0.202111, 0.349922,  0.744219,   0.0770248, 0.707693,  0.79727,
     0.410946, 0.479845, 0.251757,  0.766045,   0.147842,  0.374964,  0.448676,
     0.329044},
};

static const std::vector<float> costs = {
    792.296, 620.436, 478.537, 236.636, 640.758, 966.49,  143.431, 672.534,
    288.742, 992.474, 159.38,  83.851,  241.788, 286.125, 200.033, 984.764,
    375.491, 608.677, 560.829, 361.96,  751.436, 111.895, 401.151, 146.356,
    176.623, 677.594, 685.087, 316.998, 644.435, 934.048, 608.366, 868.619,
    225.884, 454.304, 816.328, 679.755, 716.417, 515.32,  164.308, 578.335,
    921.317, 269.999, 293.26,  43.4746, 872.173, 248.305, 467.055, 436.246,
    892.714, 311.998};

static const std::vector<float> min_impressions = {0.138646, 0.614097, 0.939139,
                                                   0.586789, 0.250837};

//
#endif
