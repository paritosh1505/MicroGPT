#pragma once

#include <string>
#include <unordered_map>
#include <vector>
class Tokenizer {
private:
  std::vector<char> id_to_char;
  std::unordered_map<char, int> char_to_id;
  int BOS;

public:
  Tokenizer(const std::vector<std::string> &docs);
  std::vector<int> encode(const std::string &text) const;
  std::string decode(const std::vector<int> &token) const;

  int vocab_size() const;
  int bos_token() const;
};