#include "lib.hpp"

#include <cassert>
#include <iostream>

void mergeSort(float initialArray[15], float helperArray[15]) {
  int arraySize = 15;
  int rangeSize = 1;
  float* temp;
  while (true) {
    rangeSize = rangeSize * 2;  // Presorting starting from smallest pieces

    if (rangeSize / 2 + 1 > arraySize) {
      break;
    }

    int rangeNumber = 0;  // Sorting all ranges
    while (true) {
      int firstIndex = rangeSize * rangeNumber;        // First half of range
      int secondIndex = firstIndex + (rangeSize / 2);  // Second half of range
      int middleIndex = secondIndex;
      int endIndex = firstIndex + rangeSize - 1;

      if (firstIndex >= arraySize) {
        break;
      }

      for (int currentIndex = firstIndex;
           currentIndex <= endIndex and currentIndex < arraySize;
           currentIndex++) {
        // Debug info
        // std::cout << "rangeSize: " << rangeSize << " rangeNumber: " <<
        // rangeNumber << " currentIndex: " << currentIndex << " firstIndex: "
        // << firstIndex << " secondIndex: " << secondIndex << std::endl;
        if (firstIndex < middleIndex and secondIndex <= endIndex and
            secondIndex < arraySize) {
          if (initialArray[firstIndex] > initialArray[secondIndex]) {
            // assert (currentIndex < arraySize);
            // assert (firstIndex < arraySize);
            helperArray[currentIndex] = initialArray[firstIndex];
            firstIndex++;
          } else {
            // assert (currentIndex < arraySize);
            // assert (secondIndex < arraySize);
            helperArray[currentIndex] = initialArray[secondIndex];
            secondIndex++;
          }
        } else if (firstIndex < middleIndex) {
          // assert (currentIndex < arraySize);
          // assert (firstIndex < arraySize);
          helperArray[currentIndex] = initialArray[firstIndex];
          firstIndex++;
        } else {
          // assert (currentIndex < arraySize);
          // assert (secondIndex < arraySize);
          helperArray[currentIndex] = initialArray[secondIndex];
          secondIndex++;
        }
      }

      rangeNumber++;
    }

    // Swapping arrays
    temp = helperArray;
    helperArray = initialArray;
    initialArray = temp;

    // Printing intermediate results
    // std::cout << "Resulting array after " << rangeSize << " rangeSize" <<
    // std::endl; for (int i = 0; i < 15; i++) {
    //   std::cout << initialArray[i] << " ";
    // }
    // std::cout << std::endl;
  }
}