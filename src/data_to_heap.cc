#include "data_to_heap.h"
#include <iostream>
#include <vector>

struct heap {
  int returns[500];
  std::string fund_names[500];
  int size = 0;
};

class Heap {
  private:
    struct heap;
  public:
    void insert(struct heap, int ret, std::string name);
    int parent_index(int n);
    int child_index(int n);
    void bubble_up(struct heap, int ret, std::string name);
    void extract_max(struct heap, int ret, std::string name);
    void bubble_down(struct heap, int ret, std::string name);
};
