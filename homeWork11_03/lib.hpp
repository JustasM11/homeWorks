#pragma once
#include <cassert>
#include <map>
#include <string>

enum class ErrorCode {
  CorrectIPAddress,
  InvalidOctetLength,
  LeadingZero,
  InvalidCharactersInOctet,
  OctetOutOfRange,
};

const std::map<ErrorCode, std::string> errorMessages = {
    {ErrorCode::CorrectIPAddress, "IP address is valid"},
    {ErrorCode::InvalidOctetLength,
     "IP address has octet with length < 1 or > 3"},
    {ErrorCode::LeadingZero, "IP address has octet with leading zero"},
    {ErrorCode::InvalidCharactersInOctet,
     "IP address has octet with invalid characters, not from the list: 0-9"},
    {ErrorCode::OctetOutOfRange, "IP address has octet with value > 255"},
};

// Define array of 4 strings is IpAddress as new type:
using IpAddress = std::array<std::string, 4>;

ErrorCode isIpAddressValid(const std::string& ipAddress);
