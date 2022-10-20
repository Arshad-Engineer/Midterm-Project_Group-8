/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file detector.hpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This is header file consisting of human loc calc class
 * @version 1.0
 * @date 2022-10-12
 *
 */

#pragma once
#include <math.h>

#include <iostream>

/**
 * @brief This class calculates the spherical coordinate location
 * of human in the image frame from the cartesian coordinates.
 *
 */
class HumanLocCalc {
 public:
  double depth = 5;  // Unit: Meters
  // Depth calc will be implented in Phase 2

  double r, theta, phi;  // Unit: Radians

  /**
   * @brief Converts the cartesian coordinates to spherical
   * coordinates
   * @param x x-axis coordinate of human loc
   * @param y y-axis coordinate of human loc
   * @return r, theta and phi of human loc are returned
   */
  double coor_calc(double x, double y) {
    // Loc w.r.t Camera Frame:
    r = pow((pow(x, 2) + pow(y, 2) + pow(depth, 2)), 0.5);
    theta = atan(y / x);
    phi = atan(pow((pow(x, 2) + pow(y, 2)), 0.5) / depth);

    // Loc w.r.t Robot Frame:
    // To be implemented in Phase 2

    return 0;
  }
};

/**
 * @brief This class assigns a unique ID to the human detected
 * and handles multi-human detection and assigns respective unique IDs
 *
 */
class HuamnTracker {
  // Will assign unique ID & send to python code for OSD (on-screen display)
  // Will be implemented  in phase 2
};
