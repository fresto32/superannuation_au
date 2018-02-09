#include <iostream>
#include "financial_data_reader.h"
#include "data_to_heap.h"
#include <vector>

int main () {
  data_to_vector_of_vectors();
  display_vector_of_vectors();

  int fund_names_size = fund_names.size();
  std::cout << "Total years of data: " << fund_names_size;
  std::cout << std::endl << std::endl;

  // Preparing variables needed for heapsorting data
  // Vectors to hold sorted data
  std::vector<std::vector<std::string> > sorted_fund_names;
  std::vector<std::vector<double> > sorted_fund_returns;

  // Initializing vectors to be manipulated
  sorted_fund_returns.resize(fund_names_size);
  sorted_fund_names.resize(fund_names_size);

  // Creating vector to hold Heap objects
  std::vector<Heap> heap_data;

  // Creating heap objects for each year of returns/fund names and sorting
  // them by heap sort
  for (int i = 0; i < fund_names_size; i++) {
    heap_data.push_back(Heap());
    heap_data[i].make_heap(fund_returns[i], fund_names[i]);
    heap_data[i].heap_sort(sorted_fund_returns[i], sorted_fund_names[i]);
    heap_data[i].display(sorted_fund_returns[i], sorted_fund_names[i]);
  }

  return 0;

 }
