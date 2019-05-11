# A genetic algorithm for solving the advertisement placement optimization problem

The Advertismenet Placement Optimization, technically knwon as APO, is a common problem in marketing where you have to place your advertise (or any product) in some media, given a set of restrictions for average views for a fixed population segment. As usual, we might be able to minimize the cost associated with the placement in such way that all segments restrictions fill.
We can distingish two main problems: one is based on average views for each population segment, and the other one relies on the probability to watch the advertisment for each segment. Both problems have the same complexity, Log-APX-hard. This justifies the genetic programming aproach.

## Implementation

This is intended to be a general purpose genetic algorithm, but it is a little bit tunned to solve the particular problems described above. It is all implemented in C++ languaje, without any external library. 

## Usage

If you want the algorithm solve an specific problem you must implement a fitness function for Dna class. It has to be a Dna member function, marked as const, as in the next example:

```cpp
template <class T, class CrossOp, class MutOp>
void Dna<T, CrossOp, MutOp>::comp_fitness() const {
  // Your big computation task
}
```

Dna class is parametrized by three classes:
* T: representation type. Now only supports vector types, if you want to add other custom types you have to rewrite the code for your purposes.
* CrossOp: crossover operator, defined in *algorithms.hpp*.
* MutOp: mutation operator, defined in *algorithms.hpp*.


The three classes decribed above determine Dna behaviour.

