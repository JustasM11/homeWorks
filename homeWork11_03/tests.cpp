#include <gtest/gtest.h>

#include "lib.hpp"

TEST(IPTest, CorrectIP) {
  std::string ip = "192.168.1.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// Empty IP
TEST(IPTest, EmptyIP1) {
  std::string ip = "";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// Empty IP
TEST(IPTest, EmptyIP2) {
  std::string ip = "...";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// Leading zero in octet
TEST(IPTest, LeadingZeroInOctet) {
  std::string ip = "01.100.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::LeadingZero);
}

// 1 dot in IP
TEST(IPTest, OneDotInIP) {
  std::string ip = "192.168100100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// 2 dots in IP
TEST(IPTest, TwoDotsInIP) {
  std::string ip = "192.168.100100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// 4 dots in IP
TEST(IPTest, ThreeDotsInIP) {
  std::string ip = "192.168.100.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// non-numeric characters in 1st octet
TEST(IPTest, NonNumericCharactersIn1stOctet) {
  std::string ip = "a.168.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 2st octet
TEST(IPTest, NonNumericCharactersIn2stOctet2) {
  std::string ip = "10a.168.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 2st octet
TEST(IPTest, NonNumericCharactersIn2stOctet3) {
  std::string ip = "1a0.168.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 1st octet
TEST(IPTest, NonNumericCharactersIn2stOctet4) {
  std::string ip = "2a.168.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 1st octet
TEST(IPTest, NonNumericCharactersIn1stOctet5) {
  std::string ip = "a0.168.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 2nd octet
TEST(IPTest, NonNumericCharactersIn2ndOctet) {
  std::string ip = "192.a.100.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 3rd octet
TEST(IPTest, NonNumericCharactersIn3rdOctet) {
  std::string ip = "192.168.a.100";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// non-numeric characters in 4th octet
TEST(IPTest, NonNumericCharactersIn4thOctet) {
  std::string ip = "192.168.100.a";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// 1st octet is 255
TEST(IPTest, FirstOctetIs255) {
  std::string ip = "255.255.255.255";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1st octet is 256
TEST(IPTest, FirstOctetIs256) {
  std::string ip = "256.255.255.255";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::OctetOutOfRange);
}

// 1st octet is 199
TEST(IPTest, FirstOctetIs199) {
  std::string ip = "199.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1st octet is 1
TEST(IPTest, FirstOctetIs1) {
  std::string ip = "1.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1st octet is 99
TEST(IPTest, FirstOctetIs99) {
  std::string ip = "99.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1st octet is 254
TEST(IPTest, FirstOctetIs254) {
  std::string ip = "254.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1st octet is 300
TEST(IPTest, FirstOctetIs300) {
  std::string ip = "300.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::OctetOutOfRange);
}

// 1st octet is 261
TEST(IPTest, FirstOctetIs261) {
  std::string ip = "261.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::OctetOutOfRange);
}

// 1st octet is 1000
TEST(IPTest, FirstOctetIs1000) {
  std::string ip = "1000.168.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// 2st octet is 1000
TEST(IPTest, SecondOctetIs1000) {
  std::string ip = "192.1000.100.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// Correct IPs:
// 127.0.0.1
TEST(IPTest, CorrectIP1) {
  std::string ip = "127.0.0.1";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 255.255.255.255
TEST(IPTest, CorrectIP2) {
  std::string ip = "255.255.255.255";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 1.2.3.4
TEST(IPTest, CorrectIP3) {
  std::string ip = "1.2.3.4";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// 55.77.213.101
TEST(IPTest, CorrectIP4) {
  std::string ip = "55.77.213.101";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::CorrectIPAddress);
}

// Incorrect IPs:
// 255.256.257.258
TEST(IPTest, IncorrectIP1) {
  std::string ip = "255.256.257.258";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::OctetOutOfRange);
}

// 0.55.33.22.
TEST(IPTest, IncorrectIP2) {
  std::string ip = "0.55.33.22.";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}

// 10.00.000.0
TEST(IPTest, IncorrectIP3) {
  std::string ip = "10.00.000.0";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::LeadingZero);
}

// 23.055.255.033
TEST(IPTest, IncorrectIP4) {
  std::string ip = "23.055.255.033";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::LeadingZero);
}

// 65.123..9
TEST(IPTest, IncorrectIP5) {
  std::string ip = "65.123..9";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidOctetLength);
}

// a.b.c.d
TEST(IPTest, IncorrectIP6) {
  std::string ip = "a.b.c.d";
  ErrorCode error = isIpAddressValid(ip);
  ASSERT_EQ(error, ErrorCode::InvalidCharactersInOctet);
}
