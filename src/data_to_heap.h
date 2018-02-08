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
    void init_heap();
    void make_heap(const std::vector<double> &values,
        const std::vector<std::string> &input_names);
    void insert(double val, std::string name);
    int parent_index(int n);
    int child_index(int n);
    void bubble_up(int index);
    void extract_max(double val, std::string name);
    void bubble_down(double val, std::string name);
    void display();

    Heap(const std::vector<double> &values, const std::vector<std::string>
        &input_names) {
      make_heap(values, input_names);
    }
};


#endif
