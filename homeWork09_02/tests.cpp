#include <gtest/gtest.h>

#include "lib.hpp"

TEST(checkResult, correctNumber) {
  std::string inputNumber = "123.456";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

TEST(checkResult, twoDots) {
  std::string inputNumber = "123.456.789";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

TEST(checkResult, noDigits) {
  std::string inputNumber = ".-";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

TEST(checkResult, emptyNumber) {
  std::string inputNumber = "";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

TEST(checkResult, minusFirst) {
  std::string inputNumber = "-123.456";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

TEST(checkResult, notNumber) {
  std::string inputNumber = "123.456a";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

TEST(checkResult, zeroOneTwoThree) {
  std::string inputNumber = "123";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// 00.000
TEST(checkResult, zeroZeroDotZeroZeroZero) {
  std::string inputNumber = "00.000";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// .15
TEST(checkResult, dotOneFive) {
  std::string inputNumber = ".15";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// 165.
TEST(checkResult, oneSixFiveDot) {
  std::string inputNumber = "165.";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// 999999999999999999999999999999999.999999999999999999999
TEST(checkResult, bigNumber) {
  std::string inputNumber =
      "999999999999999999999999999999999.999999999999999999999";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// −1.0
TEST(checkResult, minusOneDotZero) {
  std::string inputNumber = "-1.0";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// −.35
TEST(checkResult, minusDotThreeFive) {
  std::string inputNumber = "-.35";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_TRUE(result.isCorrect);
  ASSERT_TRUE(result.errorMessage.empty());
}

// 1.2.3
TEST(checkResult, oneDotTwoDotThree) {
  std::string inputNumber = "1.2.3";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

//−.
TEST(checkResult, minusDot) {
  std::string inputNumber = "-.";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

// 11e-3
TEST(checkResult, oneOneEThree) {
  std::string inputNumber = "11e-3";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}

//+25
TEST(checkResult, plusTwoFive) {
  std::string inputNumber = "+25";
  checkResult result = checkNumberIsCorrect(inputNumber);
  ASSERT_FALSE(result.isCorrect);
  ASSERT_FALSE(result.errorMessage.empty());
}