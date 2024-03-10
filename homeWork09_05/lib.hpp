#pragma once
#include <cassert>
#include <string>
#define assertm(exp, msg) assert(((void)msg, exp))

bool isCorrectNumber(const std::string& number);
std::string convertDecToRome(std::string& decNumber);
