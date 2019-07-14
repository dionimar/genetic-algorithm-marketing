#ifndef DNA_H
#define DNA_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <mutex>
#include <thread>
#include <vector>
#include <omp.h>

#include "algorithms.hpp"
#include "config.hpp"
#include "matrix.hpp"
#include "problem.hpp"
#include "random_utils.hpp"
#include "syntax_tree.hpp"

template <class T = std::vector<bool>, class CrossOp = UniformCrossover,
          class MutOp = RandomMutation>
class Dna {
private:
#ifdef PAR
  mutable std::mutex dna_mutex;
#endif
  T rep;
  mutable float fitness;
  mutable bool feasible;

public:
  typedef Dna<T, CrossOp, MutOp> Dna_type;
  typedef typename T::iterator iterator;
  typedef typename T::const_iterator const_iterator;
  typedef typename T::value_type &value;
  typedef typename T::value_type const_value;

  Dna() : rep(T()), fitness(0), feasible(false) {}
  Dna(int n) : rep(T(n, false)), fitness(0), feasible(false) {}
  Dna(const T &_rep) : rep(_rep), fitness(0), feasible(false) {}

  Dna(const Dna_type &adn) {
    rep = adn.rep;
    fitness = adn.fitness;
    feasible = adn.feasible;
  }

  Dna(Dna_type &&adn) {
    rep = std::move(adn.rep);
    fitness = std::move(adn.fitness);
    feasible = std::move(adn.feasible);
  }

  Dna &operator=(const Dna_type &adn) {
    this->rep = adn.rep;
    this->fitness = adn.fitness;
    this->feasible = adn.feasible;
    return *this;
  }

  Dna &operator=(Dna_type &&adn) {
    this->rep = std::move(adn.rep);
    this->fitness = std::move(adn.fitness);
    this->feasible = std::move(adn.feasible);
    return *this;
  }

  ~Dna() = default;

  iterator begin() noexcept {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    return rep.begin();
  }

  iterator end() noexcept {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    return rep.end();
  }

  const_iterator begin() const noexcept { return rep.begin(); }

  const_iterator end() const noexcept { return rep.end(); }

  value at(int i) {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    return rep.at(i);
  }

  const_value at(int i) const { return rep.at(i); }

  float get_fitness() const noexcept { return fitness; }

  size_t get_size() const noexcept { return rep.size(); }

  T get_rep() const { return rep; }

  bool get_feasible() const noexcept { return feasible; }

  void init_set_ones() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    rep = T(rep.size(), true);
  }

  void init_random() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    rep = random_vector_bool(rep.size());
  }

  void comp_fitness() const;

  void mutate_initial() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    rep.at(random_int_in(0, rep.size() - 1)) = false;
  }

  void mutate() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(dna_mutex);
#endif
    MutOp::mutation(rep);
  }

  Dna_type crossover(const Dna_type &other) const {
    // crossover acces rep from iterators, wich are already thread safe
    Dna_type child_rep = other;
    CrossOp::crossover(*this, other, child_rep);
    return Dna_type(child_rep);
  }

  friend std::ostream &operator<<(std::ostream &os, const Dna_type &adn) {
    for (const auto elem : adn.get_rep()) {
      os << elem;
    }
    return os;
  }

  void show_info() const {
    std::cout << *this << "    feasible: " << get_feasible();
    std::cout << "    fitness: " << get_fitness() << std::endl;
  }

  static void print_config();
};

template <class T, class CrossOp, class MutOp>
bool operator<(const Dna<T, CrossOp, MutOp> &adn1,
               const Dna<T, CrossOp, MutOp> &adn2) noexcept {
  return adn1.get_fitness() < adn2.get_fitness();
}

template <class T, class CrossOp, class MutOp>
bool operator>(const Dna<T, CrossOp, MutOp> &adn1,
               const Dna<T, CrossOp, MutOp> &adn2) noexcept {
  return adn1.get_fitness() > adn2.get_fitness();
}

template <class T, class CrossOp, class MutOp>
bool operator==(const Dna<T, CrossOp, MutOp> &adn1,
                const Dna<T, CrossOp, MutOp> &adn2) {
  return adn1.get_rep() == adn2.get_rep();
}

template <class T, class CrossOp, class MutOp>
bool operator!=(const Dna<T, CrossOp, MutOp> &adn1,
                const Dna<T, CrossOp, MutOp> &adn2) {
  return !(adn1.get_rep() == adn2.get_rep());
}

static const float costs_bound =
    (*std::max_element(costs.begin(), costs.end())) * (costs.size());

#ifdef PAPO
template <class T, class CrossOp, class MutOp>
void Dna<T, CrossOp, MutOp>::comp_fitness() const {
  fitness = scalar_prod(costs, get_rep());
  auto computed_terms = std::vector<float>(restrictions.size());

  #pragma omp parallel
  #pragma parallel for
  for (size_t i = 0; i < restrictions.size(); i++) {
    computed_terms.at(i) = watching_Ad(restrictions.at(i), *this, prob.at(i));
  }

  feasible = compare(computed_terms, min_impressions);
  if (!feasible) {
#ifdef USE_OF_INFINITY
    fitness = std::numeric_limits<float>::infinity();
#else // Use bound
    #pragma parallel for
    for (size_t i = 0; i < computed_terms.size(); i++) {
      if (computed_terms.at(i) < min_impressions.at(i)) {
        fitness += costs_bound *
                   (min_impressions.at(i) - computed_terms.at(i)) /
                   min_impressions.at(i);
      }
    }
#endif
  }
}
#endif

#ifdef APO
template <class T, class CrossOp, class MutOp>
void Dna<T, CrossOp, MutOp>::comp_fitness() const {
  auto repr = get_rep();
  fitness = scalar_prod(costs, repr);
  auto Ax = restrictions * repr;
  feasible = compare(Ax, min_impressions);

  if (!feasible) {
    auto it_Ax = Ax.begin();
    auto it_res = min_impressions.begin();
    while (it_Ax != Ax.end() && it_res != min_impressions.end()) {
      if (*it_Ax < *it_res) {
        fitness += costs_bound * (*it_res - *it_Ax) / *it_res;
      }
      ++it_Ax;
      ++it_res;
    }
  }
}
#endif

template <class T, class CrossOp, class MutOp>
void Dna<T, CrossOp, MutOp>::print_config() {
  std::cout << "--------------- Dna_type Parameters ---------------"
            << std::endl;
  std::cout << std::endl;
  std::cout << "    Crossover Operator = ";
  CrossOp::print();
  std::cout << std::endl;
  std::cout << "     Mutation Operator = ";
  MutOp::print();
  std::cout << std::endl;
  std::cout << "  Mutation Probability = " << MUTATION_RATE << std::endl;
  std::cout << std::endl;
}

#endif // DNA_H
