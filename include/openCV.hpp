/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file openCV.hpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This is header file consisting of function declarations
 * @version 4.0
 * @date 2022-10-29
 *
 */
#pragma once

#include <opencv2/opencv.hpp>

using cv::Mat;
using cv::VideoCapture;

/**
 * @brief Class 1: This class gets video data from laptop webcam & write
 * changes to real-time video
 *
 */
class videoFrameData {
 public:
  /**
   * @brief Get video data from laptop webcam
   * @return Video data
   */
  VideoCapture getFrame();

  /**
   * @brief Write data to real-time video
   * @param img Image frame/data to be written
   * @return zero
   */
  double outFrame(Mat img);
};

/**
 * @brief Class 2: This class Detects, tracks & assigns unique ID to
 * humans using HoG detector
 *
 */
class humanDetectorTracker {
 public:
  double a[100];  ///<  Array of horizontal pixel values
  double b[100];  ///<  Array of vertical pixel values
  int n;          ///<  No. of humans in frame

  /**
   * @brief Detect, track & assign ID to humans
   * @param img Image frame/data to be analysed
   * @return zero
   */
  double detector_tracker(Mat img);
};

/**
 * @brief Class 3: This class calculates human location w.r.t to Robot frame
 *
 */
class humanLocCalc {
 public:
  double z[100];  ///<  Cartesian coordinates of Human in robot frame - Z-Axis
  double x[100];  ///<  Cartesian coordinates of Human in robot frame - X-Axis
  double y[100];  ///<  Cartesian coordinates of Human in robot frame - Y-Axis

  /**
   * @brief Calc cartesian coordinates w.r.t to robot frame
   * @param a Array of horizontal pixel value of detected Humans
   * @param b Array of vertical pixel value of detected Humans
   * @param n No. of humans in frame
   * @return zero
   */
  double coorCalc(double a[], double b[], int n);
};
