#include <cassert>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "syntax_tree.hpp"
#include "matrix.hpp"
#include "generate_problem.hpp"

std::vector<std::vector<float> > generate_probabilities(int dim1, int dim2) {
  auto result = std::vector<std::vector<float> >(dim1);
  for (auto &&row : result) {
    row = random_vector(dim2, 0, 1);
  }
  return result;
}

std::vector<float> generate_costs(int dim, int bound_n, int bound_N) {
  auto result = random_vector(dim, bound_n, bound_N);
  return result;
}

std::vector<float> generate_restrictions(int dim) {
  auto result = random_vector(dim, 0, 1);
  return result;
}

std::vector<Syntax_Tree> generate_events(int dim) {
  auto result = std::vector<Syntax_Tree>(dim);
  for (int i = 0; i < dim; i++) {
    result.at(i) = cons_event(i);
  }
  return result;
}

std::vector<Syntax_Tree>
generate_restriction_trees(int dim, int depth,
                           const std::vector<Syntax_Tree> &_events) {
  auto result = std::vector<Syntax_Tree>(dim);
  std::cout << "static const std::vector<Syntax_Tree> restrictions = {";
  for (int i = 0; i < dim; i++) {
    result.at(i) = random_tree(depth, _events);
    std::cout << ",";
  }
  std::cout << "};" << std::endl;
  return result;
}

void print_probabilities(
    const std::vector<std::vector<float> > &_probabilities) {
  std::cout << "static const std::vector< std::vector<float> > prob = {";
  for (size_t j = 0; j < _probabilities.size(); j++) {
    std::cout << "{";
    for (size_t i = 0; i < _probabilities.at(j).size(); i++) {
      if (i + 1 == _probabilities.at(j).size()) {
        std::cout << _probabilities.at(j).at(i) << "}," << std::endl;
      } else {
        std::cout << _probabilities.at(j).at(i) << ", ";
      }
    }
  }
  std::cout << "};" << std::endl;
}

void print_costs(const std::vector<float> &_costs) {
  std::cout << "static const std::vector<float> costs = {";
  for (size_t i = 0; i < _costs.size(); i++) {
    if (i + 1 == _costs.size()) {
      std::cout << _costs.at(i);
    } else {
      std::cout << _costs.at(i) << ", ";
    }
  }
  std::cout << "};" << std::endl;
}

void print_restrictions(const std::vector<float> &_restrictions) {
  std::cout << "static const std::vector<float> min_impressions = {";
  for (size_t i = 0; i < _restrictions.size(); i++) {
    if (i + 1 == _restrictions.size()) {
      std::cout << _restrictions.at(i);
    } else {
      std::cout << _restrictions.at(i) << ", ";
    }
  }
  std::cout << "};" << std::endl;
}

void print_events(const std::vector<Syntax_Tree> &_events) {
  std::cout << "static const std::vector<Syntax_Tree> events = {";
  for (size_t i = 0; i < _events.size(); i++) {
    if (i + 1 == _events.size()) {
      std::cout << "cons_event(" << i << ")";
    } else {
      std::cout << "cons_event(" << i << "), ";
    }
  }
  std::cout << "};" << std::endl;
}

void print_problem(int _segments, int _media, int depth, int bound_n,
                   int bound_N) {
  std::cout << "static const int media = " << _media << ";" << std::endl;
  std::cout << "static const int segments = " << _segments << ";" << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  auto _probabilities = generate_probabilities(_segments, _media);
  // auto _nodes = generate_nodes(_media, _probabilities);
  auto _events = std::vector<Syntax_Tree>(_media);
  for (int i = 0; i < _media; i++) {
    _events.at(i) = Syntax_Tree(i);
  }
  print_events(_events);
  std::cout << std::endl;
  auto _costs = generate_costs(_media, bound_n, bound_N);
  assert(depth <= _media);
  auto _restriction_trees =
      generate_restriction_trees(_segments, depth, _events);
  auto _restrictions = generate_restrictions(_segments);
  auto x = std::vector<bool>(_media, true);
  auto comp_terms = std::vector<float>(_segments);
  for (size_t i = 0; i < comp_terms.size(); i++) {
    comp_terms.at(i) =
        watching_Ad(_restriction_trees.at(i), x, _probabilities.at(i));
  }
  // auto xx = std::vector<bool>(_media, true);
  // auto sol = dna< std::vector<bool> >(xx);
  // bool V = true;
  // for(int i = 0; i < _restriction_trees.size(); i++){
  // 	V = V && prob_consis(_restriction_trees.at(i),
  // 			     _probabilities.at(i), sol);
  // }
  bool T = compare(comp_terms, _restrictions); // && V;
  while (T == false) {
    //_restriction_trees = generate_restriction_trees(_segments, depth,
    //_events);
    // bool V = true;
    // for(int i = 0; i < _restriction_trees.size(); i++){
    //     V = V && prob_consis(_restriction_trees.at(i),
    // 			 _probabilities.at(i), sol);
    // }
    _probabilities = generate_probabilities(_segments, _media);
    for (size_t i = 0; i < comp_terms.size(); i++) {
      comp_terms.at(i) =
          watching_Ad(_restriction_trees.at(i), x, _probabilities.at(i));
    }
    T = compare(comp_terms, _restrictions); // && V;
  }
  std::cout << std::endl;
  std::cout << std::endl;
  print_probabilities(_probabilities);
  std::cout << std::endl;

  print_costs(_costs);
  std::cout << std::endl;
  print_restrictions(_restrictions);
  std::cout << std::endl;
  std::cout << "//---------------------------------------------------------"
            << std::endl;
}
