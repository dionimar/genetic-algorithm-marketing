main: main.cpp
	clang++ -g  -pthread -std=gnu++14 main.cpp generate_problem.cpp syntax_tree.cpp matrix.cpp random_utils.cpp greedy.cpp -o main.out
