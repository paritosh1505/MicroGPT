#include "tokenizer.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>
int main() {
  std::mt19937 rng(42);
  std::ifstream inputData("../Names.txt");
  std::string DataContent;
  std::vector<std::string> vecdata;
  if (!inputData) {
    throw std::runtime_error("Unable to open the file");
  }
  while (std::getline(inputData, DataContent)) {
    if (!DataContent.empty())
      vecdata.push_back(DataContent);
  }
  std::shuffle(vecdata.begin(), vecdata.end(), rng);
  Tokenizer token(vecdata);
  auto tokenEncode = token.encode("hello");
  std::string decodedVal = token.decode(tokenEncode);
  std::cout << decodedVal;
  return 0;
}
