#include "lib.hpp"

#include <cmath>
#include <iostream>
#include <string>

Email splitEmail(std::string email) {
  Email emailParts = {};
  emailParts.name = email;

  for (size_t i = 0; i < email.length(); i++) {
    if (email[i] == '@') {
      emailParts.name = email.substr(0, i);
      emailParts.domain = email.substr(i + 1);
      return emailParts;
    }
  }
  return emailParts;
}

bool isStringMatchDictionary(std::string str, std::string dictionary) {
  for (size_t i = 0; i < str.length(); i++) {
    for (size_t j = 0; j < dictionary.length(); j++) {
      if (str[i] == dictionary[j]) {
        break;
      }
      if (j == dictionary.length() - 1) {
        return false;
      }
    }
  }
  return true;
}

bool AreDotsRequirementsMet(std::string str) {
  if (str[0] == '.' or str[str.length() - 1] == '.') {
    return false;
  }

  if (str.length() >= 2) {
    for (size_t i = 0; i < str.length(); i++) {
      if (str[i] == '.' and str[i + 1] == '.') {
        return false;
      }
    }
  }

  return true;
}

ErrorCode isValidEmailName(const std::string& name) {
  if (name.length() < 1 or name.length() > 64) {
    return ErrorCode::InvalidNameLength;
  }

  std::string validChars =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-!#$%&'*+-"
      "/=?^_`{|}~.";
  if (!isStringMatchDictionary(name, validChars)) {
    return ErrorCode::NameHasInvalidChars;
  }

  if (!AreDotsRequirementsMet(name)) {
    return ErrorCode::DotsRequirementsAreNotMetForName;
  }

  return ErrorCode::CorrectEmail;
}

ErrorCode isValidEmailDomain(const std::string& domain) {
  if (domain.length() < 1 or domain.length() > 63) {
    return ErrorCode::InvalidDomainLength;
  }

  std::string validChars =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";
  if (!isStringMatchDictionary(domain, validChars)) {
    return ErrorCode::DomainHasInvalidChars;
  }

  if (!AreDotsRequirementsMet(domain)) {
    return ErrorCode::DotsRequirementsAreNotMetForDomain;
  }

  return ErrorCode::CorrectEmail;
}

ErrorCode isValidEmail(const std::string& email) {
  Email emailParts = splitEmail(email);

  ErrorCode error = isValidEmailName(emailParts.name);
  if (error != ErrorCode::CorrectEmail) {
    return error;
  }

  error = isValidEmailDomain(emailParts.domain);
  return error;
}
