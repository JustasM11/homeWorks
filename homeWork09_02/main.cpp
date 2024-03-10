#include <iostream>

#include "lib.hpp"

int main() {
  std::string inputNumber;
  std::cout << "Enter a number: ";
  std::cin >> inputNumber;
  checkResult result = checkNumberIsCorrect(inputNumber);
  std::cout << "The number is correct: " << (result.isCorrect ? "Yes" : "No")
            << std::endl;
  if (result.isCorrect == false) {
    std::cout << "Error message: " << result.errorMessage << std::endl;
  }
}
