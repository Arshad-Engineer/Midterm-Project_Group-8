/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file main.cpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief This is the main program which takes input from python openCV
 * generated txt file and outpus human loc & unique ID
 * @version 1.0
 * @date 2022-10-12
 *
 */

#include <fstream>
#include <iostream>

#include "../include/detector.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

ifstream file;

/**
 * @brief This class gets pixel data of human from the txt file created by
 * openCV appplication in python and returns the data.
 *
 */
class FetchImageData {
 public:
  string line;
  string a, b;

  /**
   * @brief A normal member function to fetch data from txt file & split received data
   * @return null character
   *
   */
  string get_data() {
    file.open("/home/dhinesh/Downloads/pixel_coord.txt");
    if (!file) {
      cout << "Unable to find pixel_coord.txt";
      exit(1);
    }

    while (getline(file, line, ';')) {
      if (line.compare(";")) {
        break;
      }
    }

    // cout << line << endl; //for debug
    int pos = line.find(",");
    a = line.substr(0, pos);
    b = line.substr(pos + 1);

    file.close();
    return "\n";
  }
};

/**
 * @brief Main function which displays detected human cartesian coordinate
 * & displays computed spherical coordinate of human in camera frame
 * @return zero
 */
int main() {
  string a, b;
  FetchImageData obj;
  obj.get_data();

  HumanLocCalc L1;
  L1.coor_calc(stod(obj.a), stod(obj.b));

  // cout << "a = " << obj.a << endl; //for debug
  // cout << "b = " << obj.b << endl; //for debug

  cout << "Detected Human Location in Camera Frame (cartesian): (" << obj.a
       << "," << obj.b << "," << L1.depth << ")" << endl;
  cout << "Detected Human Location in Camera Frame (spherical): (" << L1.r
       << "," << L1.theta << "," << L1.phi << ")" << endl;
  return 0;
}
