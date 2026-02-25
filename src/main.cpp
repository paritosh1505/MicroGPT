#include "tokenizer.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int main() {
  std::ifstream inputData("../Names.txt");
  std::string DataContent;
  std::vector<std::string> vecdata;
  if (!inputData) {
    throw std::runtime_error("Unable to open the file");
  }
  while (std::getline(inputData, DataContent)) {
    vecdata.push_back(DataContent);
  }

  return 0;
}