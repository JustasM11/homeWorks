#include <iostream>

#include "lib.hpp"

int main() {
  float distance;
  float speed;
  std::cout << "Enter speed and time separated by space, e.g. 100 10:"
            << std::endl;
  std::cin >> distance >> speed;
  float time = travelTime(distance, speed);

  std::cout << "Travel time: " << time << std::endl;

  return 0;
}
