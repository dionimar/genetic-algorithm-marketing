#ifndef POPULATION_H
#define POPULATION_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>
//#include <omp.h>

#include "adn.hpp"
#include "algorithms.hpp"
#include "config.hpp"
#include "greedy.hpp"
#include "random_utils.hpp"

template <class DnaType, class SelectOp = RandomSelection,
          class ReplaceOp = StandardReplacement>
class Population {
private:
#ifdef PAR
  mutable std::mutex pop_mutex;
#endif
  size_t population_size;
  std::vector<DnaType> members;
  int ellitists;
  int generation_number;
  mutable float entropy;

public:
  static DnaType memb_type; // Tricky member for decltype usage
  mutable size_t pool_size;
  mutable std::vector<DnaType> pool;

  typedef typename std::vector<DnaType>::iterator iterator;
  typedef typename std::vector<DnaType>::const_iterator const_iterator;
  typedef typename std::vector<DnaType>::value_type &value;
  typedef typename std::vector<DnaType>::value_type const_value;

  Population() noexcept : population_size(0),
                          pool_size(0),
                          members(std::vector<DnaType>()),
                          pool(std::vector<DnaType>()),
                          ellitists(0),
                          generation_number(0),
                          entropy(0) {}

  Population(int _length_adn, size_t _population_size, size_t _pool_size,
             int _ellitists);

  Population(const Population &pop) {
    population_size = pop.population_size;
    pool_size = pop.pool_size;
    members = pop.members;
    pool = pop.pool;
    ellitists = pop.ellitists;
    generation_number = pop.generation_number;
    entropy = pop.entropy;
  }

  Population(Population &&pop) {
    population_size = std::move(pop.population_size);
    pool_size = std::move(pop.pool_size);
    members = std::move(pop.members);
    pool = std::move(pop.pool);
    ellitists = std::move(pop.ellitists);
    generation_number = std::move(pop.generation_number);
    entropy = std::move(pop.entropy);
  }

  Population &operator=(const Population<DnaType, SelectOp, ReplaceOp> &pop) {
    this->population_size = pop.population_size;
    this->pool_size = pop.pool_size;
    this->members = pop.members;
    this->pool = pop.pool;
    this->ellitists = pop.ellitists;
    this->generation_number = pop.generation_number;
    this->entropy = pop.entropy;
    return *this;
  }

  Population &operator=(Population<DnaType, SelectOp, ReplaceOp> &&pop) {
    this->population_size = std::move(pop.population_size);
    this->pool_size = std::move(pop.pool_size);
    this->members = std::move(pop.members);
    this->pool = std::move(pop.pool);
    this->ellitists = std::move(pop.ellitists);
    this->generation_number = std::move(pop.generation_number);
    this->entropy = std::move(pop.entropy);
    return *this;
  }

  ~Population() = default;

  iterator begin() noexcept {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    return members.begin();
  }

  iterator end() noexcept {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    return members.end();
  }

  const_iterator begin() const noexcept { return members.begin(); }

  const_iterator end() const noexcept { return members.end(); }

  value at(int i) {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    return members.at(i);
  }

  const_value at(int i) const { return members.at(i); }

  std::vector<DnaType> get_members() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    return members;
  }

  size_t get_size() const noexcept { return population_size; }
  size_t get_pool_size() const noexcept { return pool_size; }
  int get_ellitists() const noexcept { return ellitists; }
  int get_generation_number() const noexcept { return generation_number; }
  float get_entropy() const noexcept { return entropy; }

  DnaType get_best() const {
    if (members.size() > 0) {
      auto feasibles = std::vector<DnaType>(0);
      for (auto &&x : members) {
        if (x.get_feasible()) {
          feasibles.push_back(x);
        }
      }

      if (feasibles.size() != 0) {
        return *std::min_element(feasibles.begin(), feasibles.end());
      } else
        return DnaType();
    } else
      return DnaType();
  }

  DnaType get_worst() const {
    if (members.size() > 0) {
      return *std::max_element(members.begin(), members.end());
    } else
      return DnaType();
  }

  void sort() {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    if (members.size() > 0) {
      std::sort(members.begin(), members.end());
    } else
      return;
  }

  void next_generation() {
    //#pragma omp parallel
    SelectOp::construct_pool(*this);
    // partial sort if ellitism is selected; we need to avoid
    // replacement over this members
    if (ellitists > 0) {
      std::partial_sort(members.begin(), members.begin() + ellitists,
                        members.end());
    }

#ifdef PAR
    auto f1 = [this](int initial, int final) {
      for (int i = initial; i < final; i++) {
        auto membs = SelectOp::selection(*this);
        auto new_memb = membs.first.crossover(membs.second);
        new_memb.mutate();
        new_memb.comp_fitness();
        ReplaceOp::replace(new_memb, *this, i);
      }
    };

    std::thread t1(f1, ellitists, population_size / 4);
    std::thread t2(f1, population_size / 4, population_size / 2);
    std::thread t3(f1, population_size / 2, 3 * population_size / 4);
    std::thread t4(f1, 3 * population_size / 4, population_size);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

#else
    //#pragma omp for
    for (int i = ellitists; i < population_size; i++) {
      auto membs = SelectOp::selection(*this);
      auto new_memb = membs.first.crossover(membs.second);
      new_memb.mutate();
      new_memb.comp_fitness();
      ReplaceOp::replace(new_memb, *this, i);
    }
#endif
    generation_number++;
  }

  void compute_entropy() const {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    int count = 0;
    
    for (auto it = members.begin(); it != members.end() - 1; ++it) {
      for (auto it2 = it + 1; it2 != members.end(); ++it2) {
        count += hamming_d(*it, *it2);
      }
    }
    
    entropy = 2 * count / (population_size * (population_size - 1));
  }

  float average_fitness() const {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    float fit = 0;

    for (auto it = members.begin(); it != members.end(); ++it) {
      fit += it->get_fitness();
    }

    return fit / population_size;
  }

  float feasible_percentage() const {
#ifdef PAR
    std::lock_guard<std::mutex> guard(pop_mutex);
#endif
    float count = 0;
    const float total = static_cast<float>(population_size);

    for (auto &&x : members) {
      if (x.get_feasible()) {
        count++;
      }
    }

    return 100 * count / total;
  }

