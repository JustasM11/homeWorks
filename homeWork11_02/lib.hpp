#pragma once
#include <cassert>
#include <map>
#include <string>

enum class ErrorCode {
  CorrectEmail,
  InvalidNameLength,
  NameHasInvalidChars,
  DotsRequirementsAreNotMetForName,
  InvalidDomainLength,
  DomainHasInvalidChars,
  DotsRequirementsAreNotMetForDomain
};

const std::map<ErrorCode, std::string> errorMessages = {
    {ErrorCode::CorrectEmail, "e-mail is valid"},
    {ErrorCode::InvalidNameLength, "e-mail name length is < 1 or > 64"},
    {ErrorCode::NameHasInvalidChars,
     "e-mail name has invalid characters, not from the list: a-z, A-Z, 0-9, "
     "-!#$%&'*+-/=?^_`{|}~."},
    {ErrorCode::DotsRequirementsAreNotMetForName,
     "e-mail name has first or last dot, or two dots in a row"},
    {ErrorCode::InvalidDomainLength, "e-mail domain length is < 1 or > 63"},
    {ErrorCode::DomainHasInvalidChars,
     "e-mail domain has invalid characters, not from the list: a-z, A-Z, 0-9, "
     "-."},
    {ErrorCode::DotsRequirementsAreNotMetForDomain,
     "e-mail domain has first or last dot, or two dots in a row"}};

struct Email {
  std::string name = "";
  std::string domain = "";
};

ErrorCode isValidEmail(const std::string& email);
