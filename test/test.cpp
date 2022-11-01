/**
 * @copyright (c) 2022 Arshad Shaik
 * @file test.cpp
 * @author Arshad Shaik (arshad22@umd.edu)
 * @brief Test cases to check the functionality of Human Tracker
 * & Detector program
 * @version 2.0
 * @date 2022-10-29
 *
 */
#include <gtest/gtest.h>

#include "../include/openCV.hpp"

humanLocCalc obj23;

// Test Case 1:
// Image Frame with 4 humans in main area of frame
double a1[4] = {160, 300, 480, 600};  // Human horizontal pixel values
double b1[4] = {120, 220, 360, 440};  // Human vertical pixel values

int noOfHum1 = 4;  // No of Humans in image frame

TEST(coor_calc, 4_humans_main) {
  obj23.coorCalc(a1, b1, noOfHum1);
  EXPECT_NEAR(obj23.x[0], -114.74, 0.01);
  EXPECT_NEAR(obj23.y[0], 522.98, 0.01);
  EXPECT_NEAR(obj23.z[0], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[1], -87.46, 0.01);
  EXPECT_NEAR(obj23.y[1], 3239.00, 0.01);
  EXPECT_NEAR(obj23.z[1], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[2], -114.74, 0.01);
  EXPECT_NEAR(obj23.y[2], -522.98, 0.01);
  EXPECT_NEAR(obj23.z[2], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[3], -116.68, 0.01);
  EXPECT_NEAR(obj23.y[3], -293.86, 0.01);
  EXPECT_NEAR(obj23.z[3], 87.5, 0.1);
}

// Test Case 2:
// Image Frame with human at origin
double a2[1] = {0};  // Human horizontal pixel values
double b2[1] = {0};  // Human vertical pixel values

int noOfHum2 = 1;  // No of Humans in image frame

TEST(coor_calc, human_at_origin) {
  obj23.coorCalc(a2, b2, noOfHum2);
  EXPECT_NEAR(obj23.x[0], -109.08, 0.01);
  EXPECT_NEAR(obj23.y[0], 236.63, 0.01);
  EXPECT_NEAR(obj23.z[0], 87.5, 0.1);
}

// Test Case 3:
// Image Frame with 4 humans scattered or at corners
double a3[4] = {640, 640, 0, 90};  // Human horizontal pixel values
double b3[4] = {480, 0, 480, 70};  // Human vertical pixel values

int noOfHum3 = 4;  // No of Humans in image frame

TEST(coor_calc, 4_humans_scattered) {
  obj23.coorCalc(a3, b3, noOfHum3);
  EXPECT_NEAR(obj23.x[0], -109.08, 0.01);
  EXPECT_NEAR(obj23.y[0], -236.63, 0.01);
  EXPECT_NEAR(obj23.z[0], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[1], 109.08, 0.01);
  EXPECT_NEAR(obj23.y[1], 236.63, 0.01);
  EXPECT_NEAR(obj23.z[1], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[2], 109.08, 0.01);
  EXPECT_NEAR(obj23.y[2], -236.63, 0.01);
  EXPECT_NEAR(obj23.z[2], 87.5, 0.1);

  EXPECT_NEAR(obj23.x[3], -114.43, 0.01);
  EXPECT_NEAR(obj23.y[3], 356.66, 0.01);
  EXPECT_NEAR(obj23.z[3], 87.5, 0.1);
}

// Test Case 4:
// Image Frame with human head in line with camera lens's
double a4[1] = {240};  // Human horizontal pixel values
double b4[1] = {240};  // Human vertical pixel values

int noOfHum4 = 1;  // No of Humans in image frame

TEST(coor_calc, human_head_inline_with_camera_lens) {
  obj23.coorCalc(a4, b4, noOfHum4);
  EXPECT_NEAR(obj23.x[0], -107.79, 0.01);
  EXPECT_NEAR(obj23.y[0], 994.30, 0.01);
  EXPECT_NEAR(obj23.z[0], 87.5, 0.1);
}
