#include <iostream>

#include "lib.hpp"

int main() {
  std::string decNumber;
  std::cout << "Enter a dec number (1-3999): " << std::endl;
  std::cin >> decNumber;

  if (!isCorrectNumber(decNumber)) {
    std::cerr << "Incorrect number!" << std::endl;
    return 1;
  }

  std::string romeNumber = convertDecToRome(decNumber);
  std::cout << "Rome number: " << romeNumber << std::endl;

  return 0;
}
