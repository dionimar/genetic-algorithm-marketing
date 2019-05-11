#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

#include "random_utils.hpp"
#include "syntax_tree.hpp"

// Node implementation ---------------------------------------------------------

Node::Node()
    : indep(std::vector< std::shared_ptr<Node> >(0)),
      excl(std::vector< std::shared_ptr<Node> >(0)),
      incl(std::vector< std::shared_ptr<Node> >(0)), event_id(-1) {}

Node::Node(const Node &nod) {
  this->indep = nod.indep;
  this->excl = nod.excl;
  this->incl = nod.incl;
  this->event_id = nod.event_id;
}

Node::Node(int _event_id)
    : indep(std::vector< std::shared_ptr<Node> >(0)),
      excl(std::vector< std::shared_ptr<Node> >(0)),
      incl(std::vector< std::shared_ptr<Node> >(0)), event_id(_event_id) {}

Node &Node::operator=(const Node &nod) {
  this->indep = nod.indep;
  this->excl = nod.excl;
  this->incl = nod.incl;
  this->event_id = nod.event_id;
  return *this;
}

Node::~Node() {
  this->indep.clear();
  this->excl.clear();
  this->incl.clear();
}

void Node::set_incl(const std::vector< std::shared_ptr<Node> > &vec) {
  this->incl = vec;
}

void Node::set_excl(const std::vector< std::shared_ptr<Node> > &vec) {
  this->excl = vec;
}

void Node::set_indep(const std::vector< std::shared_ptr<Node> > &vec) {
  this->indep = vec;
}

void Node::excl_push(const std::shared_ptr<Node> &nod) {
  this->excl.push_back(nod);
}

void Node::indep_push(const std::shared_ptr<Node> &nod) {
  this->indep.push_back(nod);
}

bool operator==(const Node &nod1, const Node &nod2) {
  bool T_indep = nod1.indep.size() == nod2.indep.size();
  if (T_indep) {
    for (size_t i = 0; i < nod1.indep.size(); i++) {
      T_indep = T_indep && *nod1.indep.at(i) == *nod2.indep.at(i);
    }

  } else {
    return false;
  }

  bool T_excl = nod1.excl.size() == nod2.excl.size();
  if (T_excl) {
    for (size_t i = 0; i < nod1.excl.size(); i++) {
      T_excl = T_excl && *nod1.excl.at(i) == *nod2.excl.at(i);
    }
    
  } else {
    return false;
  }
  
  bool T_incl = nod1.incl.size() == nod2.incl.size();
  if (T_incl) {
    for (size_t i = 0; i < nod1.incl.size(); i++) {
      T_incl = T_incl && *nod1.incl.at(i) == *nod2.incl.at(i);
    }
    
  } else {
    return false;
  }
  
  bool T_event = (nod1.event_id != -1) && (nod2.event_id != -1);
  if (T_event) {
    T_event = T_event && nod1.event_id == nod2.event_id;
    
  } else {
    T_event = (nod1.event_id == -1) && (nod2.event_id == -1);
  }
  
  return T_indep && T_excl && T_incl && T_event;
}

bool operator!=(const Node &nod1, const Node &nod2) { return !(nod1 == nod2); }

// Syntax_Tree implementation---------------------------------------------------

Syntax_Tree::Syntax_Tree() noexcept : root(nullptr) {}

Syntax_Tree::Syntax_Tree(const Node &nod) {
  root = std::make_shared<Node>(nod);
}

Syntax_Tree::Syntax_Tree(const Syntax_Tree &t) {
  if (t.root != nullptr) {
    Node aux = *t.root;
    this->root = std::make_shared<Node>(aux);
    
  } else {
    *this = Syntax_Tree();
  }
}

Syntax_Tree &Syntax_Tree::operator=(const Syntax_Tree &t) {
  if (t.root != nullptr) {
    Node aux = *t.root;
    this->root = std::make_shared<Node>(aux);
  }
  return *this;
}

Syntax_Tree::~Syntax_Tree() { root.reset(); }

bool operator==(const Syntax_Tree &tree1, const Syntax_Tree &tree2) {
  return (*tree1.root == *tree2.root);
}

