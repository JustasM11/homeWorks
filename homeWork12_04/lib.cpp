#include "lib.hpp"

#include <cassert>
#include <iostream>

int getRepeatingNumber(int numbers[15]) {
  // Note: if numbers are not sequential, this will produce incorrect result.
  // For example, if numbers are {7, 8, 9, 10, 11, 12, 14, 15, 13, 1, 2, 3, 4,
  // 5, 16} it will return 1 that is not correct.

  int helperArray[15] = {};
  int baseNumber = numbers[0];
  for (int i = 0; i < 15; i++) {
    int shift = numbers[i] - baseNumber;
    if (shift < 0) {
      shift = 15 - -shift;
    }
    std::cout << "shift: " << shift << std::endl;

    if (shift > 14 or shift < 0) {
      throw std::runtime_error("Numbers are not sequential");
    }

    if (helperArray[shift] == 1) {
      return numbers[i];
    }
    helperArray[shift] = 1;
  }

  throw std::runtime_error("No repeating number found");
}