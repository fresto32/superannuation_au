#include <iostream>
#include "financial_data_reader.h"
#include "data_to_heap.h"
#include <vector>

int main () {
  data_to_vector_of_vectors();
  display_vector_of_vectors();
  std::cout << "Total years of data: " << fund_names.size();
  std::cout << std::endl << std::endl;

  Heap data_2014(fund_returns[0], fund_names[0]);
  data_2014.display();
  std::vector<double> fund_2014_returns;
  std::vector<std::string> fund_2014_names;
  data_2014.heap_sort(fund_2014_returns, fund_2014_names);
  data_2014.display(fund_2014_returns, fund_2014_names);



  return 0;
 }
