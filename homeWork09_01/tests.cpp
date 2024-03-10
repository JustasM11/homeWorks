#include <gtest/gtest.h>

#include "lib.hpp"

TEST(RevertString, SomeString) {
  std::string inputString = "asdfgh";
  std::string expectedString = "hgfdsa";
  std::string reversedString = reverseString(inputString);
  ASSERT_EQ(reversedString, expectedString);
}

TEST(RevertString, EmptyString) {
  std::string inputString = "";
  std::string expectedString = "";
  std::string reversedString = reverseString(inputString);
  ASSERT_EQ(reversedString, expectedString);
}

TEST(isTimeValid, CorrectTime) {
  std::string time = "12:00";
  bool result = isTimeValid(time);
  ASSERT_TRUE(result);
}

TEST(isTimeInValid, LongString) {
  std::string time = "12:00:00";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, ShortString) {
  std::string time = "12";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, notNumber) {
  std::string time = "12:1B";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, notNumber2) {
  std::string time = "12:1-";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, bigHours) {
  std::string time = "25:00";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, notNumber3) {
  std::string time = "1a:00";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, notNumber7) {
  std::string time = "1-:00";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, bigMinutes) {
  std::string time = "12:61";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, noColon) {
  std::string time = "12000";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(isTimeInValid, thirtyHours) {
  std::string time = "30:00";
  bool result = isTimeValid(time);
  ASSERT_FALSE(result);
}

TEST(convertTimeToMinutes, CorrectTime) {
  std::string time = "12:00";
  int result = convertTimeToMinutes(time);
  ASSERT_EQ(result, 720);
}

TEST(mainScenario, OneHour1) {
  std::string departureTime = "12:00";
  std::string arrivalTime = "13:00";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 60);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 1);
  ASSERT_EQ(routeTime.minutes, 0);
}

TEST(mainScenario, OneHour2) {
  std::string departureTime = "09:20";
  std::string arrivalTime = "10:20";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 60);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 1);
  ASSERT_EQ(routeTime.minutes, 0);
}

TEST(mainScenario, SecondDay) {
  std::string departureTime = "09:20";
  std::string arrivalTime = "08:40";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 1400);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 23);
  ASSERT_EQ(routeTime.minutes, 20);
}

TEST(mainScenario, ZeroTime) {
  std::string departureTime = "00:00";
  std::string arrivalTime = "00:00";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 0);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 0);
  ASSERT_EQ(routeTime.minutes, 0);
}

TEST(mainScenario, OneMinute) {
  std::string departureTime = "12:34";
  std::string arrivalTime = "12:35";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 1);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 0);
  ASSERT_EQ(routeTime.minutes, 1);
}

TEST(mainScenario, MaxTime) {
  std::string departureTime = "23:59";
  std::string arrivalTime = "23:58";
  int departureMinutes = convertTimeToMinutes(departureTime);
  int arrivalMinutes = convertTimeToMinutes(arrivalTime);
  int routeTimeMinutes = getRouteTimeMinutes(departureMinutes, arrivalMinutes);
  ASSERT_EQ(routeTimeMinutes, 1439);
  MyTime routeTime = convertMinutesToHoursAndMinutes(routeTimeMinutes);
  ASSERT_EQ(routeTime.hours, 23);
  ASSERT_EQ(routeTime.minutes, 59);
}