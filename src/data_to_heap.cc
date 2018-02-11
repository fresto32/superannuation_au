#include "data_to_heap.h"
#include "financial_data_reader.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale>

int Heap::child_index(int n) {
  // Returns index of child of index n
  // If the generated child index is greater than the heap size, return -1
  return (n*2 > heap_struct.size) ? -1 : n*2;
}

int Heap::parent_index(int n) {
  // Returns index of parent of index n
  // If n=1 at root node
  if (n==1) return -1;
  else {
    return (int) n/ 2;
  }
}

void Heap::insert(double val, std::string name) {
  // Inserts an element, val, and its acccompany tag (name) into the heap
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
  // Takes in a heap index (assumed less than size of heap) and recursively
  // swaps its place with its parents if the value at the index is larger 
  // than the parents
  int p = Heap::parent_index(index);

  // If p == -1, we are at root node
  if (p == -1) return;

  // If the value of index's parent is less than itself, swap values and 
  // bubble up the parent
  if (heap_struct.returns[p] < heap_struct.returns[index]) {
    std::swap(heap_struct.returns[p], heap_struct.returns[index]);
    std::swap(heap_struct.names[p], heap_struct.names[index]);
    Heap::bubble_up(p);
  }
}
void Heap::extract_max(double *max_return, std::string *max_fund) {
  // Takes pointers of max_return and max_fund (name) in order to manipulate
  // two pieces of data. The extract_max function returns the root of the heap,
  // i.e. the largest value and calls bubble down to reorganize the heap.
  
  // if heap empty, return
  if (heap_struct.size == 0) return;

  // set max_return/max_fund to top of respective heaps
  *max_return = heap_struct.returns[1];
  *max_fund = heap_struct.names[1];

  // set the bottom most element to the root of the heap
  heap_struct.returns[1] = heap_struct.returns[heap_struct.size];
  heap_struct.names[1] = heap_struct.names[heap_struct.size];
  heap_struct.size--;

  // bubble down the top most element
  if (heap_struct.size > 1) Heap::bubble_down(1);
}

void Heap::bubble_down(int index) {
  // The opposite of bubble_up, except the elements that are swapped are the
  // between the parent and the largest child (if there is a swap)
   
  // set children
  int c = Heap::child_index(index);
  if (c == -1) return;

  // set current largest value to index 
  int largest_value_index = index;

  // use for loop to determine which is the largest of parent and children
  for (int i = 0; i < std::min(heap_struct.size, 2); i++) 
    if (heap_struct.returns[c+i] > heap_struct.returns[largest_value_index]) 
      largest_value_index = c + i; 

  // if the largest_value_index has changed, swap indices and recall function
  if (largest_value_index != index) {
    std::swap(heap_struct.returns[largest_value_index],
       heap_struct.returns[index]); 
    std::swap(heap_struct.names[largest_value_index],
       heap_struct.names[index]);
    Heap::bubble_down(largest_value_index);
  }
}

void Heap::heap_sort(std::vector<double> &returns,
    std::vector<std::string> &names) {
  // Sorts the heap by iteratively removing the largest element from the heap
  // and putting the pair values into the return and names vector

  if (heap_struct.size == 0) return;
 
  // intiializing variables to pass into extract_max function 
  double max_return;
  std::string max_fund;
  const int iterations = heap_struct.size;

  for (int i = 0; i < iterations; i++) {
    Heap::extract_max(&max_return, &max_fund);
    returns.push_back(max_return);
    names.push_back(max_fund);
  }
}

void Heap::make_heap(const std::vector<double> &values,
        const std::vector<std::string> &input_names) {
  // Faster heap construction occurs by bubbling down all elements rather
  // than incremental insertion

  // Initialize heap
  heap_struct.size = values.size();

  // Insert all elements arbitrarily into heap
  for (int i = 0; i < heap_struct.size; i++) {
    heap_struct.returns[i+1] = values[i];
    heap_struct.names[i+1] = input_names[i];
  }

  // Bubble all elements down from base to root to organize heap
  for (int j = heap_struct.size; j > 0; j--) Heap::bubble_down(j);
}

void Heap::display() {
  std::cout << "\t\t   ------------- Returns of Heap ------------- \n";
  for (int i = 1; i < heap_struct.size; i++) {
    std::cout << heap_struct.names[i] << ": " <<
      heap_struct.returns[i] << std::endl;
  }
  std::cout << "\n\tSize: " << heap_struct.size << std::endl << std::endl;
}

void Heap::display(const std::vector<double> &returns,
    const std::vector<std::string> &names) {
  std::cout << "\t\t   ------------- Returns of Sorted Heap ------------- \n";
  for (int i = 0; i < returns.size(); i++) {
    std::cout << "Index " << std::right << std::setfill(' ') <<  std::setw(3)
      << i << ":";
    std::cout << std::left << std::setfill('.') << std::setw(70) << names[i]
      + ": " << " " <<  returns[i]*100 << "%" <<  std::endl;
  }
  std::cout << "\n\tSize: " << returns.size() << std::endl << std::endl;
}
