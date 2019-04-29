#ifndef PROBLEM_H
#define PROBLEM_H
#include <iostream>
#include "syntax_tree.hpp"


#define PAPO




static const int media = 50;
static const int segments = 5;


static const std::vector<Syntax_Tree> events = {cons_event(0), cons_event(1), cons_event(2), cons_event(3), cons_event(4), cons_event(5), cons_event(6), cons_event(7), cons_event(8), cons_event(9), cons_event(10), cons_event(11), cons_event(12), cons_event(13), cons_event(14), cons_event(15), cons_event(16), cons_event(17), cons_event(18), cons_event(19), cons_event(20), cons_event(21), cons_event(22), cons_event(23), cons_event(24), cons_event(25), cons_event(26), cons_event(27), cons_event(28), cons_event(29), cons_event(30), cons_event(31), cons_event(32), cons_event(33), cons_event(34), cons_event(35), cons_event(36), cons_event(37), cons_event(38), cons_event(39), cons_event(40), cons_event(41), cons_event(42), cons_event(43), cons_event(44), cons_event(45), cons_event(46), cons_event(47), cons_event(48), cons_event(49)};

static const std::vector<Syntax_Tree> restrictions = {cons_excl(cons_incl(cons_excl(cons_incl(cons_excl(events[5], events[47]),events[44]),events[45]),events[15]),events[11]),cons_indep(cons_excl(cons_incl(cons_incl(cons_incl(events[31], events[22]),events[7]),events[19]),events[49]),events[48]),cons_indep(cons_excl(cons_indep(cons_indep(cons_excl(events[21], events[30]),events[25]),events[1]),events[33]),events[10]),cons_excl(cons_incl(cons_incl(cons_incl(cons_indep(events[23], events[4]),events[7]),events[28]),events[8]),events[46]),cons_incl(cons_incl(cons_indep(cons_excl(cons_excl(events[20], events[18]),events[23]),events[48]),events[19]),events[10])};


static const std::vector< std::vector<float> > prob = {{0.822209, 0.261032, 0.146348, 0.0973521, 0.692593, 0.096215, 0.662429, 0.378399, 0.277459, 0.746981, 0.827267, 0.479914, 0.550344, 0.367471, 0.943345, 0.153513, 0.0193187, 0.520057, 0.698235, 0.586553, 0.59685, 0.318885, 0.0283289, 0.765848, 0.96483, 0.707037, 0.0371554, 0.423857, 0.969928, 0.705802, 0.557433, 0.84932, 0.599189, 0.616317, 0.77607, 0.495813, 0.00269403, 0.953747, 0.299898, 0.717526, 0.385773, 0.381324, 0.755593, 0.181442, 0.942971, 0.821512, 0.266854, 0.699747, 0.301234, 0.620367},
{0.000538533, 0.748472, 0.205899, 0.942264, 0.623311, 0.398765, 0.779689, 0.290426, 0.343348, 0.221104, 0.574166, 0.603056, 0.779457, 0.569637, 0.347272, 0.812309, 0.551051, 0.246411, 0.632877, 0.275993, 0.320637, 0.0480728, 0.663214, 0.374507, 0.526643, 0.320644, 0.64267, 0.258303, 0.503555, 0.129364, 0.270143, 0.749973, 0.466379, 0.0884124, 0.421455, 0.369519, 0.846249, 0.699605, 0.4138, 0.942159, 0.50691, 0.471534, 0.980407, 0.178935, 0.486839, 0.29612, 0.02415, 0.940299, 0.526597, 0.0187839},
{0.543969, 0.449926, 0.19433, 0.772079, 0.629697, 0.487578, 0.114988, 0.603998, 0.549194, 0.0267997, 0.266725, 0.890291, 0.348152, 0.774055, 0.954058, 0.464457, 0.975232, 0.564736, 0.567529, 0.289189, 0.822763, 0.0385774, 0.139823, 0.907595, 0.0988523, 0.572419, 0.799778, 0.328693, 0.893936, 0.358667, 0.112828, 0.20612, 0.312684, 0.127365, 0.546061, 0.759775, 0.449663, 0.824032, 0.693741, 0.877022, 0.363702, 0.589047, 0.596098, 0.617964, 0.718898, 0.213688, 0.663715, 0.00315926, 0.551521, 0.0202815},
{0.692678, 0.389231, 0.134029, 0.627239, 0.891992, 0.772852, 0.122777, 0.935566, 0.60956, 0.832412, 0.846509, 0.62136, 0.588605, 0.29013, 0.883518, 0.807815, 0.575719, 0.144903, 0.698785, 0.211096, 0.821821, 0.161651, 0.384346, 0.898047, 0.756517, 0.757616, 0.443532, 0.840713, 0.0206102, 0.288515, 0.462356, 0.706773, 0.702656, 0.537851, 0.664273, 0.381523, 0.927198, 0.887831, 0.760286, 0.508795, 0.928423, 0.149741, 0.72287, 0.979123, 0.52377, 0.708056, 0.864653, 0.231241, 0.381697, 0.791277},
{0.588279, 0.994674, 0.588282, 0.86626, 0.402003, 0.72693, 0.700506, 0.68443, 0.72904, 0.803751, 0.379366, 0.506252, 0.430489, 0.776176, 0.214837, 0.164161, 0.650048, 0.775195, 0.749104, 0.236982, 0.785887, 0.800393, 0.588902, 0.666954, 0.694676, 0.724495, 0.985767, 0.2159, 0.274804, 0.817199, 0.94899, 0.914112, 0.0401389, 0.347685, 0.785876, 0.797657, 0.322496, 0.720046, 0.472842, 0.0622317, 0.97489, 0.401357, 0.0832251, 0.0178386, 0.379864, 0.0876251, 0.609946, 0.139077, 0.202406, 0.39126},
};

static const std::vector<float> costs = {319.183, 965.482, 725.725, 936.889, 344.243, 978.599, 846.33, 982.922, 772.622, 399.156, 190.219, 353.433, 221.418, 321.969, 833.453, 497.346, 918.256, 423.181, 207.115, 903.509, 253.077, 984.754, 540.113, 421.389, 440.332, 427.361, 675.539, 933.881, 103.139, 445.717, 771.154, 624.29, 778.695, 223.957, 105.468, 403.154, 184.369, 53.0876, 724.374, 488.515, 96.5264, 737.146, 62.1705, 504.21, 563.234, 336.282, 246.406, 347.9, 796.351, 16.4147};

static const std::vector<float> min_impressions = {0.437299, 0.63087, 0.0659277, 0.0532648, 0.294484};

//
#endif
