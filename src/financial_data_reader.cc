#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "financial_data_reader.h"

// Vectors to store parallel vectors of fund names and returns for each year
// of financial data
std::vector<std::vector<std::string> > fund_names;
std::vector<std::vector<double> > fund_returns;

void data_to_vector_of_vectors() {
  // This function returns an array of two vectors. The first contains the
  // fund names, the second contains the accompanying fund returns. The format
  // is of parallel arrays.

  std::ifstream inFile;
  inFile.open("/Users/fresto32/Dropbox/[8] Computer Science/superannuation_au/superannuation_data.txt");

  if (!inFile) {
    std::cerr << "Unable to open file\n";
    std::exit(1);
  }

  // Placeholders for the iteration through each word of inFile
  std::string y = "";
  std::string x = "";
  std::string current_year;

  // booleans for start (at start of reading) and in_name (in the date
  // portion of text file)
  bool start = true;
  bool in_name = true;

  // Temporary vectors that can be pushed onto vector of vectors (fund_names
  // and fund_returns)
  std::vector<double> temp_returns;
  std::vector<std::string> temp_names;

  while (inFile >> x) {
    // Store the first year in current_year
    if (start) {
      current_year = x;
      start = false;
      std::cout << "Current_year = " << current_year << std::endl;
    }

    // If the next value is a letter or " " add it to y, else push y, push x
    // Or if we are in the date (in_name) and the year has changed, push names
    // and returns onto vector of vectors
    if ((x.at(0) > 57) || (x.at(0) == 32) || (x.at(0) < 45) || (in_name)) {
        y += " " + x;
        if ((in_name) && (current_year != x)) {
          std::cout << "nested if: value of x =  " << x << std::endl;
          std::cout << " comp: " << current_year.compare(x) << std::endl;
          std::cout << "current year = " << current_year;
          std::cout << "\n";
          fund_names.push_back(temp_names);
          fund_returns.push_back(temp_returns);
          temp_names.clear();
          temp_returns.clear();
          current_year = x;
        }
        in_name = false;
    } else {
        temp_names.push_back(y);
        y = "";
        temp_returns.push_back(std::stod(x));
        in_name = true;
    }
  }
  // Since the final year hasn't been pushed onto the names and returns
  // vectors...
  fund_names.push_back(temp_names);
  fund_returns.push_back(temp_returns);
}

void display_vector_of_vectors() {
// Displays the contents of the fund names and returns arrays
  std::cout << " ------------------DISPLAY------------------" << std::endl;
  for (int j = 0; j < fund_names.size(); j++)
  {
    std::cout << std::endl << "\t------ YEAR = " << j + 2014 << " ------\n";
    for (int i = 0; i < fund_names[j].size(); i++) {
      std::cout << fund_names[j][i] << " " << fund_returns[j][i] 
        << std::endl;
    }
    std::cout << "\nSize of Fund Names: " << fund_names[j].size() 
      << std::endl;
    std::cout << "Size of Fund Returns: " << fund_returns[j].size()
      << std::endl << std::endl;

    if (fund_names[j].size() != fund_returns[j].size())
      std::cout << "Error: Fund names and returns not same size!" 
        << std::endl;
  }
}

// int main () {
//   data_to_vector_of_vectors();
//   display_vector_of_vectors();
//   std::cout << "Fund Names size: " << fund_names.size();
//   std::cout << std::endl << std::endl;
//   return 0;
// }
