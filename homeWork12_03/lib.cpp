#include "lib.hpp"

#include <cassert>
#include <iostream>

float travelTime(float distance, float speed) {
  assert(speed > 0);
  return distance / speed;
}