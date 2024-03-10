#include <gtest/gtest.h>

#include "lib.hpp"

TEST(convertTextToCaesar, test1) {
  std::string text = "abc";
  int code = 1;
  std::string expected = "bcd";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test2) {
  std::string text = "abc";
  int code = 2;
  std::string expected = "cde";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test3) {
  std::string text = "abc";
  int code = 3;
  std::string expected = "def";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test4) {
  std::string text = "abc";
  int code = 4;
  std::string expected = "efg";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test20) {
  std::string text = "abcd";
  int code = 20;
  std::string expected = "uvwx";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test25) {
  std::string text = "abc";
  int code = 25;
  std::string expected = "zab";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test26) {
  std::string text = "abc";
  int code = 26;
  std::string expected = "abc";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, test27) {
  std::string text = "abc";
  int code = 27;
  std::string expected = "bcd";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testText1) {
  std::string text = "aBxZ*";
  int code = 67;
  std::string expected = "pQmO*";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testText2) {
  std::string text = "The quick brown fox jumps over the lazy dog";
  int code = 3;
  std::string expected = "Wkh txlfn eurzq ira mxpsv ryhu wkh odcb grj";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testEmpty) {
  std::string text = "";
  int code = 1;
  std::string expected = "";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testCode0) {
  std::string text = "abc";
  int code = 0;
  std::string expected = "abc";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testCodeNegative1) {
  std::string text = "abc";
  int code = -1;
  std::string expected = "zab";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testCodeNegative2) {
  std::string text = "abc";
  int code = -2;
  std::string expected = "yza";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testCodeNegative26) {
  std::string text = "abc";
  int code = -26;
  std::string expected = "abc";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}

TEST(convertTextToCaesar, testCodeNegative20) {
  std::string text = "abc";
  int code = -20;
  std::string expected = "ghi";
  std::string actual = convertTextToCaesar(text, code);
  ASSERT_EQ(expected, actual);
}
