#include <iostream>
#include <opencv2/opencv.hpp>

using std::cout;
using std::endl;
using std::vector;

using namespace cv;
using cv::Scalar;
using cv::VideoCapture;
using cv::CAP_PROP_FRAME_HEIGHT;
using cv::CAP_PROP_FRAME_WIDTH;
using cv::Mat;

 
int main (int argc, const char * argv[])
{
  double a[100], b[100];
  // Set video source, 0 for default web cam
  VideoCapture video(0);

  // Set video frame size - set to 720p size
  video.set(CAP_PROP_FRAME_WIDTH, 640);
  video.set(CAP_PROP_FRAME_HEIGHT, 480);

  //Check video source availability
  if (!video.isOpened())
  {
    cout << "Video Source not avalable !" << endl;
  }
    
  Mat img;
  HOGDescriptor hog;
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

  namedWindow("video capture", WINDOW_AUTOSIZE);
  while (true) {
    video >> img;
    if (!img.data)
      continue;

    vector<Rect> found, found_filtered;
    hog.detectMultiScale(img, found, 0, Size(8, 8), Size(32, 32), 1.05, 2);

    size_t i, j;
    for (i = 0; i < found.size(); i++) {
      Rect r = found[i];
      for (j = 0; j < found.size(); j++)
        if (j != i && (r & found[j]) == r)
          break;
      if (j == found.size())
        found_filtered.push_back(r);
    }
    for (i = 0; i < found_filtered.size(); i++) {
      Rect r = found_filtered[i];
      r.x += cvRound(r.width * 0.1);
      r.width = cvRound(r.width * 0.8);
      r.y += cvRound(r.height * 0.06);
      r.height = cvRound(r.height * 0.9);
      rectangle(img, r.tl(), r.br(), Scalar(0, 255, 0), 2);
      a[i] = (r.tl().x + r.br().x)/2;
      b[i] = (r.tl().y + r.br().y)/2;
    }

    cout << "Human 1: " << a[0] << "," << b[0] << endl;
    cout << "Human 2: " << a[1] << "," << b[1] << endl;

    a[0] = 0;
    a[1] = 0;
    b[0] = 0;
    b[1] = 0;

    imshow("video capture", img);
    if (waitKey(20) >= 0)
      break;
    }
    return 0;
}
