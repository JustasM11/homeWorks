#include <iostream>

#include "lib.hpp"

int main() {
  std::string ipAdress;
  std::cout << "Enter IP: " << std::endl;
  std::cin >> ipAdress;

  ErrorCode error = isIpAddressValid(ipAdress);

  std::cout << "IP is valid: "
            << (error == ErrorCode::CorrectIPAddress ? "Yes" : "No") << " ("
            << errorMessages.at(error) << ")" << std::endl;

  return 0;
}
