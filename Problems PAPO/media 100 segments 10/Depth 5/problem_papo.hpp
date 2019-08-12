#ifndef PROBLEM_H
#define PROBLEM_H
#include "syntax_tree.hpp"
#include <iostream>

#define PAPO

static const int media = 100;
static const int segments = 10;

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

static const std::vector<Syntax_Tree> restrictions = {
    cons_excl(cons_excl(cons_incl(cons_excl(cons_excl(events[40], events[27]),
                                            events[70]),
                                  events[1]),
                        events[2]),
              events[22]),
    cons_indep(cons_incl(cons_excl(cons_excl(cons_indep(events[71], events[21]),
                                             events[10]),
                                   events[96]),
                         events[49]),
               events[57]),
    cons_excl(
        cons_indep(
            cons_indep(cons_excl(cons_indep(events[44], events[29]), events[1]),
                       events[4]),
            events[14]),
        events[59]),
    cons_indep(cons_excl(cons_excl(cons_indep(cons_incl(events[77], events[48]),
                                              events[71]),
                                   events[66]),
                         events[42]),
               events[28]),
    cons_indep(cons_excl(cons_excl(cons_excl(cons_indep(events[31], events[91]),
                                             events[63]),
                                   events[95]),
                         events[38]),
               events[66]),
    cons_excl(cons_incl(cons_incl(cons_incl(cons_indep(events[89], events[29]),
                                            events[21]),
                                  events[3]),
                        events[56]),
              events[46]),
    cons_indep(cons_excl(cons_indep(cons_incl(cons_excl(events[24], events[16]),
                                              events[32]),
                                    events[92]),
                         events[70]),
               events[31]),
    cons_indep(cons_incl(cons_excl(cons_incl(cons_incl(events[2], events[3]),
                                             events[88]),
                                   events[7]),
                         events[76]),
               events[74]),
    cons_excl(cons_incl(cons_excl(cons_excl(cons_excl(events[12], events[33]),
                                            events[75]),
                                  events[53]),
                        events[97]),
              events[18]),
    cons_excl(cons_excl(cons_incl(cons_indep(cons_incl(events[33], events[31]),
                                             events[28]),
                                  events[5]),
                        events[96]),
              events[6])};

