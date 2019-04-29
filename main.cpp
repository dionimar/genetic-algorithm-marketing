#include <ctime>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>

#include "adn.hpp"
#include "config.hpp"
#include "generate_problem.hpp"
#include "greedy.hpp"
#include "population.hpp"
#include "problem.hpp"
#ifdef TESTING
#include "testing.hpp"
#endif


int main(int argc, char **argv) {

#if _WIN32
  std::srand(time(nullptr));
#else
  std::srand(std::time(nullptr));
#endif

  // print_problem(20, 50, 5, 1, 1000);
#ifdef TESTING
  test_group();
#else
  // typedef dna<std::vector<bool>, UniformCrossover, RandomMutation> dna_type;
  // typedef population<dna_type, RandomSelection, StandardReplacement> popul1;
  // typedef population<dna_type, ProportionalSelection, StandardReplacement> popul2;
  // typedef population<dna_type, RankSelection, StandardReplacement> popul3;
  // typedef population<dna_type, StochasticSelection, StandardReplacement> popul4;
  // // typedef population<dna_type, qnnSelection, qNNR> popul5;

  // // typedef population<dna_type, qnnSelection, qNNR> popul1;
  // // typedef population<dna_type, qnnSelection, qNNR> popul2;
  // // typedef population<dna_type, qnnSelection, StandardReplacement> popul3;
  // // typedef population<dna_type, qnnSelection, StandardReplacement> popul4;
  // // typedef population<dna_type, qnnSelection, qNNR> popul5;

  // // NON TESTING ALTERNATIVE
  // // auto pop1 = popul1(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  // // auto pop2 = popul2(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  // // auto pop3 = popul3(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  // auto pop4 = popul4(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  // // auto pop5 = popul5(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);

  // pop4.evolve(MAX_ITERATIONS);

  // // std::thread t1 (&popul1::evolve, &pop1, MAX_ITERATIONS);
  // // std::thread t2 (&popul2::evolve, &pop2, MAX_ITERATIONS);
  // // std::thread t3 (&popul3::evolve, &pop3, MAX_ITERATIONS);
  // // std::thread t4 (&popul4::evolve, &pop4, MAX_ITERATIONS);
  // // // std::thread t5 (&popul5::evolve, &pop5, MAX_ITERATIONS);
  // // t1.join();
  // // t2.join();
  // // t3.join();
  // // t4.join();
  // // t5.join();

  // std::cout << "----------------GREEDY SOLUTION-------------------------------"
  //           << std::endl;
#ifdef PAPO
  // auto x = greedy_papo(restrictions, min_impressions, prob);
#endif
#ifdef APO
  // auto x = greedy_apo(media, restrictions, min_impressions, costs);
#endif
  // auto greedy_adn = dna<std::vector<bool> >(x);
  // greedy_adn.comp_fitness();

  // greedy_adn.show_info();
#endif

  return 0;
}
