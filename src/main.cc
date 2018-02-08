#include <iostream>
#include "financial_data_reader.h"
#include "data_to_heap.h"

int main () {
   data_to_vector_of_vectors();
   display_vector_of_vectors();
   std::cout << "Total years of data: " << fund_names.size();
   std::cout << std::endl << std::endl;

   std::cout << "Some change\n";
  
   Heap data_2014(fund_returns[0], fund_names[0]);

   data_2014.display();

   return 0;
 }
