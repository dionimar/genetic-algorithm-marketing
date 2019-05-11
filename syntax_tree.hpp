#ifndef SYNTAX_TREE
#define SYNTAX_TREE

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

class Syntax_Tree;

class Node {
private:
  std::vector< std::shared_ptr<Node> > indep;
  std::vector< std::shared_ptr<Node> > excl;
  std::vector< std::shared_ptr<Node> > incl;
  int event_id;

public:
  Node();
  Node(const Node &nod);
  Node(int _event_id);
  Node(Node &&nod) = default;
  Node &operator=(const Node &nod);
  Node &operator=(Node &&nod) = default;
  ~Node();

  void set_incl(const std::vector< std::shared_ptr<Node> > &vec);
  void set_excl(const std::vector< std::shared_ptr<Node> > &vec);
  void set_indep(const std::vector< std::shared_ptr<Node> > &vec);
  void excl_push(const std::shared_ptr<Node> &nod);
  void indep_push(const std::shared_ptr<Node> &nod);

  friend Syntax_Tree cons_event(int _event_id);
  friend Syntax_Tree cons_incl(const Syntax_Tree &tree1, int _event_id);
  friend Syntax_Tree cons_excl(const Syntax_Tree &tree1,
                               const Syntax_Tree &tree2);
  friend Syntax_Tree cons_indep(const Syntax_Tree &tree1,
                                const Syntax_Tree &tree2);
  friend Syntax_Tree cons_incl(const Syntax_Tree &tree1,
                               const Syntax_Tree &tree2);
  friend Syntax_Tree random_tree_rec(int depth,
                                     const std::vector<Syntax_Tree> &events,
                                     std::vector<int> &permutations);

  friend bool parse(const Node &T);
  friend void show(const Node &T, int cont);

  friend bool operator==(const Node &nod1, const Node &nod2);
  friend bool operator!=(const Node &nod1, const Node &nod2);

  template <class Dna>
  friend float watching_Ad(const Node &root, const Dna &solution,
                           const std::vector<float> &probabilities);

  template <class Dna>
  friend bool prob_consis(const Node &nod, const std::vector<float> &prob,
                          const Dna &solution);
};

bool operator==(const Node &nod1, const Node &nod2);
bool operator!=(const Node &nod1, const Node &nod2);

class Syntax_Tree {
public:
  std::shared_ptr<Node> root;

public:
  Syntax_Tree() noexcept;
  Syntax_Tree(const Node &nod);
  Syntax_Tree(const Syntax_Tree &t);
  Syntax_Tree(Syntax_Tree &&t) = default;
  Syntax_Tree &operator=(const Syntax_Tree &t);
  Syntax_Tree &operator=(Syntax_Tree &&t) = default;
  ~Syntax_Tree();

  void set_incl(const std::vector< std::shared_ptr<Node> > &vec);
  void set_excl(const std::vector< std::shared_ptr<Node> > &vec);
  void set_indep(const std::vector< std::shared_ptr<Node> > &vec);
  void excl_push(const std::shared_ptr<Node> &nod);
  void indep_push(const std::shared_ptr<Node> &nod);
};

bool operator==(const Syntax_Tree &tree1, const Syntax_Tree &tree2);
bool operator!=(const Syntax_Tree &tree1, const Syntax_Tree &tree2);

Syntax_Tree cons_event(int _event_id);
Syntax_Tree cons_incl(const Syntax_Tree &tree1, int _event_id);
Syntax_Tree cons_excl(const Syntax_Tree &tree1, const Syntax_Tree &tree2);
Syntax_Tree cons_indep(const Syntax_Tree &tree1, const Syntax_Tree &tree2);
Syntax_Tree cons_incl(const Syntax_Tree &tree1, const Syntax_Tree &tree2);

Syntax_Tree random_tree_rec(int depth, const std::vector<Syntax_Tree> &events,
                            std::vector<int> &permutations);

Syntax_Tree random_tree(int depth, const std::vector<Syntax_Tree> &events);

bool parse(const Node &T);
bool parse(const Syntax_Tree &tree);
void show(const Node &T, int cont);
void show(const Syntax_Tree &tree);

template <class Dna>
float watching_Ad(const Node &root, const Dna &solution,
                  const std::vector<float> &probabilities) {
  if (root.indep.size() > 0) {
    float prod = 1;
    for (auto &&syntax_node : root.indep) {
      prod *= (1 - watching_Ad(*syntax_node, solution, probabilities));
    }
    return (1 - prod);
    
  } else if (root.excl.size() > 0) {
    float sum = 0;
    for (auto &&syntax_node : root.excl) {
      sum += watching_Ad(*syntax_node, solution, probabilities);
    }
    return sum;
  }
  
  if (root.incl.size() > 0) {
    if (static_cast<bool>(solution.at(root.incl.at(1)->event_id)) == true) {
      return probabilities.at(root.incl.at(1)->event_id);
    } else {
      return watching_Ad(*root.incl.at(0), solution, probabilities);
    }
  }
  
  if (root.event_id != -1) {
    if (static_cast<bool>(solution.at(root.event_id)) == true) {
      return probabilities.at(root.event_id);
    } else
      return 0;
  }
  
  return -1;
}

template <class Dna>
float watching_Ad(const Syntax_Tree &tree, const Dna &solution,
                  const std::vector<float> &probabilities) {
  assert(tree.root != nullptr);
  return watching_Ad(*tree.root, solution, probabilities);
}

template <class Dna>
bool prob_consis(const Node &nod, const std::vector<float> &prob,
                 const Dna &solution) {
  if (nod.indep.size() > 0) {
    bool T = true;
    for (auto &&term : nod.indep) {
      T = T && prob_consis(*term, prob, solution);
    }
    return T;
  }
  
  if (nod.excl.size() > 0) {
    bool T = watching_Ad(nod, solution, prob);
    for (auto &&term : nod.excl) {
      T = T && prob_consis(*term, prob, solution);
    }
    return T;
  }
  
  if (nod.incl.size() > 0) {
    return watching_Ad(*nod.incl.at(0), solution, prob) <=
           prob.at((*nod.incl.at(1)).event_id);
    
  } else {
    return true;
  }
}

template <class Dna>
bool prob_consis(const Syntax_Tree &term, const std::vector<float> &prob,
                 const Dna &solution) {
  return prob_consis(*term.root, prob, solution);
}

#endif // SYNTAX_TREE
