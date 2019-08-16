#ifndef CONFIG_H
#define CONFIG_H

#define PAR

//#define TESTING
#ifdef TESTING
#define MAX_TEST_ITERATIONS 100
#endif

//#define USE_OF_INFINITY
//#define SHOW_INFO

// If no ONES_INITIALIZATION is defined all members are initialized from random
// values. Using ONES_INITIALIZATION the initial members are set to 1 plus
// a mutation, so we ensure the existence of more feasible members at first
// generation.
#define ONES_INITIALIZATION
// Take the greedy solution in first population
//#define GREEDY_INIT
#define MUTATION_RATE 0.1
#define POPULATION_SIZE 200
#define POOL_SIZE 200
#define ELLITISTS 20 // Number of individuals to keep for next generation
#define MAX_ITERATIONS 250

#define PRINT(a) P(a)
#define P(a) #a

#endif // CONFIG_H
