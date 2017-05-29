# OpenCV test project 
* Build system: cmake
* Dependencies: OpenCV
* Tests: gtest
* Code style check: cpplint
* Continuous integration: travis-ci

## Dependencies
1. OpenCV ([link](http://docs.opencv.org/3.2.0/d7/d9f/tutorial_linux_install.html))

## Build steps
```
mkdir opencv_test
cd ~/opencv_test
git clone https://github.com/inalgo/ar.git
mkdir build
cd build
cmake -D OpenCV_DIR=~/opencv-3.2.0_build/ ../ar/
```