bool operator!=(const Syntax_Tree &tree1, const Syntax_Tree &tree2) {
  return !(tree1 == tree2);
}

void Syntax_Tree::set_incl(const std::vector< std::shared_ptr<Node> > &vec) {
  this->root->set_incl(vec);
}

void Syntax_Tree::set_excl(const std::vector< std::shared_ptr<Node> > &vec) {
  this->root->set_excl(vec);
}

void Syntax_Tree::set_indep(const std::vector< std::shared_ptr<Node> > &vec) {
  this->root->set_indep(vec);
}

void Syntax_Tree::excl_push(const std::shared_ptr<Node> &nod) {
  this->root->excl_push(nod);
}

void Syntax_Tree::indep_push(const std::shared_ptr<Node> &nod) {
  this->root->indep_push(nod);
}

Syntax_Tree cons_event(int _event_id) { return Syntax_Tree(Node(_event_id)); }

Syntax_Tree cons_incl(const Syntax_Tree &tree1, int _event_id) {
  auto tree1_root = tree1.root;
  
  if (tree1_root != nullptr) {
    Node nod = Node(_event_id);
    Node aux = Node(*tree1_root);
    Node root = Node();
    root.set_incl({std::make_shared<Node>(aux), std::make_shared<Node>(nod)});
    return root;
  }
  
  return Syntax_Tree();
}

Syntax_Tree cons_excl(const Syntax_Tree &tree1, const Syntax_Tree &tree2) {
  std::shared_ptr<Node> tree1_root = tree1.root;
  std::shared_ptr<Node> tree2_root = tree2.root;
  
  if ((tree1_root != nullptr) && (tree2_root != nullptr)) {
    if (tree1_root->excl.size() > 0) {
      Syntax_Tree tree = Syntax_Tree(tree1);
      tree.excl_push(std::shared_ptr<Node>(tree2_root));
      return tree;
      
    } else {
      Node nod = Node();
      nod.set_excl({std::shared_ptr<Node>(tree1_root),
                    std::shared_ptr<Node>(tree2_root)});
      return Syntax_Tree(nod);
    }
    
  } else if ((tree1_root == nullptr) && (tree2_root != nullptr)) {
    return Syntax_Tree(*tree2_root);
    
  } else if ((tree1_root != nullptr) && (tree2_root == nullptr)) {
    return Syntax_Tree(*tree1_root);
  }
  
  return Syntax_Tree();
}

Syntax_Tree cons_indep(const Syntax_Tree &tree1, const Syntax_Tree &tree2) {
  std::shared_ptr<Node> tree1_root = tree1.root;
  std::shared_ptr<Node> tree2_root = tree2.root;
  
  if ((tree1_root != nullptr) && (tree2_root != nullptr)) {
    Syntax_Tree tree = Syntax_Tree(tree1);
    if (tree1_root->indep.size() > 0) {
      tree.indep_push(std::shared_ptr<Node>(tree2_root));
      return tree;
      
    } else {
      Node nod = Node();
      nod.set_indep({std::shared_ptr<Node>(tree1_root),
                     std::shared_ptr<Node>(tree2_root)});
      return Syntax_Tree(nod);
    }
    
  } else if ((tree1_root != nullptr) && (tree2_root == nullptr)) {
    return Syntax_Tree(*tree1_root);
    
  } else if ((tree1_root == nullptr) && (tree2_root != nullptr)) {
    return Syntax_Tree(*tree2_root);
  }
  
  return Syntax_Tree();
}

Syntax_Tree cons_incl(const Syntax_Tree &tree1, const Syntax_Tree &tree2) {
  std::shared_ptr<Node> tree1_root = tree1.root;
  std::shared_ptr<Node> tree2_root = tree2.root;
  
  if ((tree1_root != nullptr) && (tree2_root != nullptr)) {
    Node nod = Node();
    nod.set_incl(
        {std::shared_ptr<Node>(tree1_root), std::shared_ptr<Node>(tree2_root)});
    return Syntax_Tree(nod);
    
  } else if ((tree1_root == nullptr) && (tree2_root != nullptr)) {
    return Syntax_Tree(*tree2_root);
    
  } else {
    return Syntax_Tree();
  }
}

