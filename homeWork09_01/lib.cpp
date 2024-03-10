#include "lib.hpp"

#include <string>

std::string reverseString(const std::string& str) {
  std::string result = "";
  for (int i = str.size() - 1; i >= 0; i--) {
    result += str[i];
  }
  return result;
}

bool isTimeValid(const std::string& time) {
  // Check that time is in format HH:MM and HH is in 0-23 and MM is in 0-59
  if (time.length() != 5) {
    return false;
  }

  if (time[2] != ':') {
    return false;
  }

  if (time[0] < '0' or time[0] > '2') {
    return false;
  }

  if (time[0] == '1' and (time[1] < '0' or time[1] > '9')) {
    return false;
  }

  if (time[0] == '2' and (time[1] < '0' or time[1] > '3')) {
    return false;
  }

  if (time[3] < '0' or time[3] > '5') {
    return false;
  }

  if (time[4] < '0' or time[4] > '9') {
    return false;
  }

  return true;
}

int convertTimeToMinutes(const std::string& inputTime) {
  int hours = (inputTime[0] - '0') * 10 + (inputTime[1] - '0');
  int minutes = (inputTime[3] - '0') * 10 + (inputTime[4] - '0');
  return hours * 60 + minutes;
}

int getRouteTimeMinutes(int departureMinutes, int arrivalMinutes) {
  if (arrivalMinutes < departureMinutes) {
    arrivalMinutes += 24 * 60;
  }
  int routeTime = arrivalMinutes - departureMinutes;
  return routeTime;
}

MyTime convertMinutesToHoursAndMinutes(int minutes) {
  MyTime result;
  result.hours = minutes / 60;
  result.minutes = minutes % 60;
  return result;
}
