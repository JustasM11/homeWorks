#include "lib.hpp"

#include <iostream>
#include <string>

checkResult checkNumberIsCorrect(const std::string& inputNumber) {
  bool dotFound = false;
  bool numberFound = false;
  for (long unsigned int i = 0; i < inputNumber.length(); i++) {
    char currentChar = inputNumber[i];

    if (currentChar == '.') {
      if (dotFound == true) {
        return checkResult{false, "There are more than one dot"};
      } else {
        dotFound = true;
        continue;
      }
    } else if (currentChar == '-') {
      if (i != 0) {
        return checkResult{false, "The minus is not the first character"};
      } else {
        continue;
      }
    } else if (currentChar < '0' or currentChar > '9') {
      return checkResult{false, "There is a non-digit character"};
    } else {
      numberFound = true;
      continue;
    }
  }

  if (numberFound == false) {
    return checkResult{false, "There are no digits"};
  }

  return checkResult{true, ""};
}
