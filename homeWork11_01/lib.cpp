#include "lib.hpp"

#include <cmath>
#include <iostream>
#include <string>

char convertCharToCaesar(char c, int code, char startChar) {
  return startChar + (c - startChar + code) % 26;
}

std::string convertTextToCaesar(const std::string& text, int code) {
  if (code < 0) {
    code = 26 - std::abs(code);
  }

  std::string caesarText = "";
  for (size_t i = 0; i < text.length(); ++i) {
    if (text[i] >= 'a' and text[i] <= 'z') {
      caesarText += convertCharToCaesar(text[i], code, 'a');
    } else if (text[i] >= 'A' and text[i] <= 'Z') {
      caesarText += convertCharToCaesar(text[i], code, 'A');
    } else {
      caesarText += text[i];
    }
  }
  return caesarText;
}