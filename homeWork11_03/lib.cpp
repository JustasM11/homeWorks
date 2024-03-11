#include "lib.hpp"

#include <cmath>
#include <iostream>
#include <string>

IpAddress splitIpAddress(const std::string ipAddress) {
  IpAddress ip;
  int currentPartIndex = 0;
  for (size_t i = 0; i < ipAddress.length(); i++) {
    if (currentPartIndex == 3) {
      ip[currentPartIndex] += ipAddress[i];
      continue;
    }

    if (ipAddress[i] == '.') {
      currentPartIndex++;
      continue;
    }

    ip[currentPartIndex] += ipAddress[i];
  }

  return ip;
}

bool isNumberInRange(const char number, const char start, const char end) {
  return number >= start and number <= end;
}

ErrorCode checkIpAddressPart(const std::string part) {
  if (part.length() <= 0 or part.length() > 3) {
    return ErrorCode::InvalidOctetLength;
  }

  if (part.length() > 1 and part[0] == '0') {
    return ErrorCode::LeadingZero;
  }

  if (part.length() == 1) {
    if (!isNumberInRange(part[0], '0', '9')) {
      return ErrorCode::InvalidCharactersInOctet;
    }
  } else if (part.length() == 2) {
    if (!isNumberInRange(part[0], '0', '9') or
        !isNumberInRange(part[1], '0', '9')) {
      return ErrorCode::InvalidCharactersInOctet;
    }
  } else if (part.length() == 3) {
    if (!isNumberInRange(part[0], '0', '9') or
        !isNumberInRange(part[1], '0', '9') or
        !isNumberInRange(part[2], '0', '9')) {
      return ErrorCode::InvalidCharactersInOctet;
    }

    if (part[0] > '2') {
      return ErrorCode::OctetOutOfRange;
    } else if (part[0] == '2') {
      if (part[1] > '5') {
        return ErrorCode::OctetOutOfRange;
      } else if (part[1] == '5') {
        if (part[2] > '5') {
          return ErrorCode::OctetOutOfRange;
        }
      }
    }
  }

  return ErrorCode::CorrectIPAddress;
}

ErrorCode isIpAddressValid(const std::string& ipAddress) {
  IpAddress ip = splitIpAddress(ipAddress);
  for (size_t i = 0; i <= 3; i++) {
    ErrorCode error = checkIpAddressPart(ip[i]);
    if (error != ErrorCode::CorrectIPAddress) {
      return error;
    }
  }

  return ErrorCode::CorrectIPAddress;
}
