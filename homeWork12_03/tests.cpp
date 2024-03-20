#include <gtest/gtest.h>

#include "lib.hpp"

TEST(travelTime, test1) { ASSERT_FLOAT_EQ(travelTime(100, 100), 1); }

TEST(travelTime, test2) { ASSERT_FLOAT_EQ(travelTime(100, 50), 2); }

TEST(travelTime, test4) { ASSERT_FLOAT_EQ(travelTime(0, 100), 0); }

// Check assertion when speed = 0
TEST(travelTime, test5) { ASSERT_DEATH(travelTime(100, 0), ".*"); }

// Check assertion when speed < 0
TEST(travelTime, test6) { ASSERT_DEATH(travelTime(100, -1), ".*"); }
