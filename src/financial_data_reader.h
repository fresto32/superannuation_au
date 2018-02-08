// financial_data_reader.h file
#ifndef _financial_data_reader_h
#define _financial_data_reader_h

// Converts raw data to vector of vector format
void data_vector_of_vectors();

// Vectors to store parallel vectors of fund names and returns for each year
// of financial data
std::vector<std::vector<std::string> > fund_names;
std::vector<std::vector<double> > fund_returns;

// Displays the vector of vectors in std::cout format
void display_vector_of_vectors();

#endif
