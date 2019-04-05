#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>
#include <cmath>
#include <functional>
#include <memory>
#include <mutex>
#include <random>
#include <thread>

#include "config.hpp"
#include "problem.hpp"
#include "random_utils.hpp"

// POLICY METHOS FOR MUTATION---------------------------------------------------
struct SwapMutation {
public:
  template <class T> static void mutation(T &rep);
  static void print() { std::cout << "Swap Mutation"; }
};

struct RandomMutation {
public:
  template <class T> static void mutation(T &rep);
  static void print() { std::cout << "Random Mutation"; }
};

// POLICY METHODS FOR CROSSOVER-------------------------------------------------
struct UniformCrossover {
public:
  template <class T>
  static void crossover(const T &rep1, const T &rep2, T &result);
  static void print() { std::cout << "Uniform Crossover"; }
};

struct OnePointCrossover {
public:
  template <class T>
  static void crossover(const T &rep1, const T &rep2, T &result);
  static void print() { std::cout << "One Point Crossover"; }
};

struct TwoPointCrossover {
public:
  template <class T>
  static void crossover(const T &rep1, const T &rep2, T &result);
  static void print() { std::cout << "Two Point Crossover"; }
};

struct AndCrossover {
public:
  template <class T>
  static void crossover(const T &rep1, const T &rep2, T &result);
  static void print() { std::cout << "And Crossover"; }
};

struct OrCrossover {
public:
  template <class T>
  static void crossover(const T &rep1, const T &rep2, T &result);
  static void print() { std::cout << "Or Crossover"; }
};

// POLICY METHODS FOR SELECTION-------------------------------------------------
struct RandomSelection {
public:
  template <class Pop> static void construct_pool(Pop &p);
  template <class Pop>
  static std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
  selection(Pop &p);
  static void print() { std::cout << "Random Selection"; }
};

struct ProportionalSelection {
public:
  template <class Pop> static void construct_pool(Pop &p);
  template <class Pop>
  static std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
  selection(Pop &p);
  static void print() { std::cout << "Proportional Selection"; }
};

struct RankSelection {
public:
  template <class Pop> static void construct_pool(Pop &p);
  template <class Pop>
  static std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
  selection(Pop &p);
  static void print() { std::cout << "Rank Selection"; }
};

struct RouletteWheelSelection {
public:
  template <class Pop> static void construct_pool(Pop &p);
  template <class Pop>
  static std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
  selection(Pop &p);
  static void print() { std::cout << "Roulette Wheel Selection"; }
};

struct StochasticSelection {
public:
  template <class Pop> static void construct_pool(Pop &p);
  template <class Pop>
  static std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
  selection(Pop &p);
  static void print() { std::cout << "Stochastic Universal Selection"; }
};

// POLICY METHODS FOR REPLACEMENT-----------------------------------------------
struct StandardReplacement {
public:
  template <class Pop>
  static void replace(decltype(Pop::memb_type) &member, Pop &p, int k);
  static void print() { std::cout << "Standard Replacement"; }
};

struct qNNR {
public:
  template <class Pop>
  static void replace(decltype(Pop::memb_type) &member, Pop &p, int k);
  static void print() { std::cout << "qNNR"; }
};

// IMPLEMENTATION---------------------------------------------------------------

template <class T> void SwapMutation::mutation(T &rep) {
  const int p1 = random_int_in(0, media - 1);
  const int p2 = random_int_in(0, media - 1);
  std::swap(rep.at(p1), rep.at(p2));
}

template <class T> void RandomMutation::mutation(T &rep) {
  const int position = random_int_in(0, media - 1);
  rep.at(position) = random_mutation();
}

template <class T>
void UniformCrossover::crossover(const T &rep1, const T &rep2, T &result) {
  if (rep1 != rep2) {
    auto it_rep1 = rep1.begin();
    auto it_rep2 = rep2.begin();
    auto it_result = result.begin();
    for (; it_rep1 != rep1.end() && it_rep2 != rep2.end() &&
           it_result != result.end();) {

      if (random_choice()) {
        *it_result = *it_rep1;
      } else {
        *it_result = *it_rep2;
      }

      it_rep1++;
      it_rep2++;
      it_result++;
    }
    // #endif
  } else {
    result = rep1;
  }
}

