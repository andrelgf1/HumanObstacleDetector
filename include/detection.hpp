#ifndef INCLUDE_DETECTION_HPP_
#define INCLUDE_DETECTION_HPP_

#include <opencv2/opencv.hpp>

#include <vector>


class Detection {
 public:

  Detection();

  std::vector<cv::Rect> detect(const cv::Mat& image);
 private:
  cv::HOGDescriptor hog;
};

#endif /* INCLUDE_DETECTION_HPP_ */
