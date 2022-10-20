/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file main.cpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief Google Test execution file
 * @version 1.0
 * @date 2022-10-12
 *
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
