#include <iostream>

#include "lib.hpp"

int main() {
  int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108,
                     110, 109, 112, 113, 116, 117, 118};
  int number = getRepeatingNumber(numbers);

  std::cout << "Repeating number is: " << number << std::endl;

  return 0;
}
