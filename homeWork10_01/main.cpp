#include <cmath>
#include <iostream>

int main() {
  float a, b, c;
  std::cout << "Please enter a, b, c:";
  std::cin >> a >> b >> c;

  float discriminant = b * b - 4 * a * c;  // b^2 - 4ac
  if (discriminant > 1) {
    float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
    float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
    std::cout << "Root 1, 2: " << x1 << ", " << x2 << std::endl;
  } else if (discriminant == 0) {
    float x = -b / (2 * a);
    std::cout << "Root: " << x << std::endl;
  } else {
    std::cerr << "Complex scenario is not supported!" << std::endl;
    return 1;
  }
  return 0;
}