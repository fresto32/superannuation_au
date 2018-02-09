#ifndef _data_to_tree_h
#define _data_to_tree_h

// Tree structure consisting of the finanial return and fund name, pointers
// to the right, left, and parent tree
struct tree {
  double financial_return;
  std::string fund_name;
  tree *parent;
  tree *left;
  tree *right;
};

// Tree class, which consists of all the methods needed to generate,
// manipulate, and search the tree of financial data. Each Tree object
// is assumed to consist of a single tree for that given year.
class Tree {
 private:
  struct tree tree_struct;
 public:
  // The following three methods are overloaded so that the tree class 
  // may be used to search/find min or max/insert an arbitrary tree. 

  // A special case is the *search_tree overloading. To search the tree_struct
  // ,tree_structmethod with two argument must be called, which then starts a
  // recursive search using the *search_tree of three arguments. This is 
  // because outside the class, the user cannot input the private struct 
  // tree_struct into the search tree with three parameters.
  tree *search_tree(tree *tree_to_search, std::string search_name, 
      double search_return);
  tree *search_tree(std::string search_name, double search_return);

  tree *find_minimum(tree *tree_to_search);
  tree *find_minimum();

  tree *find_maximum(tree *tree_to_search);
  tree *find_maximum();

  void insert_tree(tree **t, std::string name_to_add, double return_to_add,
      tree *tree_parent);
  void insert_tree(std::string name_to_add, double return_to_add);
  void make_tree(std::vector<std::string> fund_names_to_add, 
      std::vector<double> returns_to_add);

  // Displays the tree in post order form
  void display(tree *p, int indent = 0);
  void display();
};

#endif
