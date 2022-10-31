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

// 2 people standing on left and right respectively
int a1[1] = {160}; a2[1] = {300}; a3[1] = {480}; a4[1] = {600}
int b1[1] = {120}; b2[1] = {220}, b3[1] = {360}; b4[1] = {440}
int noOfHum = 1;

TEST(coor_calc, should_pass) {
  obj23.coor_calc(a1, b1, noOfHum);
  EXPECT_NEAR(obj23.x, , -114.74, 1);
  EXPECT_NEAR(obj23.y, 522.98, 1);
  EXPECT_NEAR(obj23.z, 87.5, 1);

  obj23.coor_calc(a2, b2);
  EXPECT_NEAR(obj23.x, , -87.46, 1);
  EXPECT_NEAR(obj23.y, 3239.00, 1);
  EXPECT_NEAR(obj23.z, 87.5, 1);

  obj23.coor_calc(a3, b3);
  EXPECT_NEAR(obj23.x, , -114.74, 1);
  EXPECT_NEAR(obj23.y, -522.98, 1);
  EXPECT_NEAR(obj23.z, 87.5, 1);

  obj23.coor_calc(a4, b4);
  EXPECT_NEAR(obj23.x, , -116.68, 1);
  EXPECT_NEAR(obj23.y, -293.86, 1);
  EXPECT_NEAR(obj23.z, 87.5, 1);
}

/*
Test Case:
Another test case will be written for HumanTracker before implementation
Will be done as part of Phase 2
*/
