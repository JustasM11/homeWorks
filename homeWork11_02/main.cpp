#include <iostream>

#include "lib.hpp"

int main() {
  std::string email;
  std::cout << "Enter e-mail: " << std::endl;
  std::cin >> email;

  ErrorCode error = isValidEmail(email);

  std::cout << "E-mail is valid: "
            << (error == ErrorCode::CorrectEmail ? "Yes" : "No") << " ("
            << errorMessages.at(error) << ")" << std::endl;

  return 0;
}
