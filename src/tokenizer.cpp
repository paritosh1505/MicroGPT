
#include "tokenizer.hpp"
#include <cstddef>
#include <iostream>
#include <set>
#include <vector>
Tokenizer::Tokenizer(const std::vector<std::string> &docs) {
  std::set<char> allChar;
  for (size_t i = 0; i < docs.size(); i++) {
    std::string word = docs[i];

    for (char c : word) {
      allChar.insert(c);
    }
  }
  for (auto it = allChar.begin(); it != allChar.end(); it++) {
    id_to_char.push_back(*it);
  }
  for (size_t i = 0; i < id_to_char.size(); i++) {
    char_to_id[id_to_char[i]] = static_cast<int>(i);
  }
}

int Tokenizer::vocab_size() const {
  return static_cast<int>(id_to_char.size() + 1);
}
int Tokenizer::bos_token() const { return static_cast<int>(id_to_char.size()); }

std::vector<int> Tokenizer::encode(const std::string &text) const {
  std::vector<int> endCodeInt;
  endCodeInt.push_back(bos_token());
  for (char c : text) {
    endCodeInt.push_back(char_to_id.at(c));
  }
  endCodeInt.push_back(bos_token());
  return endCodeInt;
}

std::string Tokenizer::decode(const std::vector<int> &tokenval) const {
  std::string result;
  for (int token : tokenval) {
    if (token == bos_token())
      continue;
    result += id_to_char[static_cast<size_t>(token)];
  }
  return result;
}