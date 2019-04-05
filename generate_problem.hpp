#ifndef GENERATE_PROBLEM_H
#define GENERATE_PROBLEM_H

#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>
#include <vector>

#include "syntax_tree.hpp"
#include "random_utils.hpp"
#include "matrix.hpp"


std::vector< std::vector<float> > generate_probabilities(int dim1, int dim2);
std::vector<float> generate_costs(int bound_n, int bound_N);
std::vector<float> generate_restrictions(int dim);
std::vector<Syntax_Tree> generate_events(int dim);
std::vector<Syntax_Tree>
generate_restriction_trees(int dim, int depth,
			   const std::vector<Syntax_Tree> & _events);

void
print_probabilities(const std::vector< std::vector<float> > & _probabilities);
void print_costs(const std::vector<float> & _costs);
void print_restrictions(const std::vector<float> & _restrictions);
void print_events(const std::vector<Syntax_Tree> & _events);

void print_problem(int dim1, int dim2, int depth, int bound_n, int bound_N);


#endif //GENERATE_PROBLEM_H
