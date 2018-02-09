#include "financial_data_reader.h"
#include "data_to_tree.h"
#include <iostream>
#include <iomanip>

// Searches the given tree for the search_name, search_return pair
tree *Tree::search_tree(tree *tree_to_search, std::string search_name, 
    double search_return) {
  if (tree_to_search == NULL) return NULL;

  if ((tree_to_search->financial_return == search_return) &&
      (tree_to_search->fund_name == search_name)) {
    return tree_to_search;
  }

  if (tree_to_search->financial_return > search_return)
    return Tree::search_tree(tree_to_search->left, search_name, search_return);
  else
    return Tree::search_tree(tree_to_search->right, search_name, 
        search_return);
}
 
tree *Tree::search_tree(std::string search_name, double search_return) {
  return Tree::search_tree(&tree_struct, search_name, search_return);
}

tree *Tree::find_minimum(tree *tree_to_search) {
  while (tree_to_search->left != NULL) 
    tree_to_search = tree_to_search->left;

  return tree_to_search;
}

tree * Tree::find_minimum() {
  return Tree::find_minimum(&tree_struct);
}
 
tree *Tree::find_maximum(tree *tree_to_search) {
  while (tree_to_search->right != NULL) 
    tree_to_search = tree_to_search->right;

  return tree_to_search;
}

tree *Tree::find_maximum() {
  return Tree::find_maximum(&tree_struct);
}
 
void Tree::insert_tree(tree **t, std::string name_to_add, 
    double return_to_add, tree *tree_parent) {
  tree *tree_ptr;

  if (*t == NULL) {
    tree_ptr = new tree;
    tree_ptr->financial_return = return_to_add;
    tree_ptr->fund_name = name_to_add;

    tree_ptr->parent = tree_parent;
    tree_ptr->right = tree_ptr->left = NULL;
    *t = tree_ptr;
    return;
  }

  if (return_to_add < (*t)->financial_return)
    Tree::insert_tree(&((*t)->left), name_to_add, return_to_add, *t);
  else
    Tree::insert_tree(&((*t)->right), name_to_add, return_to_add, *t);
}

void Tree::insert_tree(std::string name_to_add, double return_to_add) {
  tree *ptr = &tree_struct;
  Tree::insert_tree(&(ptr), name_to_add, return_to_add, &tree_struct);
}

void Tree::make_tree(const std::vector<std::string> fund_names_to_add, 
      const std::vector<double> returns_to_add) {
  for (int i = 0; i < fund_names_to_add.size(); i++)
    Tree::insert_tree(fund_names_to_add[i], returns_to_add[i]);
}

void Tree::display(tree *p, int indent) {
  if (p != NULL) {
    if (p->left) display(p->left, indent+4);
    if (p->right) display(p->right, indent+4);
    if (indent) {
      std::cout << std::setw(indent) << " ";
    }
    std::cout << p->fund_name << ": " << p->financial_return << "\n";
  }
}

void Tree::display() {
  Tree::display(&tree_struct);
}
