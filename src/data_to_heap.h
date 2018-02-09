#ifndef _data_to_heap_h
#define _data_to_heap_h
#include <iostream>
#include <vector>
#include <string>

// Class with all members needed to create and manipulate a heap
struct heap {
  double returns[500];
  std::string names[500];
  int size;
};

class Heap {
 private:
  struct heap heap_struct;
 public:
  void make_heap(const std::vector<double> &values,
    const std::vector<std::string> &input_names);
  void insert(double val, std::string name);
  int parent_index(int n);
  int child_index(int n);
  void bubble_up(int index);
  void extract_max(double *max_return, std::string *max_fund);
  void bubble_down(int index);
  void heap_sort(std::vector<double> &returns,
    std::vector<std::string> &names);
  void display();
  void display(const std::vector<double> &returns, 
      const std::vector<std::string> &names);

  Heap(const std::vector<double> &values, const std::vector<std::string>
      &input_names) {
    make_heap(values, input_names);
  }
  Heap() {

  }
};


#endif
