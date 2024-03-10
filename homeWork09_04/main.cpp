#include <iostream>

#include "lib.hpp"

int main() {
  std::string correctNumber;
  std::cout << "Enter a 4-digits number: " << std::endl;
  std::cin >> correctNumber;

  if (!isCorrectNumber(correctNumber)) {
    std::cerr << "Incorrect number!" << std::endl;
    return 1;
  }

  std::string guessNumber;
  GuessResult guessResult;
  while (true) {
    std::cout << "Try to guess 4-digits number: " << std::endl;
    std::cin >> guessNumber;
    if (!isCorrectNumber(correctNumber)) {
      std::cerr << "Incorrect number!" << std::endl;
      continue;
    }
    guessResult = verifyGuess(correctNumber, guessNumber);

    std::cout << "Bulls: " << guessResult.bulls << " Cows: " << guessResult.cows
              << std::endl
              << std::endl;
  }

  return 0;
}
