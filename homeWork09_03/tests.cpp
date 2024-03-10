#include <gtest/gtest.h>

#include "lib.hpp"

// abcd abce skjc ahdy
// 4
TEST(calculateWordsCount, test1) {
  std::string inputLine = "abcd abce skjc ahdy";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(4, wordsCount);
}

//..33 !!@! WWW )))))))))) __ ))
// 6
TEST(calculateWordsCount, test2) {
  std::string inputLine = "..33 !!@! WWW )))))))))) __ ))";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(6, wordsCount);
}

//    _
// 1
TEST(calculateWordsCount, test3) {
  std::string inputLine = "    _    ";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(1, wordsCount);
}

//
// 0
TEST(calculateWordsCount, test4) {
  std::string inputLine = "     ";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(0, wordsCount);
}

// Empty line
// 0
TEST(calculateWordsCount, test5) {
  std::string inputLine = "";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(0, wordsCount);
}

//    1 2 3
// 3
TEST(calculateWordsCount, test6) {
  std::string inputLine = "    1 2 3";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(3, wordsCount);
}

// 1 2 3
// 3
TEST(calculateWordsCount, test7) {
  std::string inputLine = "1 2 3    ";
  int wordsCount = calculateWordsCount(inputLine);
  ASSERT_EQ(3, wordsCount);
}
