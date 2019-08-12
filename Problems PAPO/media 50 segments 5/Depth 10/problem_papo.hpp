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
    cons_incl(
        cons_excl(
            cons_indep(
                cons_incl(cons_excl(cons_excl(cons_indep(
                                                  cons_indep(
                                                      cons_excl(cons_indep(
                                                                    events[17],
                                                                    events[35]),
                                                                events[28]),
                                                      events[8]),
                                                  events[47]),
                                              events[40]),
                                    events[1]),
                          events[41]),
                events[27]),
            events[14]),
        events[43]),
    cons_indep(
        cons_indep(
            cons_indep(
                cons_excl(
                    cons_incl(cons_excl(cons_indep(
                                            cons_indep(
                                                cons_excl(cons_excl(events[16],
                                                                    events[33]),
                                                          events[47]),
                                                events[39]),
                                            events[28]),
                                        events[14]),
                              events[41]),
                    events[10]),
                events[43]),
            events[11]),
        events[38]),
    cons_excl(
        cons_indep(
            cons_indep(
                cons_incl(
                    cons_indep(
                        cons_indep(
                            cons_incl(cons_excl(cons_incl(cons_incl(events[37],
                                                                    events[49]),
                                                          events[43]),
                                                events[12]),
                                      events[16]),
                            events[4]),
                        events[6]),
                    events[21]),
                events[44]),
            events[17]),
        events[22]),
    cons_indep(
        cons_indep(
            cons_incl(
                cons_indep(
                    cons_indep(
                        cons_excl(cons_incl(cons_excl(cons_indep(
                                                          cons_incl(events[30],
                                                                    events[22]),
                                                          events[1]),
                                                      events[32]),
                                            events[34]),
                                  events[7]),
                        events[8]),
                    events[5]),
                events[41]),
            events[17]),
        events[40]),
    cons_excl(
        cons_excl(
            cons_incl(
                cons_excl(
                    cons_incl(
                        cons_incl(cons_excl(cons_indep(
                                                cons_excl(cons_indep(events[27],
                                                                     events[9]),
                                                          events[42]),
                                                events[37]),
                                            events[20]),
                                  events[3]),
                        events[38]),
                    events[17]),
                events[19]),
            events[26]),
        events[41])};
static const std::vector<std::vector<float>> prob = {
    {0.631033,  0.698346, 0.352917, 0.399743, 0.559478, 0.838732, 0.271945,
     0.564466,  0.676284, 0.731382, 0.879201, 0.608021, 0.238042, 0.638945,
     0.484369,  0.728369, 0.955773, 0.95575,  0.528554, 0.920527, 0.718022,
     0.860818,  0.46885,  0.969954, 0.612645, 0.929958, 0.168908, 0.14775,
     0.366987,  0.952917, 0.232792, 0.181325, 0.262523, 0.311806, 0.607743,
     0.984029,  0.919481, 0.278643, 0.196709, 0.394666, 0.2425,   0.175298,
     0.0458738, 0.678603, 0.649335, 0.932161, 0.675759, 0.767505, 0.44252,
     0.0328367},
    {0.244023, 0.538954,   0.856582,  0.615714,  0.845078,  0.0121953, 0.479973,
     0.27902,  0.971628,   0.333551,  0.0130012, 0.251186,  0.831347,  0.804584,
     0.279248, 0.551662,   0.60907,   0.926196,  0.800121,  0.521717,  0.889362,
     0.901496, 0.908395,   0.0423856, 0.54539,   0.901498,  0.422209,  0.92278,
     0.727518, 0.468846,   0.406541,  0.640274,  0.121465,  0.479614,  0.410253,
     0.187181, 0.00730488, 0.643905,  0.15696,   0.153512,  0.800574,  0.576726,
     0.972356, 0.0145816,  0.413562,  0.218977,  0.0867398, 0.172357,  0.285239,
     0.708384},
    {0.386731,  0.164435, 0.0685383, 0.276755,  0.2065,    0.093809, 0.0958318,
     0.212489,  0.697855, 0.36616,   0.0176737, 0.911367,  0.972005, 0.711604,
     0.153628,  0.234728, 0.476404,  0.628828,  0.0857488, 0.263699, 0.00478773,
     0.0220859, 0.852844, 0.877631,  0.75664,   0.454513,  0.367941, 0.491172,
     0.643534,  0.093727, 0.291541,  0.569417,  0.73059,   0.349944, 0.705319,
     0.322301,  0.831415, 0.745404,  0.761948,  0.848313,  0.654184, 0.269858,
     0.784099,  0.820139, 0.26955,   0.305578,  0.123014,  0.491594, 0.739009,
     0.693737},
    {0.860626, 0.663715, 0.774899,  0.38734,   0.603053,  0.413865,  0.534911,
     0.276263, 0.454944, 0.584078,  0.703377,  0.0900746, 0.282437,  0.917681,
     0.179301, 0.299236, 0.0645857, 0.188602,  0.456433,  0.370901,  0.368414,
     0.508583, 0.441119, 0.269654,  0.78544,   0.716064,  0.32821,   0.0722327,
     0.212541, 0.829888, 0.753148,  0.285394,  0.355387,  0.29584,   0.347136,
     0.682412, 0.784869, 0.296981,  0.550837,  0.957088,  0.0899006, 0.89271,
     0.244239, 0.471772, 0.428266,  0.0886448, 0.305724,  0.220507,  0.549558,
     0.692335},
    {0.562667, 0.426335,  0.493863, 0.214338,  0.728161,  0.0885798,  0.547596,
     0.724561, 0.0195454, 0.895788, 0.8368,    0.641404,  0.76738,    0.317303,
     0.423014, 0.787388,  0.48609,  0.812023,  0.936446,  0.636855,   0.623664,
     0.977516, 0.576862,  0.771266, 0.317446,  0.836228,  0.162891,   0.734199,
     0.41056,  0.642938,  0.487792, 0.0399037, 0.0208319, 0.00923235, 0.0955685,
     0.654852, 0.0431052, 0.108467, 0.696541,  0.993748,  0.962778,   0.670734,
     0.429447, 0.877383,  0.7615,   0.0269705, 0.677557,  0.743157,   0.740363,
     0.806288},
};

static const std::vector<float> costs = {
    611.838, 783.793, 668.685, 63.4667, 681.742, 884.651, 739.724, 949.139,
    840.123, 84.0085, 819.853, 911.574, 93.8785, 145.348, 944.399, 418.633,
    223.482, 613.532, 455.814, 669.103, 900.462, 923.141, 897.32,  60.6964,
    701.493, 870.062, 199.054, 452.945, 343.493, 607.269, 30.9029, 579.39,
    195.125, 841.307, 208.921, 377.443, 270.588, 117.825, 972.866, 925.452,
    277.711, 911.496, 440.277, 943.56,  653.488, 367.356, 259.195, 701.163,
    439.539, 357.105};

static const std::vector<float> min_impressions = {0.418684, 0.327584, 0.117532,
                                                   0.249809, 0.39891};

//
#endif
