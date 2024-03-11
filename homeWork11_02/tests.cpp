#include <gtest/gtest.h>

#include "lib.hpp"

TEST(EmailTest, CorrectEmail) {
  std::string email = "test@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// Empty email
TEST(EmailTest, EmptyEmail) {
  std::string email = "";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidNameLength);
}

// Empty email name
TEST(EmailTest, EmptyEmailName) {
  std::string email = "@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidNameLength);
}

// Empty email domain
TEST(EmailTest, EmptyEmailDomain) {
  std::string email = "test@";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidDomainLength);
}

// email name is 64 chars and domain is 63 chars
TEST(EmailTest, EmailNameIs64CharsAndDomainIs63Chars) {
  std::string email =
      "1111111111111111111111111111111111111111111111111111111111111111@"
      "111111111111111111111111111111111111111111111111111111111111111";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// email name is 65 chars
TEST(EmailTest, EmailNameIs65Chars) {
  std::string email =
      "11111111111111111111111111111111111111111111111111111111111111111@"
      "111111111111111111111111111111111111111111111111111111111111111";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidNameLength);
}

// email domain is 64 chars
TEST(EmailTest, EmailDomainIs64Chars) {
  std::string email =
      "1111111111111111111111111111111111111111111111111111111111111111@"
      "1111111111111111111111111111111111111111111111111111111111111111";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidDomainLength);
}

// First dot in email name
TEST(EmailTest, FirstDotInEmailName) {
  std::string email = ".aa@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForName);
}

// First dot in email domain
TEST(EmailTest, FirstDotInEmailDomain) {
  std::string email = "aa@.test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForDomain);
}

// Last dot in email name
TEST(EmailTest, LastDotInEmailName) {
  std::string email = "aa.@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForName);
}

// Last dot in email domain
TEST(EmailTest, LastDotInEmailDomain) {
  std::string email = "aa@test.com.";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForDomain);
}

// Two dots in a row in email name
TEST(EmailTest, TwoDotsInARowInEmailName) {
  std::string email = "aa..aa@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForName);
}

// Two dots in a row in email domain
TEST(EmailTest, TwoDotsInARowInEmailDomain) {
  std::string email = "aa@test..com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForDomain);
}

// Invalid character in email name
TEST(EmailTest, InvalidCharacterInEmailName) {
  std::string email = "aaa\a@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::NameHasInvalidChars);
}

// Invalid character in email domain
TEST(EmailTest, InvalidCharacterInEmailDomain) {
  std::string email = "aaa@test.c!om";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DomainHasInvalidChars);
}

// All valid characters in email name
TEST(EmailTest, AllValidCharactersInEmailName) {
  std::string email = "23456789-!#$%&'*+-/=?^_`{|}~.a@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// All valid characters in email domain
TEST(EmailTest, AllValidCharactersInEmailDomain) {
  std::string email = "NOPQRSTUVWXYZ0123456789-.A@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// one character in email name
TEST(EmailTest, OneCharacterInEmailName) {
  std::string email = "a@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// one character in email domain
TEST(EmailTest, OneCharacterInEmailDomain) {
  std::string email = "test@a";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// digits only in email name
TEST(EmailTest, DigitsOnlyInEmailName) {
  std::string email = "01234567890@test.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// digits only in email domain
TEST(EmailTest, DigitsOnlyInEmailDomain) {
  std::string email = "test@01234567890";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// simple@example.com
TEST(EmailTest, SimpleEmail) {
  std::string email = "simple@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// very.common@example.com
TEST(EmailTest, VeryCommonEmail) {
  std::string email = "very.common@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// disposable.style.email.with+symbol@example.com
TEST(EmailTest, DisposableStyleEmail) {
  std::string email = "disposable.style.email.with+symbol@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// other.email-with-hyphen@example.com
TEST(EmailTest, OtherEmailWithHyphen) {
  std::string email = "other.email-with-hyphen@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// fully-qualified-domain@example.com
TEST(EmailTest, FullyQualifiedDomain) {
  std::string email = "fully-qualified-domain@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// user.name+tag+sorting@example.com
TEST(EmailTest, UserNameTagSorting) {
  std::string email = "user.name+tag+sorting@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// x@example.com
TEST(EmailTest, XEmail) {
  std::string email = "x@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// example-indeed@strange-example.com
TEST(EmailTest, ExampleIndeedStrangeExample) {
  std::string email = "example-indeed@strange-example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// admin@mailserver1
TEST(EmailTest, AdminMailserver1) {
  std::string email = "admin@mailserver1";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// example@s.example
TEST(EmailTest, ExampleSExample) {
  std::string email = "example@s.example";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// mailhost!username@example.org
TEST(EmailTest, MailhostUsername) {
  std::string email = "mailhost!username@example.org";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// user%example.com@example.org
TEST(EmailTest, UserExampleCom) {
  std::string email = "user%example.com@example.org";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::CorrectEmail);
}

// John..Doe@example.com
TEST(EmailTest, JohnDoe) {
  std::string email = "John..Doe@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DotsRequirementsAreNotMetForName);
}

// Abc.example.com
TEST(EmailTest, AbcExampleCom1) {
  std::string email = "Abc.example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidDomainLength);
}

// A@b@c@example.com
TEST(EmailTest, AbcExampleCom2) {
  std::string email = "A@b@c@example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DomainHasInvalidChars);
}

// 1234567890123456789012345678901234567890123456789012345678901234+x@example.com
TEST(EmailTest, LongEmail) {
  std::string email =
      "1234567890123456789012345678901234567890123456789012345678901234+x@"
      "example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::InvalidNameLength);
}

// i_like_underscore@but_its_not_allow_in _this_part.example.com
TEST(EmailTest, UnderscoreNotAllowed) {
  std::string email =
      "i_like_underscore@but_its_not_allow_in _this_part.example.com";
  ErrorCode error = isValidEmail(email);
  ASSERT_EQ(error, ErrorCode::DomainHasInvalidChars);
}