template <class T>
void OnePointCrossover::crossover(const T &rep1, const T &rep2, T &result) {
  if (rep1 != rep2) {
    const int crossover_position = random_int_in(1, media - 2);
    auto it_rep1 = rep1.begin();
    auto it_rep2 = rep2.begin();
    auto it_result = result.begin();

    for (int i = 0; i < crossover_position; i++) {
      *it_result = *it_rep1;
      ++it_rep1;
      ++it_rep2;
      ++it_result;
    }

    for (int i = crossover_position; i < media; i++) {
      *it_result = *it_rep2;
      ++it_rep2;
      ++it_result;
    }

  } else {
    result = rep1;
  }
}

template <class T>
void TwoPointCrossover::crossover(const T &rep1, const T &rep2, T &result) {
  if (rep1 != rep2) {
    const int crossover_position1 = random_int_in(1, media - 2);
    int crossover_position2 = random_int_in(1, media - 2);

    while (crossover_position2 == crossover_position1) {
      crossover_position2 = random_int_in(1, media - 2);
    }

    const int cp1 = std::min(crossover_position1, crossover_position2);
    const int cp2 = std::max(crossover_position1, crossover_position2);
    auto it_rep1 = rep1.begin();
    auto it_rep2 = rep2.begin();
    auto it_result = result.begin();

    for (int i = 0; i < cp1; i++) {
      *it_result = *it_rep1;
      ++it_rep1;
      ++it_rep2;
      ++it_result;
    }

    for (int i = cp1; i < cp2; i++) {
      *it_result = *it_rep2;
      ++it_rep1;
      ++it_rep2;
      ++it_result;
    }

    for (; it_rep1 != rep1.end() && it_result != result.end();) {
      *it_result = *it_rep1;
      ++it_rep1;
      ++it_result;
    }

  } else {
    result = rep1;
  }
}

template <class T>
void AndCrossover::crossover(const T &rep1, const T &rep2, T &result) {
  if (rep1 != rep2) {
    auto it_rep1 = rep1.begin();
    auto it_rep2 = rep2.begin();
    auto it_result = result.begin();

    for (; it_rep1 != rep1.end() && it_rep2 != rep2.end() &&
           it_result != result.end();) {
      *it_result = *it_rep1 && *it_rep2;
      ++it_rep1;
      ++it_rep2;
      ++it_result;
    }

  } else {
    result = rep1;
  }
}

template <class T>
void OrCrossover::crossover(const T &rep1, const T &rep2, T &result) {
  if (rep1 != rep2) {
    auto it_rep1 = rep1.begin();
    auto it_rep2 = rep2.begin();
    auto it_result = result.begin();

    for (; it_rep1 != rep1.end() && it_rep2 != rep2.end() &&
           it_result != result.end();) {
      *it_result = *it_rep1 || *it_rep2;
      ++it_rep1;
      ++it_rep2;
      ++it_result;
    }

  } else {
    result = rep1;
  }
}

template <class Pop> void RandomSelection::construct_pool(Pop &p) {
  p.pool_size = p.get_size();
  p.pool = p.get_members();
}

template <class Pop>
std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
RandomSelection::selection(Pop &p) {
  const auto pool_s = static_cast<long long int>(p.get_pool_size());
  const auto rand_pos_pool1 = random_int_in(0, pool_s - 1);
  auto rand_pos_pool2 = random_int_in(0, pool_s - 1);

  while (rand_pos_pool1 == rand_pos_pool2) {
    rand_pos_pool2 = random_int_in(0, pool_s - 1);
  }

  return std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>(
      p.pool.at(rand_pos_pool1), p.pool.at(rand_pos_pool2));
}

// Proportional Sel.: this method adds to the pool as many copies of a DNA as
// its fitness ratio. Consequently, by choosing a random element from the pool,
// the probability of chossing a DNA is proportional to its fitness value.
template <class Pop> void ProportionalSelection::construct_pool(Pop &p) {
  const auto pool_s = static_cast<long long int>(p.get_size());
  float total_fitness = 0;

  for (auto it = p.begin(); it != p.end(); ++it) {
    total_fitness += it->get_fitness();
  }

  p.pool.clear();
  for (size_t i = 0; i < p.get_size(); i++) {
    auto times = static_cast<int>((1 / p.at(i).get_fitness()) * (pool_s + 1) /
                                  1 / (total_fitness));
    times = (times >= 1) ? times : 1;
    for (int k = 0; k < times; k++) {
      p.pool.push_back(p.at(i));
    }
  }

  if (p.pool.size() < p.get_pool_size()) {
    while (p.pool.size() < p.get_pool_size()) {
      p.pool.push_back(p.at(random_int_in(0, pool_s - 1)));
    }

  } else {
    p.pool.resize(p.get_pool_size());
  }
}

