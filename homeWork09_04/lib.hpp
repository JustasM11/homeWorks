#pragma once
#include <string>

struct GuessResult {
  int bulls;
  int cows;
};

bool isCorrectNumber(const std::string& number);
GuessResult verifyGuess(const std::string& correctNumber,
                        const std::string& guessNumber);
