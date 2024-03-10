#include <gtest/gtest.h>

#include "lib.hpp"

TEST(isCorrectNumber, test1) {
  std::string number = "1234";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, true);
}

TEST(isCorrectNumber, test2) {
  std::string number = "123";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, true);
}

TEST(isCorrectNumber, test3) {
  std::string number = "12345";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(isCorrectNumber, test4) {
  std::string number = "123a";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(isCorrectNumber, zero) {
  std::string number = "0";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(isCorrectNumber, one) {
  std::string number = "1";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, true);
}

TEST(isCorrectNumber, zero2) {
  std::string number = "00";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(isCorrectNumber, zero4) {
  std::string number = "0000";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(isCorrectNumber, test5) {
  std::string number = "3999";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, true);
}

TEST(isCorrectNumber, test6) {
  std::string number = "4000";
  bool result = isCorrectNumber(number);
  ASSERT_EQ(result, false);
}

TEST(convertDecToRome, test1) {
  std::string number = "1";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "I");
}

TEST(convertDecToRome, test2) {
  std::string number = "2";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "II");
}

TEST(convertDecToRome, test3) {
  std::string number = "3";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "III");
}

TEST(convertDecToRome, test4) {
  std::string number = "4";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "IV");
}

TEST(convertDecToRome, test5) {
  std::string number = "5";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "V");
}

TEST(convertDecToRome, test6) {
  std::string number = "6";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "VI");
}

TEST(convertDecToRome, test7) {
  std::string number = "7";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "VII");
}

TEST(convertDecToRome, test8) {
  std::string number = "8";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "VIII");
}

TEST(convertDecToRome, test9) {
  std::string number = "9";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "IX");
}

TEST(convertDecToRome, test10) {
  std::string number = "10";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "X");
}

TEST(convertDecToRome, test11) {
  std::string number = "11";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XI");
}

// 12
TEST(convertDecToRome, test12) {
  std::string number = "12";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XII");
}

// 24
TEST(convertDecToRome, test24) {
  std::string number = "24";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XXIV");
}

// 48
TEST(convertDecToRome, test48) {
  std::string number = "48";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XLVIII");
}

// 99
TEST(convertDecToRome, test99) {
  std::string number = "99";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XCIX");
}

// 100
TEST(convertDecToRome, test100) {
  std::string number = "100";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "C");
}

// 96
TEST(convertDecToRome, test96) {
  std::string number = "96";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "XCVI");
}

// 123
TEST(convertDecToRome, test123) {
  std::string number = "123";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "CXXIII");
}

// 500
TEST(convertDecToRome, test500) {
  std::string number = "500";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "D");
}

// 182
TEST(convertDecToRome, test182) {
  std::string number = "182";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "CLXXXII");
}

// 728
TEST(convertDecToRome, test728) {
  std::string number = "728";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "DCCXXVIII");
}

// 1456
TEST(convertDecToRome, test1456) {
  std::string number = "1456";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "MCDLVI");
}

// 2912
TEST(convertDecToRome, test2912) {
  std::string number = "2912";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "MMCMXII");
}

// 666
TEST(convertDecToRome, test666) {
  std::string number = "666";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "DCLXVI");
}

// 999
TEST(convertDecToRome, test999) {
  std::string number = "999";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "CMXCIX");
}

// 351
// CCCLI
TEST(convertDecToRome, test351) {
  std::string number = "351";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "CCCLI");
}

// 449
// CDXLIX
TEST(convertDecToRome, test449) {
  std::string number = "449";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "CDXLIX");
}

// 1313
// MCCCXIII
TEST(convertDecToRome, test1313) {
  std::string number = "1313";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "MCCCXIII");
}

// 2020
// MMXX
TEST(convertDecToRome, test2020) {
  std::string number = "2020";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "MMXX");
}

// 888
// DCCCLXXXVIII
TEST(convertDecToRome, test888) {
  std::string number = "888";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "DCCCLXXXVIII");
}

TEST(convertDecToRome, test1234) {
  std::string number = "1234";
  std::string result = convertDecToRome(number);
  ASSERT_EQ(result, "MCCXXXIV");
}