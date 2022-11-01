[![Build Status](https://app.travis-ci.com/stark-2000/Midterm-Project_Group-8.svg?branch=main)](https://app.travis-ci.com/github/stark-2000/Midterm-Project_Group-8)
[![Coverage Status](https://coveralls.io/repos/github/stark-2000/Midterm-Project_Group-8/badge.svg?branch=main)](https://coveralls.io/github/stark-2000/Midterm-Project_Group-8?branch=main)
---
# Acme's Perception Robotic Module

## Disclaimer
 - License: BSD 
 - License File: LICENSE.txt (in the project directory)
   
## Project Overview and Description:
 - For the midterm project, me and my teammate have decided to choose Acme’s perception robotic module & work on the deliverables and provide a high-quality solution following the essential software engineering practices which they can directly integrate into their product.
 - Computer vision based automatic human detector and tracker ywhich gives location coordinates of multiple humans detected in a realtime video feed from a monocular video camera.
 
## Purpose of the Project
 - The purpose this project is to detect a human from the live feed from the camera and generate the co-ordinates of the location in the robot fixed frame. It shall also track the multiple human obstacles from the image.
 
## Personnel:
 - Dhinesh Rajasekaran 
    - UID: 119400241
 - Arshad Shaik
    - UID: 118438832
 
## Video Presentation:
 - https://youtu.be/AMKvC8GD-Lg - Phase 0
 - https://youtu.be/kq9s1iwcfdw - Phase 1

## Requirements: 
 - Laptop/Raspberry Pi
 - Linux/Ubuntu
 - Webcam/Monocular Video Camera
 - VS Code
 
## AIP Google Sheet
 - https://docs.google.com/spreadsheets/d/1C9AE03gUqFlZGb2_IyPfMfevvJ9ezGKtAxI_n_HEC9M/edit?usp=sharing

## Shareable link to sprint planning notes and review Google Doc
 - https://docs.google.com/document/d/1wD_bKCtLOdt1voyiwZQc1tobgl-Iy5lTP9kQC6JQSEE/edit?usp=sharing
 
## Dependencies
 - openCV library
 - doxygen 
 - lcov
 
## Known issues/bugs
 - Human Tracker functionality yet to be implemented
 - Depth calc inaccuracy and final implementation yet to be done
 - Moving of source code from header file to cpp file
 - Convertion of coordinates from camera to robot frame
 - Develop Test Case for HumanTracker class

## How to build, run & test (from command line)
 - Run the following commands in order
```
git clone --recursive https://github.com/stark-2000/Midterm-Project_Group-8.git
cd Midterm-Project_Group-8
python3 openCV.py
mkdir build
cd build
cmake ..
make
./test/cpp-test
./app/my_app
```
## Command to check Google Style and run static code analysis
- From the app directory run the following command
```
cpplint $( find . -name main.cpp) > cpplintlog
cppcheck --enable=all --std=c++11 --suppress=missingIncludeSystem $( find . -name main.cpp) > cppchecklog
```
## Instructions for code coverage
- From the build directory run the following command
```
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## How to generate Doxygen documentation (from command line)
- From the app directory run the following command
```
doxygen main.cpp
cd html
firefox index.html
```
