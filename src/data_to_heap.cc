#include "data_to_heap.h"
#include "financial_data_reader.h"
#include <iostream>
#include <vector>
#include <algorithm>

int Heap::child_index(int n) {
  // Returns index of child of node n
  return n * 2;
}

int Heap::parent_index(int n) {
  // Returns index of parent of node n
  // If n=1 at root node
  if (n==1) return -1;
  else {
    return (int) n/ 2;
  }
}

void Heap::insert(double val, std::string name) {
  if (heap_struct.size >= 500) {
    std::cout << "Max heap size reached!" << std::endl;
    return;
  } else {
    heap_struct.size++;
    heap_struct.returns[heap_struct.size] = val;
    heap_struct.names[heap_struct.size] = name;
    Heap::bubble_up(heap_struct.size);
  }
}

void Heap::bubble_up(int index) {
  int p = Heap::parent_index(index);

  // If p == -1, we are at root node
  if (p == -1) return;

  if (heap_struct.returns[p] < heap_struct.returns[index]) {
    std::swap(heap_struct.returns[p], heap_struct.returns[index]);
    std::swap(heap_struct.names[p], heap_struct.names[index]);
    Heap::bubble_up(p);
  }
}

void Heap::init_heap() {
  heap_struct.size = 0;
}

void Heap::make_heap(const std::vector<double> &values,
        const std::vector<std::string> &input_names) {
  Heap::init_heap();

  for (int i = 0; i < values.size(); i++) {
    Heap::insert(values[i], input_names[i]);
  }
}

void Heap::display() {
  std::cout << " ------------- Returns of Heap ------------- " << std::endl;
  for (int i = 0; i < heap_struct.size; i++) {
    std::cout << heap_struct.names[i] << ": " <<
      heap_struct.returns[i] << std::endl;
  }
}
