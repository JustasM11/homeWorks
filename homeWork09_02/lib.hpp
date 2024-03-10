#pragma once
#include <string>

struct checkResult {
  bool isCorrect;
  std::string errorMessage;
};

checkResult checkNumberIsCorrect(const std::string& inputNumber);
