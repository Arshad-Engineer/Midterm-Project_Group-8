/**
 * @copyright (c) 2022 Arshad Shaik
 * @file main.cpp
 * @author Arshad Shaik (arshad22@umd.edu)
 * @brief main program for google test case check
 * @version 1.0
 * @date 2022-10-12
 *
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
