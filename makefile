main: main.cpp
	clang++ -O2 -pthread -std=gnu++14 main.cpp syntax_tree.cpp matrix.cpp random_utils.cpp greedy.cpp -o main.out
