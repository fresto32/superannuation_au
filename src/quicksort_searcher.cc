#include "quicksort_searcher.h"
#include <vector>

int fund_rank(int index, const std::vector<double> returns_to_order) {
  // The index of a fund name will be taken and then a modified quicksort
  // position the index in its ranking in returns_to_order. Note only one
  // implementation of quicksort will run to produce the ranking result.
  
  std::vector<double> returns_to_order_c = returns_to_order;

  // swap the value at the index and the last element of returns_to_order
  int size_of_vector = returns_to_order.size();

  std::swap(returns_to_order_c[index], returns_to_order_c[size_of_vector-1]);

  // For every element in the array, if the element is larger than the last
  // element, swap it with the first_high indexed variable
  int first_high = 0;
  for (int i = 0; i < size_of_vector; i++) {
    if (returns_to_order_c[i] > returns_to_order_c[size_of_vector-1]) {
      std::swap(returns_to_order_c[i], returns_to_order_c[first_high]);
      first_high++;
    }
  }

  // Return the first_high indexed variable
  return first_high;
}
