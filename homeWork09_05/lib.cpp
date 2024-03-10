#include "lib.hpp"

#include <iostream>
#include <string>

bool isCorrectNumber(const std::string& number) {
  if (number.length() < 1 || number.length() > 4) {
    return false;
  }

  bool notZero = false;
  for (size_t i = 0; i < number.length(); i++) {
    if ('0' > number[i] || number[i] > '9') {
      return false;
    }
    if (number[i] != '0') {
      notZero = true;
    }
  }

  if (!notZero) {
    return false;
  }

  // max number if 3999
  if (number[0] > '3') {
    return false;
  }

  return true;
}

std::string convertDecToRome(std::string& decNumber) {
  assertm(decNumber.length() < 5, "Provided decNumber has length > 4");

  while (decNumber.length() < 4) {
    decNumber = "0" + decNumber;
  }

  std::string romeNumber = "";
  std::string zero = "";
  std::string one = "";
  std::string two = "";
  std::string three = "";
  std::string four = "";
  std::string five = "";
  std::string six = "";
  std::string seven = "";
  std::string eigth = "";
  std::string nine = "";

  for (size_t i = 0; i < decNumber.length(); i++) {
    if (i == 0) {
      zero = "";
      one = "M";
      two = "MM";
      three = "MMM";
      four = "MR";
      five = "R";
      six = "RM";
      seven = "RMM";
      eigth = "RMMM";
      nine = "MQ";
    } else if (i == 1) {
      zero = "";
      one = "C";
      two = "CC";
      three = "CCC";
      four = "CD";
      five = "D";
      six = "DC";
      seven = "DCC";
      eigth = "DCCC";
      nine = "CM";
    } else if (i == 2) {
      zero = "";
      one = "X";
      two = "XX";
      three = "XXX";
      four = "XL";
      five = "L";
      six = "LX";
      seven = "LXX";
      eigth = "LXXX";
      nine = "XC";
    } else if (i == 3)  // Keep if just for similarity
    {
      zero = "";
      one = "I";
      two = "II";
      three = "III";
      four = "IV";
      five = "V";
      six = "VI";
      seven = "VII";
      eigth = "VIII";
      nine = "IX";
    }

    if (decNumber[i] == '0') {
      romeNumber += zero;
    } else if (decNumber[i] == '1') {
      romeNumber += one;
    } else if (decNumber[i] == '2') {
      romeNumber += two;
    } else if (decNumber[i] == '3') {
      romeNumber += three;
    } else if (decNumber[i] == '4') {
      romeNumber += four;
    } else if (decNumber[i] == '5') {
      romeNumber += five;
    } else if (decNumber[i] == '6') {
      romeNumber += six;
    } else if (decNumber[i] == '7') {
      romeNumber += seven;
    } else if (decNumber[i] == '8') {
      romeNumber += eigth;
    } else if (decNumber[i] == '9') {
      romeNumber += nine;
    }
  }
  return romeNumber;
}