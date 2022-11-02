/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file openCV.cpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This program contains the class member function declarations
 * @version 4.0
 * @date 2022-10-29
 *
 */
#include "../include/openCV.hpp"

#include <math.h>

#include <iostream>
#include <opencv2/opencv.hpp>

using std::cout;
using std::endl;
using std::fill_n;
using std::string;
using std::to_string;
using std::vector;

using cv::CAP_PROP_FRAME_HEIGHT;
using cv::CAP_PROP_FRAME_WIDTH;
using cv::FONT_HERSHEY_SIMPLEX;
using cv::HOGDescriptor;
using cv::Mat;
using cv::Point;
using cv::Rect;
using cv::Scalar;
using cv::Size;
using cv::WINDOW_AUTOSIZE;

// Global Variables:
// Video/Image Data:
double frame_h = 640;           ///< Video Frame Horizontal Resolution
double frame_v = 480;           ///< Video Frame Vertical Resolution
double mid_px_h = frame_h / 2;  ///< center horizontal pixel value of frame
double mid_px_v = frame_v / 2;  ///< center vertical pixel value of frame
int i;                          ///< general 'for' loop variables
int j;                          ///< general 'for' loop variables

// Human Detector & Tracker Variables:
double a_prev[100] = {0};  ///< holds prev horizontal pixel value
double b_prev[100] = {0};  ///< holds prev vertical pixel value
int pos;                   ///< holds position of repeated human from prev frame
int ID[100];               ///< array for storing unique IDs assigned to humans
int ID_Counter = 1;        ///< keeps track of unique IDs assigned
int flag;                  ///< general flag value
int count1;                ///< stores vector size
int count2;                ///< stores vector size

// Location calc variables:
double r;   ///< Spherical coordinates of human - Radial distance
double r1;  ///< Radial distance projection on XY plane
double p;   ///< Spherical coordinates of human - Polar Angle
double az;  ///< Spherical coordinates of human - Azimuthal Angle
double FoV_h =
    49.5;  ///< horizontal FoV in Degrees (measured for laptop webcam)
double FoV_v =
    37.125;  ///< vertical FoV in degrees (measured for laptop webcam)
const double res_h = FoV_h / frame_h;  ///< horizontal resolution (° per pixel)
const double res_v = FoV_v / frame_v;  ///< vertical resolution (° per pixel)
const double h = 176;                  ///< Average Human Height (in cm)

// Alter the below value depending on application
const double H =
    88.5;  ///< Floor - table height: 64.5cm + laptop - web camera height: 24cm


/**
 * @brief Get video data from laptop webcam
 * @return Video data
 */
VideoCapture videoFrameData::getFrame() {
#if !defined (DONT_COVER1)
  VideoCapture video(
      0);  ///< Set video source to 0 for default webcam in laptop
  namedWindow("video capture", WINDOW_AUTOSIZE);  ///< Set laptop window size
#endif
  video.set(CAP_PROP_FRAME_WIDTH,
            frame_h);  ///< Set video frame horizontal resolution
  video.set(CAP_PROP_FRAME_HEIGHT,
            frame_v);  ///< Set video frame vertical resolution

  // Check video source availability
  if (!video.isOpened()) {
    cout << "Video Source not avalable !" << endl;
  }
  return video;
}

/**
 * @brief Detect, track & assign ID to humans
 * @param img Image frame/data to be analysed
 * @return zero
 */
