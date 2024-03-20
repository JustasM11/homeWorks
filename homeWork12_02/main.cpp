#include <iostream>

#include "lib.hpp"

int main() {
  float initialArray[15];
  std::cout << "Enter 15 numbers separated by space:" << std::endl;
  for (int i = 0; i < 15; i++) {
    std::cin >> initialArray[i];
  }

  float helperArray[15] = {};

  mergeSort(initialArray, helperArray);

  std::cout << "Sorted result: " << std::endl;
  for (int i = 0; i < 15; i++) {
    std::cout << initialArray[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