Syntax_Tree random_tree_rec(int depth, const std::vector<Syntax_Tree> &events,
                            std::vector<int> &permutations) {
  const int j = permutations.back();
  permutations.pop_back();
  
  if (depth > 0) {
    // Syntax_Tree tree = Syntax_Tree();
    auto tree_ptr = std::make_unique<Syntax_Tree>(Syntax_Tree());
    const int k = random_int_in(0, 2);
    
    if (k == 0) {
      std::cout << "cons_excl(";
      *tree_ptr = cons_excl(random_tree_rec(depth - 1, events, permutations),
                            events.at(j));
      std::cout << "events[" << j << "]"
                << "),";
      return *(tree_ptr.release());
      
    } else if (k == 1) {
      std::cout << "cons_incl(";
      *tree_ptr = cons_incl(random_tree_rec(depth - 1, events, permutations),
                            events.at(j));
      std::cout << "events[" << j << "]"
                << "),";
      return *(tree_ptr.release());
      
    } else {
      std::cout << "cons_indep(";
      *tree_ptr = cons_indep(random_tree_rec(depth - 1, events, permutations),
                             events.at(j));
      std::cout << "events[" << j << "]"
                << "),";
      return *(tree_ptr.release());
    }
    
  } else {
    std::cout << "events[" << j << "]";
    return cons_event(events.at(j).root->event_id);
  }
}

Syntax_Tree random_tree(int depth, const std::vector<Syntax_Tree> &events) {
  auto permutations = std::vector<int>(events.size());
  
  for (size_t i = 0; i < events.size(); i++) {
    permutations.at(i) = i;
  }
  
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(permutations.begin(), permutations.end(), g);
  return random_tree_rec(depth, events, permutations);
}

bool parse(const Node &T) {
  if (T.incl.size() > 0) {
    bool test = true;
    test = test && parse(*T.incl.at(0));
    for (int i = T.incl.size() - 1; i > 0; i--) {
      test = test && (T.incl.at(i)->event_id != -1);
    }
  }
  
  if (T.indep.size() > 0) {
    bool test = true;
    for (auto &&elem : T.indep) {
      test = test && parse(*elem);
    }
    return ((T.excl.size() == 0) && (T.event_id == -1) && test);
    
  } else if (T.excl.size() > 0) {
    bool test = true;
    for (auto &&elem : T.excl) {
      test = test && parse(*elem);
    }
    return ((T.indep.size() == 0) && (T.event_id == -1) && test);
    
  } else if (T.event_id != -1) {
    return true;
  }
  
  return false;
}

bool parse(const Syntax_Tree &tree) {
  if (tree.root != nullptr) {
    return parse(*tree.root);
  } else
    return false;
}

void show(const Node &T, int cont) {
  for (int i = 0; i < cont; i++) {
    std::cout << "    ";
  }
  
  if (T.incl.size() > 0) {
    if (T.event_id != -1) {
      std::cout << T.event_id << std::endl;
    }
    std::cout << "" << std::endl;
    for (auto &&elem : T.incl) {
      show(*elem, cont + 1);
    }
  }
  
  if (T.excl.size() > 0) {
    if (T.event_id != -1) {
      std::cout << T.event_id << std::endl;
    }
    std::cout << "" << std::endl;
    for (auto &&elem : T.excl) {
      show(*elem, cont + 1);
    }
    
  } else if (T.indep.size() > 0) {
    if (T.event_id != -1) {
      std::cout << T.event_id << std::endl;
    }
    std::cout << "" << std::endl;
    for (auto &&elem : T.indep) {
      show(*elem, cont + 1);
    }
  }
  
  if (T.event_id != -1) {
    std::cout << T.event_id << std::endl;
  }
}

void show(const Syntax_Tree &tree) {
  if (tree.root != nullptr) {
    show(*tree.root, 0);
  } else {
    std::cout << "nullptr" << std::endl;
  }
}
