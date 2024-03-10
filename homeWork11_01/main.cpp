#include <iostream>

#include "lib.hpp"

int main() {
  std::string text;
  std::cout << "Enter text: " << std::endl;
  std::getline(std::cin, text);

  int code;
  std::cout << "Enter code: " << std::endl;
  std::cin >> code;

  std::string caesarText = convertTextToCaesar(text, code);

  std::cout << "Caesar text: " << std::endl << caesarText << std::endl;

  return 0;
}
