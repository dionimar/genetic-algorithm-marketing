# A genetic algorithm for solving the advertisement placement optimization problem

The Advertismenet Placement Optimization, technically knwon as APO, is a common problem in marketing where you have to place your advertise (or any product) in some media, given a set of restrictions for average views for a fixed population segment. As usual, we might be able to minimize the cost associated with the placement in such way that all segments restrictions fill.
We can distingish two main problems: one is based on average views for each population segment, and the other one relies on the probability to watch the advertisment for each segment. Both problems have the same complexity, Log-APX-hard. This justifies the genetic programming aproach.

## Implementation

This is intended to be a general purpose genetic algorithm, but it is a little bit tunned to solve the particular problems described above. It is all implemented in C++ languaje, without any external library. 

