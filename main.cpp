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

  // print_problem(20, 200, 10, 1, 1000);
#ifdef TESTING
  test_group();
#else
  typedef Dna<std::vector<bool>, UniformCrossover, RandomMutation> DnaType;
  
  typedef Population<DnaType, StochasticSelection, qNNR> popul1;
  typedef Population<DnaType, ProportionalSelection, qNNR> popul2;
  typedef Population<DnaType, RandomSelection, StandardReplacement> popul3;
  typedef Population<DnaType, RankSelection, StandardReplacement> popul4;

  // NON TESTING ALTERNATIVE
  auto pop1 = popul1(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  auto pop2 = popul2(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  auto pop3 = popul3(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
  auto pop4 = popul4(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);

  pop1.evolve(MAX_ITERATIONS);
  pop2.evolve(MAX_ITERATIONS);
  pop3.evolve(MAX_ITERATIONS);
  pop4.evolve(MAX_ITERATIONS);

#ifdef PAPO
  auto x = greedy_papo(restrictions, min_impressions, prob);
#endif
#ifdef APO
  auto x = greedy_apo(media, restrictions, min_impressions, costs);
#endif
  auto greedy_adn = Dna<std::vector<bool> >(x);
  greedy_adn.comp_fitness();
  greedy_adn.show_info();
#endif

  return 0;
}
