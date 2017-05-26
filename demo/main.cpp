#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
  cv::VideoCapture cap(0);
  if (!cap.isOpened()) {
      std::cout << "Failed to open camera device" << std::endl;
      return -1;
  }

  const int scale = 1;
  const int delta = 0;
  const int ddepth = CV_16S;

  cv::Mat frame;
  for (;;) {
    if (!cap.read(frame))
        break;

    cv::Mat frame_gray, grad;
    cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);

    cv::Mat grad_x, abs_grad_x;
    cv::Sobel(frame_gray, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_x, abs_grad_x);

    cv::Mat grad_y, abs_grad_y;
    cv::Sobel(frame_gray, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(grad_y, abs_grad_y);

    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

    cv::imshow("window", grad);

    char key = cvWaitKey(10);
    if (key == 27)  // ESC
        break;
  }

  return 0;
}
