#ifndef TESTING_H
#define TESTING_H

#include <cassert>
#include <iostream>
#include <vector>

#include "adn.hpp"
#include "config.hpp"
#include "greedy.hpp"
#include "population.hpp"
#include "random_utils.hpp"

template <typename T> void test_f(T &pop) {
  auto data_fitness = std::vector<std::vector<float>>(0);
  auto data_entropy = std::vector<std::vector<float>>(0);
  auto data_feasibility = std::vector<std::vector<float>>(0);

  for (int i = 0; i < MAX_TEST_ITERATIONS; i++) {
    pop = T(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    pop.evolve(MAX_ITERATIONS, data_fitness, data_entropy, data_feasibility);
  }

  // std::cout << "Data Fitness" << std::endl;
  for (auto &&data : data_fitness) {
    for (auto &&x : data) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  //std::cout << "Data Entropy" << std::endl;
  for (auto &&data : data_entropy) {
    for (auto &&x : data) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  //std::cout << "Data Feasibles" << std::endl;
  for (auto &&data : data_feasibility) {
    for (auto &&x : data) {
      std::cout << x << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void test_all() {

  typedef std::vector<bool> Dna_t;

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RandomS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RandomS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          RandomSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RandomS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_PropS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_PropS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          ProportionalSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_PropS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>, RankSelection,
                          StandardReplacement>(media, POPULATION_SIZE,
                                               POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RankS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RankS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          RankSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RankS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RouletteS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RouletteS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          RouletteWheelSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RouletteS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_StochasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_StochasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_StochasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_StochasticS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_SotchasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_StochasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_StochasticS_StandardR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          StochasticSelection, StandardReplacement>(
        media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_StochasticS_StandardR, ";
    test_f(pop);
  }

  {
    auto pop =
        Population<Dna<Dna_t, UniformCrossover, SwapMutation>, RandomSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, OnePointCrossover, SwapMutation>, RandomSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>, RandomSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, AndCrossover, SwapMutation>, RandomSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RandomS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          RandomSelection, qNNR>(media, POPULATION_SIZE,
                                                 POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          RandomSelection, qNNR>(media, POPULATION_SIZE,
                                                 POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          RandomSelection, qNNR>(media, POPULATION_SIZE,
                                                 POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RandomS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, AndCrossover, RandomMutation>, RandomSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RandomS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_PropS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_PropS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          ProportionalSelection, qNNR>(media, POPULATION_SIZE,
                                                       POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_PropS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop =
        Population<Dna<Dna_t, UniformCrossover, SwapMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, OnePointCrossover, SwapMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, AndCrossover, SwapMutation>, RankSelection, qNNR>(
            media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RankS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop =
        Population<Dna<Dna_t, UniformCrossover, RandomMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, OnePointCrossover, RandomMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RankS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, AndCrossover, RandomMutation>, RankSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RankS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, SwapMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_RouletteS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_RouletteS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          RouletteWheelSelection, qNNR>(media, POPULATION_SIZE,
                                                        POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_RouletteS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, SwapMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_SwapM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, SwapMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_SwapM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, SwapMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_SwapM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop =
        Population<Dna<Dna_t, AndCrossover, SwapMutation>, StochasticSelection,
                   qNNR>(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    std::cout << "AndC_SwapM_StochasticS_qNNR, ";
    test_f(pop);
  }

  {
    auto pop = Population<Dna<Dna_t, UniformCrossover, RandomMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "UniformC_RandomM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, OnePointCrossover, RandomMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "OnePointC_RandomM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, TwoPointCrossover, RandomMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "TwoPointC_RandomM_StochasticS_qNNR, ";
    test_f(pop);
  }
  {
    auto pop = Population<Dna<Dna_t, AndCrossover, RandomMutation>,
                          StochasticSelection, qNNR>(media, POPULATION_SIZE,
                                                     POOL_SIZE, ELLITISTS);
    std::cout << "AndC_RandomM_StochasticS_qNNR, ";
    test_f(pop);
  }
}

void test_group() {
  typedef Population<Dna<std::vector<bool>, UniformCrossover, RandomMutation>,
                     RandomSelection, qNNR>
      pop1;
  typedef Population<Dna<std::vector<bool>, UniformCrossover, RandomMutation>,
                     ProportionalSelection, qNNR>
      pop2;
  typedef Population<Dna<std::vector<bool>, UniformCrossover, RandomMutation>,
                     RouletteWheelSelection, qNNR>
      pop3;
  typedef Population<Dna<std::vector<bool>, UniformCrossover, RandomMutation>,
                     StochasticSelection, qNNR>
      pop4;

  {
    auto pop = pop1(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    test_f(pop);
  }
  {
    auto pop = pop2(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    test_f(pop);
  }
  {
    auto pop = pop3(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    test_f(pop);
  }
  {
    auto pop = pop4(media, POPULATION_SIZE, POOL_SIZE, ELLITISTS);
    test_f(pop);
  }
}

#endif