double humanDetectorTracker::detector_tracker(Mat img) {
  string dtext,
      text;  ///< holds dynamic string data to be displayed as Unique ID
  string ftext = "Human ";  ///< holds static string data to be displayed
  // Histogram of Gradients Method for Human Detection
  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

  vector<Rect> found, found_filtered;  ///< vector to store initial detected
                                       ///< human data & filtered data

  hog.detectMultiScale(img, found, 0, Size(8, 8), Size(32, 32), 1.05,
                       2);  ///< Detecting multiple humans using HoG & storing
                            ///< data in found vector

  count1 = found.size();

  // Filtering detected humans & storing no of humans in fould_filtered vector
  for (i = 0; i < count1; i++) {
    Rect re = found[i];
    for (j = 0; j < count1; j++)
      if (j != i && (re & found[j]) == re) break;
    if (j == count1) found_filtered.push_back(re);
  }

  count2 = found_filtered.size();
  // Calc the pixel values of each detected human's head
  for (i = 0; i < count2; i++) {
    Rect re = found_filtered[i];
    a[i] = (re.tl().x + (re.width / 2));
    b[i] = re.tl().y;
  }

  // Comparing the pixel values of each detected human btw current & previous
  // frame
  for (i = 0; i < count2; i++) {  // i is for each human in current frame
    Rect re = found_filtered[i];
    re.x += cvRound(re.width * 0.1);
    re.width = cvRound(re.width * 0.8);
    re.y += cvRound(re.height * 0.06);
    re.height = cvRound(re.height * 0.9);

    for (j = 0; j < count2; j++) {  // j is for each human in previous frame
      if ((abs(a_prev[j] - a[i]) < 150) && (abs(b_prev[j] - b[i]) < 100)) {
        flag = 1;
        pos = j;
        break;
      } else {
        flag = 2;
      }
    }

    if (flag == 1) {  // Human matched - assign prev-frame ID
      rectangle(img, re.tl(), re.br(), Scalar(0, 255, 0), 2);  // Draw bounding
                                                               // box
      dtext = to_string(ID[pos]);
      text = ftext + dtext;
      putText(img, text, Point(re.tl().x, re.tl().y - 10), FONT_HERSHEY_SIMPLEX,
              0.5, Scalar(0, 255, 0), 2);  // Print unique ID
    }

    if (flag == 2) {  // Human not matched - assign new ID
      rectangle(img, re.tl(), re.br(), Scalar(0, 255, 0), 2);  // Draw bounding
                                                               // box
      dtext = to_string(ID_Counter);
      text = ftext + dtext;
      putText(img, text, Point(re.tl().x, re.tl().y - 10), FONT_HERSHEY_SIMPLEX,
              0.5, Scalar(0, 255, 0), 2);  // Print unique ID
      ID[i] = ID_Counter;
      ID_Counter++;
    }
  }

  for (i = 0; i < count2; i++) {
    a_prev[i] = a[i];
    b_prev[i] = b[i];
  }

  // If no humans in frame - reset all
  if (count2 == 0) {
    ID_Counter = 1;
    fill_n(a_prev, 100, 0);
    fill_n(b_prev, 100, 0);
  }

  cout << "No. of Humans: " << found_filtered.size()
       << endl;  // Displaying no of humans detected
  n = count2;
  return 0;   
}

/**
 * @brief Calc cartesian coordinates w.r.t to robot frame
 * @param a Array of horizontal pixel value of detected Humans
 * @param b Array of vertical pixel value of detected Humans
 * @param n No. of humans in frame
 * @return zero
 */
double humanLocCalc::coorCalc(double a[], double b[], int n) {
  // Calc human location w.r.t to robot (laptop) frame
  for (i = 0; i < n; i++) {
    cout << "Human " << i + 1 << ": " << endl;
    cout << "Pixel Values: ";
    cout << a[i] << "," << b[i] << endl;  // Print human'head pixel values

    // Calc spherical coordinates of human w.r.t robot frame
    if (b[i] <= mid_px_v) {
      p = (90 - ((mid_px_v - b[i]) * res_v));
    } else {
      p = (90 + ((b[i] - mid_px_v) * res_v));
    }

    cout << "Polar Angle (p): " << p << endl;

    if (a[i] > mid_px_h) {
      az = (90 - ((a[i] - mid_px_h) * res_h));
    } else {
      az = (90 + ((mid_px_h - a[i]) * res_h));
    }

    cout << "Azimuthal Angle (az): " << az << endl;

    // Check if polar angle is 90° (special case)
    if (p == 90) {
      p = 85 * (M_PI / 180);  // Make polar angle 85° & convert to radians
    } else {
      p = p * (M_PI / 180);
    }  // convert polar angle to radians

    az = az * (M_PI / 180);  // convert azimuthal angle to radians

    // Calc cartesian coordinates of human w.r.t robot frame:
    z[i] =
        h - H;  // z coordinate of human location in 3D space w.r.t robot frame
    r = z[i] / cos(p);  // radial distance 'r' of human in spherical coordinate
    cout << "r: " << r << endl;
    r1 = r * sin(p);
    x[i] = r1 * cos(az);  // x coordinate of human location in 3D space w.r.t
                          // robot frame
    y[i] = r1 * sin(az);  // y coordinate of human location in 3D space w.r.t
                          // robot frame

    cout << "x:" << x[i] << "cm , "
         << "y:" << y[i] << "cm , "
         << "z:" << z[i] << "cm" << endl;
    cout << endl;
  }
  cout << endl;
  return 0;
}

/**
 * @brief Write data to real-time video
 * @param img Image frame/data to be written
 * @return zero
 */
double videoFrameData::outFrame(Mat img) {
  #if !defined (DONT_COVER2)  
  imshow("Output Frame", img);  ///<  Overlay info on real-time video
  #endif
  return 0;
}
