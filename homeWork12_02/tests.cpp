#include <gtest/gtest.h>

#include "lib.hpp"

TEST(mergeSort, test1) {
  float initialArray[15] = {4, 3, 6, 1, 3, 6, 0, 1, 9, 7, 2, 3, 5, 8, 4};
  float helperArray[15] = {};

  mergeSort(initialArray, helperArray);

  float expectedArray[15] = {9, 8, 7, 6, 6, 5, 4, 4, 3, 3, 3, 2, 1, 1, 0};
  for (int i = 0; i < 15; i++) {
    ASSERT_EQ(initialArray[i], expectedArray[i]);
  }
}

TEST(mergeSort, test2) {
  float initialArray[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  float helperArray[15] = {};

  mergeSort(initialArray, helperArray);

  float expectedArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < 15; i++) {
    ASSERT_EQ(initialArray[i], expectedArray[i]);
  }
}

TEST(mergeSort, test3) {
  float initialArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  float helperArray[15] = {};

  mergeSort(initialArray, helperArray);

  float expectedArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  for (int i = 0; i < 15; i++) {
    ASSERT_EQ(initialArray[i], expectedArray[i]);
  }
}

TEST(mergeSort, test4) {
  float initialArray[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  float helperArray[15] = {};

  mergeSort(initialArray, helperArray);

  float expectedArray[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 15; i++) {
    ASSERT_EQ(initialArray[i], expectedArray[i]);
  }
}
