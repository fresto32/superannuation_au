// financial_data_reader.h file
#ifndef _financial_data_reader_h
#define _financial_data_reader_h

#include <vector>
#include <string>

// Vectors to store parallel vectors of fund names and returns for each year
// of financial data
extern std::vector<std::vector<std::string> > fund_names;
extern std::vector<std::vector<double> > fund_returns;

// Converts raw data to vector of vector format
void data_to_vector_of_vectors();

// Displays the vector of vectors in std::cout format
void display_vector_of_vectors();

#endif
