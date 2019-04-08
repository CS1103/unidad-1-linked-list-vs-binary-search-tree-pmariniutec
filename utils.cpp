#include "utils.h"
#include <iostream>

std::vector<std::string> UTEC::split(std::string& s, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);

  while (std::getline(tokenStream, token, delimiter)) {
	tokens.push_back(token);
  }
  return tokens;
}
