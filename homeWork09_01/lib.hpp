#pragma once
#include <string>

struct MyTime {
  int hours;
  int minutes;
};

std::string reverseString(const std::string& str);
bool isTimeValid(const std::string& time);
int convertTimeToMinutes(const std::string& inputTime);
int getRouteTimeMinutes(int departureMinutes, int arrivalMinutes);
MyTime convertMinutesToHoursAndMinutes(int minutes);
