#include "lib.hpp"

#include <iostream>
#include <string>

bool isCorrectNumber(const std::string& number) {
  if (number.length() != 4) {
    return false;
  }

  for (size_t i = 0; i < number.length(); i++) {
    if (number[i] < '0' or number[i] > '9') {
      return false;
    }
  }
  return true;
}

GuessResult verifyGuess(const std::string& correctNumber,
                        const std::string& guessNumber) {
  GuessResult result;
  result.bulls = 0;
  result.cows = 0;
  std::string usedCorrectNumberChars = "0000";
  std::string usedGuessNumberChars = "0000";

  // Quick check for bulls
  for (size_t i = 0; i < correctNumber.length(); i++) {
    if (correctNumber[i] == guessNumber[i]) {
      result.bulls++;
      // std::cout << "Bull found: at i: " << i << std::endl;
      usedCorrectNumberChars[i] = '1';
      usedGuessNumberChars[i] = '1';
    }
  }

  // Check for cows
  for (size_t i = 0; i < correctNumber.length(); i++) {
    // Skip already matched digit
    if (usedCorrectNumberChars[i] == '1') {
      continue;
    }

    for (size_t j = 0; j < guessNumber.length(); j++) {
      // Skip already matched digit
      if (usedGuessNumberChars[j] == '1') {
        continue;
      }

      if (correctNumber[i] == guessNumber[j]) {
        result.cows++;
        // std::cout << "Cow found: at i: " << i << " j: " << j << std::endl;
        usedCorrectNumberChars[i] = '1';
        usedGuessNumberChars[j] = '1';
        break;
      }
    }
  }

  return result;
}