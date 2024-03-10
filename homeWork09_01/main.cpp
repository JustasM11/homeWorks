#include <iostream>

#include "lib.hpp"

int main() {
  std::string departureTime, arrivalTime;
  std::cout << "Enter departure time and arrival time, e.g. 12:00 13:00"
            << std::endl;
  std::cin >> departureTime >> arrivalTime;

  if (!isTimeValid(departureTime)) {
    std::cerr << "Departure time is invalid: " << departureTime << "\n";
    return 1;
  }

  if (!isTimeValid(arrivalTime)) {
    std::cerr << "Arrival time is invalid: " << arrivalTime << "\n";
    return 1;
  }

  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);

  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);

  std::cout << "Route time is " << routeTime.hours << " hours and "
            << routeTime.minutes << " minutes" << std::endl;
}
