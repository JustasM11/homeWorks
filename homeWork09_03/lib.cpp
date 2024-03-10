#include "lib.hpp"

#include <iostream>
#include <string>

int calculateWordsCount(const std::string& inputLine) {
  int wordsCount = 0;
  bool isWord = false;
  for (long unsigned int i = 0; i < inputLine.length(); i++) {
    if (inputLine[i] != ' ') {
      if (isWord == false) {
        wordsCount++;
        isWord = true;
      }
    } else {
      isWord = false;
    }
  }
  return wordsCount;
}