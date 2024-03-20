#include <gtest/gtest.h>

#include "lib.hpp"

TEST(getRepeatingNumber, test1) {
  int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108,
                     110, 109, 112, 113, 116, 117, 118};
  int number = getRepeatingNumber(numbers);
  ASSERT_EQ(number, 108);
}

TEST(getRepeatingNumber, test2) {
  int numbers[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  ASSERT_THROW(getRepeatingNumber(numbers), std::runtime_error);
}

TEST(getRepeatingNumber, test3) {
  int numbers[15] = {1, 2, 3, 4, 5, 6, 7, 8, 16, 10, 11, 12, 13, 14, 15};
  ASSERT_THROW(getRepeatingNumber(numbers), std::runtime_error);
}

TEST(getRepeatingNumber, test4) {
  int numbers[15] = {1, 2, 3, 4, 5, 6, 7, 8, -16, 10, 11, 12, 13, 14, 15};
  ASSERT_THROW(getRepeatingNumber(numbers), std::runtime_error);
}
