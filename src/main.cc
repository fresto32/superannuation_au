#include <iostream>
#include "financial_data_reader.h"
#include "data_to_heap.h"

int main () {
   data_to_vector_of_vectors();
   display_vector_of_vectors();
   std::cout << "Fund Names size: " << fund_names.size();
   std::cout << std::endl << std::endl;

   std::cout << "Some change";

   return 0;
 }
