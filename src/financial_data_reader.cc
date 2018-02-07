#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Vectors to store parallel vectors of fund names and returns
std::vector<std::string> fund_names;
std::vector<double> fund_returns;

// reserve 343 items for each
// fund_names.reserve(350);
// fund_returns.reserve(350);

void data_to_array() {
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

  while (inFile >> x) {
    // If the next value is a letter or " " add it to y, else push y, push x
    if ((x.at(0) > 57) || (x.at(0) == 32) || (x.at(0) < 45)) {
        y += " " + x;
    } else {
        fund_names.push_back(y);
        y = "";
        fund_returns.push_back(std::stod(x));
    }  
  }
}

void display() {
  for (int i = 0; i < fund_names.size(); i++) {
    std::cout << fund_names[i] << " " << fund_returns[i] << std::endl;
  }
  std::cout << "Size of Fund Names: " << fund_names.size() << std::endl;
  std::cout << "Size of Fund Returns: " << fund_returns.size() << std::endl;

  if (fund_names.size() != fund_returns.size())
    std::cout << "Error: Fund names and returns not same size!" << std::endl;
}

int main () {
  data_to_array();
  display();
  return 0;
}



