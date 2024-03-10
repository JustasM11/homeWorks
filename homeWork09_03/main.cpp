#include <iostream>

#include "lib.hpp"

int main() {
  std::string inputLine;
  std::cout << "Enter a line: " << std::endl;
  std::getline(std::cin, inputLine);
  int wordsCount = calculateWordsCount(inputLine);

  std::cout << "The number of words in the line: " << wordsCount << std::endl;
  return 0;
}