#ifdef TESTING
  void evolve(int max_iterations, std::vector<std::vector<float>> &data_fitness,
              std::vector<std::vector<float>> &data_entropy,
              std::vector<std::vector<float>> &data_feasibility) {
    assert(max_iterations > 0);
    auto bests = std::vector<float>(0);
    auto entropys = std::vector<float>(0);
    auto feasible_p = std::vector<float>(0);

    while (max_iterations > 0) {
      next_generation();
      // compute_entropy();
      max_iterations--;
      bests.push_back(get_best().get_fitness());
      // entropys.push_back(get_entropy());
      // feasible_p.push_back(feasible_percentage());
    }

    // bests.push_back(get_best().get_fitness());
    data_fitness.push_back(bests);
    // data_entropy.push_back(entropys);
    // data_feasibility.push_back(feasible_p);
  }

#else
  void evolve(int max_iterations) {
    assert(max_iterations > 0);
    while (max_iterations > 0) {
      next_generation();
      max_iterations--;
    }
    show();
  }
#endif

  void show() const {
    std::cout << "------------ population Parameters -----------" << std::endl
              << std::endl;
    std::cout << "       population size = " << POPULATION_SIZE << std::endl;
    std::cout << "             Pool size = " << pool_size << std::endl;
    std::cout << "              Elitists = " << ellitists << std::endl;
    std::cout << "      Selection Method = ";
    SelectOp::print();
    std::cout << std::endl;
    std::cout << "           Replacement = ";
    ReplaceOp::print();
    std::cout << std::endl;
    std::cout << "       Max. Iterations = " << MAX_ITERATIONS << std::endl;
    std::cout << "      Initialized from = ";
#ifdef ONES_INITIALIZATION
    std::cout << "1's plus mutation" << std::endl;
#else
    std::cout << "random" << std::endl;
#endif
    std::cout << std::endl;
    DnaType::print_config();
    std::cout << "---------------- Best Member -----------------" << std::endl;
    std::cout << std::endl;
    std::cout << "         representation: " << std::endl;
    std::cout << get_best() << std::endl;
    std::cout << "                  cost = " << get_best().get_fitness()
              << std::endl;
    std::cout << std::endl;
    std::cout << "-------------- population Stats -------------" << std::endl;
    std::cout << std::endl;
    const float min_fitness = get_best().get_fitness();
    const float max_fitness = get_worst().get_fitness();
    std::cout << "       Minimum fitness = " << min_fitness << std::endl;
    std::cout << "       Maximum fitness = " << max_fitness << std::endl;
    std::cout << "   Feasible percentage = " << feasible_percentage() << "%"
              << std::endl;
    std::cout << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, const Population &pop) {
    for (const auto &elem : pop.members) {
      os << elem;
      os << "    fitness: " << elem.get_fitness();
      os << std::endl;
    }
    return os;
  }
};

template <class DnaType, class SelectOp, class ReplaceOp>
Population<DnaType, SelectOp, ReplaceOp>::Population(int _length_adn,
                                                     size_t _population_size,
                                                     size_t _pool_size,
                                                     int _ellitists)
    : population_size(_population_size),
      members(std::vector<DnaType>(population_size, DnaType(_length_adn))),
      ellitists(_ellitists), generation_number(0), entropy(0),
      pool_size(_pool_size),
      pool(std::vector<DnaType>(0, DnaType(_length_adn))) {

  assert(population_size > 0);
  assert(pool_size > 0);
  assert(ellitists >= 0);

  if (pool_size <= population_size) {
    pool = std::vector<DnaType>(pool_size, DnaType(_length_adn));
  } else {
    pool = std::vector<DnaType>(population_size, DnaType(_length_adn));
  }

  auto it_member = members.begin();
#ifdef GREEDY_INIT
#ifdef PAPO
  *it_member = DnaType(greedy_papo(restrictions, min_impressions, prob));
#else
  *it_member = DnaType(greedy_apo(media, restrictions, min_impressions, prob));
#endif
#else
  // Ensure first member is set to 1's, so if it's not feasible,
  // no feasible solution exists.
  it_member->init_set_ones();
#endif
  it_member->comp_fitness();
  assert(it_member->get_feasible());
  ++it_member;

  for (; it_member != members.end(); ++it_member) {
#ifdef ONES_INITIALIZATION
    it_member->init_set_ones();
    it_member->mutate_initial();
#else
    it_member->init_random();
#endif
    it_member->comp_fitness();
  }
}

#endif // POPULATION_H