static const std::vector<std::vector<float>> prob = {
    {0.68184,   0.432536,  0.340929,  0.190642,  0.694782,  0.569829,  0.174521,
     0.657062,  0.619965,  0.843407,  0.809623,  0.0253061, 0.547896,  0.904463,
     0.310965,  0.259783,  0.369347,  0.613597,  0.473987,  0.183087,  0.814049,
     0.823708,  0.278892,  0.594908,  0.0433765, 0.272697,  0.977704,  0.309843,
     0.456664,  0.953857,  0.480312,  0.222975,  0.406481,  0.818247,  0.885063,
     0.252388,  0.96026,   0.590611,  0.0497582, 0.419945,  0.0646117, 0.376934,
     0.628555,  0.0159135, 0.739229,  0.873455,  0.228761,  0.88371,   0.780294,
     0.258628,  0.0306409, 0.917078,  0.890495,  0.781115,  0.144842,  0.460503,
     0.460937,  0.364121,  0.143493,  0.685131,  0.235563,  0.725394,  0.163326,
     0.0630543, 0.213008,  0.0235425, 0.0787473, 0.526394,  0.613783,  0.229371,
     0.0558479, 0.582611,  0.163555,  0.358209,  0.463826,  0.998748,  0.368514,
     0.763448,  0.489506,  0.198947,  0.0153942, 0.133942,  0.0368549, 0.653772,
     0.859491,  0.071675,  0.382619,  0.686898,  0.0386623, 0.237276,  0.243619,
     0.173035,  0.0717792, 0.626283,  0.657491,  0.182945,  0.755503,  0.163813,
     0.321517,  0.0682142},
    {0.105393, 0.0590895, 0.553587, 0.986108,   0.967222,  0.035069,  0.519672,
     0.148413, 0.928091,  0.135877, 0.072167,   0.793955,  0.820305,  0.203109,
     0.603258, 0.729189,  0.832889, 0.00145637, 0.598902,  0.272892,  0.564111,
     0.35862,  0.943246,  0.281215, 0.858753,   0.991315,  0.269105,  0.678526,
     0.472537, 0.976384,  0.289547, 0.544226,   0.555248,  0.34236,   0.238879,
     0.233015, 0.204265,  0.170875, 0.0843473,  0.421307,  0.945625,  0.550935,
     0.276945, 0.877707,  0.404959, 0.301133,   0.98614,   0.442043,  0.602555,
     0.111405, 0.537297,  0.543266, 0.914285,   0.437562,  0.361148,  0.365403,
     0.312296, 0.575184,  0.13519,  0.904405,   0.10077,   0.254412,  0.887957,
     0.551568, 0.113898,  0.7967,   0.852538,   0.0617684, 0.0835858, 0.452815,
     0.630659, 0.457411,  0.328788, 0.666135,   0.409062,  0.0994215, 0.216175,
     0.471948, 0.538791,  0.418227, 0.779315,   0.268279,  0.971771,  0.922408,
     0.599613, 0.169998,  0.506449, 0.756672,   0.799306,  0.478986,  0.617882,
     0.448952, 0.97699,   0.523826, 0.684822,   0.549638,  0.502451,  0.867507,
     0.389,    0.629301},
    {0.393495,   0.733044, 0.497412,  0.664248, 0.470049, 0.964733,  0.535503,
     0.00841724, 0.196591, 0.0371276, 0.067653, 0.452259, 0.257511,  0.620576,
     0.964009,   0.397927, 0.0547981, 0.882874, 0.74182,  0.752925,  0.803297,
     0.355886,   0.556287, 0.927085,  0.843036, 0.123859, 0.817006,  0.516559,
     0.0349333,  0.830018, 0.562141,  0.413327, 0.237161, 0.180923,  0.761927,
     0.543077,   0.458569, 0.0142226, 0.593201, 0.425098, 0.622551,  0.787511,
     0.805916,   0.619438, 0.960178,  0.10015,  0.870136, 0.826487,  0.886525,
     0.491,      0.826909, 0.935083,  0.309848, 0.742352, 0.215126,  0.332954,
     0.0195451,  0.608383, 0.2152,    0.376402, 0.979049, 0.680519,  0.0600071,
     0.781374,   0.554429, 0.9676,    0.680263, 0.812316, 0.543991,  0.626513,
     0.665012,   0.539834, 0.126928,  0.999755, 0.296414, 0.0436038, 0.0867869,
     0.935721,   0.159021, 0.740158,  0.536623, 0.117591, 0.453076,  0.193565,
     0.7971,     0.168319, 0.956725,  0.989137, 0.62206,  0.081699,  0.559829,
     0.628388,   0.79477,  0.63849,   0.751014, 0.363148, 0.719256,  0.58331,
     0.644925,   0.261158},
    {0.470439,  0.541601,  0.394198, 0.643601,  0.427767,  0.440415,  0.989209,
     0.370301,  0.833946,  0.95995,  0.629003,  0.860111,  0.26438,   0.596503,
     0.292506,  0.880034,  0.176602, 0.839415,  0.672911,  0.694135,  0.116934,
     0.108691,  0.87754,   0.874439, 0.443796,  0.971343,  0.30984,   0.311444,
     0.123138,  0.382106,  0.940478, 0.172506,  0.23685,   0.0833187, 0.471901,
     0.505954,  0.453534,  0.183399, 0.692815,  0.294142,  0.489567,  0.405099,
     0.866461,  0.247345,  0.80293,  0.548043,  0.927248,  0.743075,  0.215675,
     0.343469,  0.489522,  0.101447, 0.578455,  0.462392,  0.448571,  0.993807,
     0.482123,  0.0334394, 0.078154, 0.237843,  0.11479,   0.267833,  0.831747,
     0.0146122, 0.581006,  0.311742, 0.571,     0.798495,  0.220973,  0.998742,
     0.0755463, 0.804366,  0.6496,   0.0398101, 0.123262,  0.988855,  0.825244,
     0.271091,  0.460383,  0.661433, 0.899589,  0.149392,  0.418019,  0.460774,
     0.369988,  0.33112,   0.520541, 0.872552,  0.0293226, 0.647177,  0.923852,
     0.752987,  0.318863,  0.72382,  0.760989,  0.937741,  0.941035,  0.739068,
     0.136992,  0.953405},
    {0.178185,  0.763003,  0.400522,   0.262233,  0.469923,  0.888461,
     0.247659,  0.655512,  0.00459001, 0.198819,  0.982732,  0.0453835,
     0.802014,  0.927576,  0.0441171,  0.268969,  0.0163982, 0.238226,
     0.668214,  0.473108,  0.0641334,  0.977547,  0.882544,  0.406294,
     0.0363326, 0.318638,  0.140683,   0.429679,  0.674121,  0.345756,
     0.932071,  0.589325,  0.990807,   0.779923,  0.600455,  0.804961,
     0.866084,  0.270693,  0.027372,   0.0534643, 0.14293,   0.635052,
     0.236082,  0.621514,  0.146544,   0.283011,  0.939066,  0.573044,
     0.175305,  0.0167116, 0.269514,   0.912712,  0.932772,  0.193703,
     0.0324186, 0.962669,  0.51634,    0.755985,  0.32882,   0.218888,
     0.598731,  0.349093,  0.732284,   0.856272,  0.330026,  0.625813,
     0.424895,  0.381073,  0.422215,   0.714628,  0.242868,  0.198486,
     0.202894,  0.11224,   0.726222,   0.0881723, 0.597335,  0.847613,
     0.261451,  0.532606,  0.548334,   0.489027,  0.622839,  0.561281,
     0.438622,  0.542979,  0.361865,   0.526258,  0.252242,  0.403839,
     0.259117,  0.914016,  0.0282611,  0.678376,  0.772709,  0.793188,
     0.832426,  0.888945,  0.507997,   0.631322},
    {0.521298,   0.936965,  0.414205,  0.0430674, 0.111625,  0.608086,
     0.475645,   0.0881414, 0.4733,    0.543198,  0.249611,  0.903482,
     0.97108,    0.434601,  0.78441,   0.719652,  0.0670472, 0.521964,
     0.782737,   0.623631,  0.868224,  0.977337,  0.786977,  0.953274,
     0.855219,   0.589925,  0.0448013, 0.746297,  0.560443,  0.927155,
     0.173695,   0.994851,  0.0398611, 0.919347,  0.136873,  0.86348,
     0.41623,    0.2743,    0.350922,  0.613342,  0.338855,  0.908928,
     0.708866,   0.766453,  0.261551,  0.0356331, 0.880397,  0.528281,
     0.00527425, 0.793357,  0.0561899, 0.403153,  0.032107,  0.134525,
     0.0362215,  0.346292,  0.540873,  0.680425,  0.477765,  0.0214235,
     0.116363,   0.772271,  0.888737,  0.993787,  0.785618,  0.521075,
     0.232745,   0.578249,  0.256285,  0.125384,  0.210788,  0.411263,
     0.0640173,  0.847262,  0.769561,  0.739052,  0.980113,  0.291561,
     0.6176,     0.94797,   0.595647,  0.761805,  0.21252,   0.715641,
     0.206176,   0.97237,   0.0158329, 0.488991,  0.578669,  0.690468,
     0.686475,   0.300305,  0.0195846, 0.0536616, 0.733962,  0.237508,
     0.795019,   0.653207,  0.479632,  0.507649},
    {0.0311929, 0.172671,  0.32815,   0.742973,  0.694857,  0.92518,
     0.705494,  0.841555,  0.469192,  0.27422,   0.421029,  0.203884,
     0.612134,  0.62822,   0.485653,  0.647162,  0.941997,  0.00253933,
     0.927545,  0.225713,  0.103981,  0.688828,  0.739347,  0.23655,
     0.223306,  0.629647,  0.679454,  0.603626,  0.0991978, 0.0755748,
     0.802473,  0.467142,  0.119192,  0.0528494, 0.381446,  0.97595,
     0.478091,  0.9065,    0.565666,  0.289048,  0.0202126, 0.803645,
     0.877471,  0.842672,  0.917271,  0.267601,  0.965559,  0.951794,
     0.0229335, 0.470244,  0.898239,  0.97899,   0.7929,    0.850172,
     0.28811,   0.345368,  0.891859,  0.55762,   0.73156,   0.722497,
     0.90011,   0.663338,  0.485439,  0.579687,  0.259053,  0.325041,
     0.950596,  0.0530969, 0.226766,  0.902012,  0.204972,  0.3375,
     0.086605,  0.0331682, 0.077225,  0.971148,  0.856251,  0.723087,
     0.077388,  0.385745,  0.0538511, 0.435813,  0.216935,  0.364301,
     0.161316,  0.541738,  0.501357,  0.259936,  0.50495,   0.564645,
     0.873315,  0.0392138, 0.280386,  0.260135,  0.663544,  0.72514,
     0.819697,  0.704273,  0.686398,  0.910383},
    {0.671215,  0.096093, 0.0530844, 0.081374, 0.946575,  0.198478, 0.0853966,
     0.16634,   0.893673, 0.787601,  0.256322, 0.67165,   0.175287, 0.382975,
     0.893081,  0.682629, 0.0229184, 0.174766, 0.059136,  0.589205, 0.0904665,
     0.644819,  0.84482,  0.606596,  0.929442, 0.868022,  0.617126, 0.368475,
     0.585945,  0.356618, 0.388407,  0.881666, 0.490678,  0.272756, 0.290643,
     0.0722426, 0.900019, 0.227247,  0.278136, 0.198419,  0.610517, 0.534835,
     0.610715,  0.92278,  0.180187,  0.969037, 0.111917,  0.663723, 0.451142,
     0.310951,  0.147331, 0.801542,  0.921464, 0.617993,  0.653719, 0.172331,
     0.421148,  0.855964, 0.847513,  0.245788, 0.0392339, 0.478466, 0.481435,
     0.845027,  0.737822, 0.820974,  0.84339,  0.404537,  0.457385, 0.606871,
     0.276394,  0.484048, 0.0844868, 0.249863, 0.768948,  0.321832, 0.828415,
     0.527241,  0.27189,  0.66249,   0.500401, 0.754633,  0.203207, 0.916767,
     0.375506,  0.655284, 0.716141,  0.140079, 0.865333,  0.624953, 0.827442,
     0.397103,  0.715174, 0.0318223, 0.253843, 0.0460307, 0.401608, 0.938478,
     0.123054,  0.32405},
    {0.642678, 0.743109,  0.715694,  0.575672,  0.806803, 0.314435,  0.555219,
     0.993619, 0.958829,  0.0680052, 0.679918,  0.591836, 0.0923193, 0.276404,
     0.759288, 0.979698,  0.196807,  0.0047742, 0.29062,  0.754413,  0.36357,
     0.845464, 0.82348,   0.835051,  0.490591,  0.205257, 0.431083,  0.446885,
     0.718536, 0.599608,  0.992479,  0.288096,  0.555534, 0.424428,  0.284134,
     0.859818, 0.18826,   0.210103,  0.475893,  0.697293, 0.642109,  0.554807,
     0.250102, 0.404037,  0.52894,   0.502009,  0.616969, 0.506415,  0.967232,
     0.843779, 0.820689,  0.968978,  0.737939,  0.128609, 0.601369,  0.562615,
     0.263301, 0.130326,  0.858571,  0.967417,  0.587254, 0.531663,  0.800305,
     0.777309, 0.763719,  0.279,     0.0975193, 0.408926, 0.895663,  0.437699,
     0.765426, 0.883683,  0.179691,  0.19689,   0.314916, 0.641953,  0.704704,
     0.582597, 0.0546478, 0.487166,  0.974611,  0.782547, 0.383358,  0.232792,
     0.724979, 0.381109,  0.815526,  0.312575,  0.174364, 0.0162132, 0.380893,
     0.777181, 0.722436,  0.359683,  0.492588,  0.971984, 0.544134,  0.0426782,
     0.14945,  0.778514},
    {0.967602,  0.858121, 0.810611,   0.590333, 0.214587,  0.505359,  0.229597,
     0.798095,  0.888019, 0.00812144, 0.845558, 0.95792,   0.959333,  0.0874012,
     0.147945,  0.812259, 0.953516,   0.662461, 0.121658,  0.828886,  0.45533,
     0.711891,  0.594453, 0.727433,   0.319081, 0.947256,  0.863706,  0.416596,
     0.41222,   0.788141, 0.613857,   0.342122, 0.363421,  0.0811321, 0.189166,
     0.374888,  0.483613, 0.329101,   0.569336, 0.0135302, 0.476375,  0.724676,
     0.146694,  0.844949, 0.162365,   0.38336,  0.206808,  0.332923,  0.706741,
     0.328416,  0.350793, 0.26546,    0.94462,  0.326455,  0.428848,  0.204029,
     0.722767,  0.224765, 0.266563,   0.298086, 0.288453,  0.295385,  0.376885,
     0.269932,  0.617459, 0.982019,   0.92683,  0.178903,  0.0188026, 0.470332,
     0.932695,  0.911939, 0.841342,   0.331769, 0.569122,  0.880281,  0.931386,
     0.0670717, 0.854246, 0.965963,   0.282535, 0.0672952, 0.567368,  0.469688,
     0.0208115, 0.8794,   0.0417064,  0.355118, 0.0920332, 0.991523,  0.0650152,
     0.825792,  0.017518, 0.904351,   0.590526, 0.221168,  0.566464,  0.516326,
     0.146045,  0.0550025},
};

