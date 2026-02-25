#pragma once

#include <string>
#include <unordered_map>
#include <vector>
class Tokenizer {
private:
  std::vector<char> charEntry;
  std::unordered_map<char, int> mapVal;
  int BOS;

public:
  Tokenizer(std::vector<std::string> &docs);
  std::vector<int> encode(const std::string &text) const;
  std::string decode(std::vector<int> &token) const;

  int vocab_size() const;
  int bos_token() const;
};