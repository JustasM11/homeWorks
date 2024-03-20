#include <iostream>
#include <string>

int main() {
  std::string surnames[10] = {};

  std::cout << "Enter 10 surnames, each on new line: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cin >> surnames[i];
  }

  for (int i = 0; i < 3; i++) {
    std::cout << "Enter flat number: ";

    int flatNumber;
    std::cin >> flatNumber;

    if (flatNumber < 1 or flatNumber > 10) {
      std::cout << "Invalid flat number, expected value > 0 and < 11"
                << std::endl;
      continue;
    }

    std::cout << "Surname: " << surnames[flatNumber - 1] << std::endl;
  }

  return 0;
}
