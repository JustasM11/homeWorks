#include <gtest/gtest.h>

#include "lib.hpp"

// isCorrectNumber 0000
TEST(isCorrectNumber, test1) {
  std::string number = "0000";
  bool result = isCorrectNumber(number);
  ASSERT_TRUE(result);
}

// isCorrectNumber 9999
TEST(isCorrectNumber, test2) {
  std::string number = "9999";
  bool result = isCorrectNumber(number);
  ASSERT_TRUE(result);
}

// isCorrectNumber ""
TEST(isCorrectNumber, test3) {
  std::string number = "";
  bool result = isCorrectNumber(number);
  ASSERT_FALSE(result);
}

// isCorrectNumber "-1"
TEST(isCorrectNumber, test4) {
  std::string number = "-1";
  bool result = isCorrectNumber(number);
  ASSERT_FALSE(result);
}

// isCorrectNumber "111"
TEST(isCorrectNumber, test5) {
  std::string number = "111";
  bool result = isCorrectNumber(number);
  ASSERT_FALSE(result);
}

// isCorrectNumber "12345"
TEST(isCorrectNumber, test6) {
  std::string number = "12345";
  bool result = isCorrectNumber(number);
  ASSERT_FALSE(result);
}

// isCorrectNumber "abcd"
TEST(isCorrectNumber, test7) {
  std::string number = "abcd";
  bool result = isCorrectNumber(number);
  ASSERT_FALSE(result);
}

// verifyGuess 1234 1234
TEST(verifyGuess, test1) {
  std::string correctNumber = "1234";
  std::string guessNumber = "1234";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 4);
  ASSERT_EQ(result.cows, 0);
}

// verifyGuess 1234 4321
TEST(verifyGuess, test2) {
  std::string correctNumber = "1234";
  std::string guessNumber = "4321";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 0);
  ASSERT_EQ(result.cows, 4);
}

// verifyGuess 1234 5678
TEST(verifyGuess, test3) {
  std::string correctNumber = "1234";
  std::string guessNumber = "5678";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 0);
  ASSERT_EQ(result.cows, 0);
}

// verifyGuess 1234 1243
TEST(verifyGuess, test4) {
  std::string correctNumber = "1234";
  std::string guessNumber = "1243";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 2);
  ASSERT_EQ(result.cows, 2);
}

// 5671 7251
// 1 2
TEST(verifyGuess, test5) {
  std::string correctNumber = "5671";
  std::string guessNumber = "7251";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 1);
  ASSERT_EQ(result.cows, 2);
}

// 1234 1234
// 4 0
TEST(verifyGuess, test6) {
  std::string correctNumber = "1234";
  std::string guessNumber = "1234";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 4);
  ASSERT_EQ(result.cows, 0);
}

// 0023 2013
// 2 1
TEST(verifyGuess, test7) {
  std::string correctNumber = "0023";
  std::string guessNumber = "2013";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 2);
  ASSERT_EQ(result.cows, 1);
}

// 2013 0023
// 2 1
TEST(verifyGuess, test8) {
  std::string correctNumber = "2013";
  std::string guessNumber = "0023";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 2);
  ASSERT_EQ(result.cows, 1);
}

// 1111 1111
// 4 0
TEST(verifyGuess, test9) {
  std::string correctNumber = "1111";
  std::string guessNumber = "1111";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 4);
  ASSERT_EQ(result.cows, 0);
}

// 1222 2234
// 1 1
TEST(verifyGuess, test10) {
  std::string correctNumber = "1222";
  std::string guessNumber = "2234";
  GuessResult result = verifyGuess(correctNumber, guessNumber);
  ASSERT_EQ(result.bulls, 1);
  ASSERT_EQ(result.cows, 1);
}