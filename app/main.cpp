/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file main.cpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This is the main program which calls various classes and runs a loop
 * @version 4.0
 * @date 2022-10-29
 *
 */
#include <iostream>

#include "../include/openCV.hpp"

using cv::waitKey;

// Global Variables:
VideoCapture Video;  ///< stores video frame received from openCV.cpp
Mat img;             ///< img stores instantaneous frame captured from video

/**
 * @brief Main function which calls various classes and runs a loop until
 * any key is pressed
 * @return zero
 */
int main() {
  videoFrameData obj1;
  Video = obj1.getFrame();  // get video data from class 1

  while (true) {
    Video >> img;  ///< Passing the received data to static frame

    humanDetectorTracker obj2;
    // Passing image frame to class 2 for detection & tracking of humans
    obj2.detector_tracker(img);

    humanLocCalc obj3;
    obj3.coorCalc(obj2.a, obj2.b,
                  obj2.n);  // Calc human location in robot frame using class 3
    obj1.outFrame(img);     // Write changes to real-time video using class 1

    if (waitKey(20) >=
        0)  // if any key is pressed - exit from detection/tracking
      break;
  }
  return 0;
}