static const std::vector<float> costs = {
    626.59,  766.012, 521.783, 461.826, 252.521, 361.292, 731.386, 113.1,
    205.409, 894.413, 120.225, 90.2592, 83.9665, 687.403, 613.994, 19.3112,
    469.447, 130.401, 439.837, 766.959, 247.768, 371.918, 962.236, 453.064,
    99.883,  377.376, 999.428, 277.463, 565.202, 683.001, 339.643, 680.729,
    799.223, 343.091, 88.9374, 705.316, 320.12,  926.969, 209.691, 32.2981,
    688.587, 579.751, 91.0361, 326.18,  179.888, 68.9414, 678.883, 752.636,
    575.75,  643.556, 280.086, 426.211, 221.492, 324.565, 185.842, 661.818,
    968.508, 131.189, 404.477, 258.622, 944.76,  556.634, 132.133, 803.003,
    380.649, 938.936, 684.096, 42.6585, 214.529, 254.267, 95.8349, 547.231,
    756.203, 352.645, 303.245, 124.014, 22.936,  143.111, 198.719, 583.595,
    542.016, 935.043, 146.377, 820.793, 627.632, 303.491, 366.528, 641.642,
    967.231, 219.131, 863.588, 730.521, 486.38,  743.625, 233.003, 856.955,
    643.107, 722.731, 167.314, 58.5993};

static const std::vector<float> min_impressions = {
    0.411339, 0.590392, 0.340115, 0.572148, 0.716022,
    0.306151, 0.674742, 0.490092, 0.265298, 0.919409};

//
#endif
