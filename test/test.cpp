/**
 * @copyright (c) 2022 Arshad Shaik
 * @file test.cpp
 * @author Arshad Shaik (arshad22@umd.edu)
 * @brief Test cases to check the functionality of Human Tracker
 * & Detector program
 * @version 1.0
 * @date 2022-10-12
 *
 */

#include <gtest/gtest.h>

#include "../include/detector.hpp"

HumanLocCalc obj23;

TEST(coor_calc, should_pass) {
  obj23.coor_calc(270, 45);
  EXPECT_NEAR(obj23.r, 273, 0.9);
  EXPECT_NEAR(obj23.theta, 0.165, 0.009);
  EXPECT_NEAR(obj23.phi, 1.552, 0.009);

  obj23.coor_calc(0, 0);
  EXPECT_NEAR(obj23.r, 5, 0.9);
  double temp = obj23.theta;
  EXPECT_NEAR(isnan(temp), 1, 0);
  EXPECT_NEAR(obj23.phi, 0, 0.009);

  obj23.coor_calc(-63, 47);
  EXPECT_NEAR(obj23.r, 78, 0.9);
  EXPECT_NEAR(obj23.theta, -0.640, 0.009);
  EXPECT_NEAR(obj23.phi, 1.507, 0.009);

  obj23.coor_calc(23, -74);
  EXPECT_NEAR(obj23.r, 77, 0.9);
  EXPECT_NEAR(obj23.theta, -1.269, 0.009);
  EXPECT_NEAR(obj23.phi, 1.506, 0.009);
}

/*
Test Case:
Another test case will be written for HumanTracker before implementation
Will be done as part of Phase 2
*/