template <class Pop>
std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
ProportionalSelection::selection(Pop &p) {
  return RandomSelection::selection(p);
}

template <class Pop> void RankSelection::construct_pool(Pop &p) {
  p.pool = p.get_members();
  p.pool_size = p.get_size();
}

template <class Pop>
std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
RankSelection::selection(Pop &p) {
  const auto pool_s = static_cast<long long int>(p.get_pool_size());
  const auto rand_pos1 = random_int_in(0, pool_s - 1);
  auto rand_pos2 = random_int_in(0, pool_s - 1);

  while (rand_pos1 == rand_pos2) {
    rand_pos2 = random_int_in(0, pool_s - 1);
  }

  auto ii = (rand_pos1 > rand_pos2) ? rand_pos2 : rand_pos1;
  auto jj = random_int_in(0, pool_s - 1);

  while (jj > ii) {
    jj = random_int_in(0, pool_s - 1);
  }

  return std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>(
      p.pool.at(ii), p.pool.at(jj));
}

template <class Pop> void RouletteWheelSelection::construct_pool(Pop &p) {
  p.pool = p.get_members();
  p.pool_size = p.get_size();
}

template <class Pop>
std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
RouletteWheelSelection::selection(Pop &p) {
  float total_fitness = 0;

  for (auto it = p.begin(); it != p.end(); ++it) {
    total_fitness += it->get_fitness();
  }

  std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)> ret_pair;
  auto threshold = random_int_in(0, static_cast<long long int>(total_fitness));
  float partial_sum = 0;
  auto it_memb = p.begin();

  while (partial_sum < threshold && it_memb != p.end()) {
    partial_sum += it_memb->get_fitness();
    ++it_memb;
  }

  if (it_memb == p.end()) {
    it_memb = p.end() - 1;
  }

  ret_pair.first = *it_memb;
  threshold = random_int_in(0, static_cast<long long int>(total_fitness));
  partial_sum = 0;
  it_memb = p.begin();

  while (partial_sum < threshold && it_memb != p.end()) {
    partial_sum += it_memb->get_fitness();
    ++it_memb;
  }

  if (it_memb == p.end()) {
    it_memb = p.end() - 1;
  }

  ret_pair.second = *it_memb;
  return ret_pair;
}

template <class Pop> void StochasticSelection::construct_pool(Pop &p) {
  ProportionalSelection::construct_pool(p);
}

template <class Pop>
std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>
StochasticSelection::selection(Pop &p) {
  const auto start_point =
      static_cast<int>(random_float_in(0, 0.5) * p.get_pool_size());
  const auto step = static_cast<int>(0.5 * p.get_pool_size());
  const auto end_point = (start_point + step) < p.get_pool_size()
                             ? (start_point + step)
                             : (p.get_pool_size() - 1);

  return std::pair<decltype(Pop::memb_type), decltype(Pop::memb_type)>(
      p.pool.at(start_point), p.pool.at(end_point));
}

template <class Pop>
void StandardReplacement::replace(decltype(Pop::memb_type) &member, Pop &p,
                                  int k) {
  p.at(k) = member;
}

template <class Pop>
void qNNR::replace(decltype(Pop::memb_type) &member, Pop &p, int k) {
  const auto qmin = 1;
  const auto qmax = p.get_size() - 1;
  size_t q = qmin +
             (std::expm1((static_cast<float>(p.get_generation_number() + 1) /
                          static_cast<float>(MAX_ITERATIONS))) /
              std::expm1(1)) *
                 (qmax - qmin);

  q = q < p.get_size() ? q : p.get_size() - 1;
  auto P = p.get_members();
  std::partial_sort(P.begin(), P.begin() + q + 1, P.end(),
                    [member](auto a, auto b) {
                      return (std::abs(member.get_fitness() - a.get_fitness()) <
                              std::abs(member.get_fitness() - b.get_fitness()));
                    });

  decltype(Pop::memb_type) nearest =
      *std::max_element(P.begin(), P.begin() + q + 1);

  if (nearest > member) {
    auto x = std::find(p.begin(), p.end(), nearest);
    if (x != p.end()) {
      *x = member;
    }
  }
}

#endif // ALGORITHMS_H
