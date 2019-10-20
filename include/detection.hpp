/**
 * @file detection.hpp
 * @brief
 * @author
 * @copyright 2019
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#ifndef INCLUDE_DETECTION_HPP_
#define INCLUDE_DETECTION_HPP_

#include <opencv2/opencv.hpp>

#include <vector>

/**
 * Performs Histogram of Gradients detection of humans in images using Support Vector Machines.
 */
class Detection {
 public:
  /**
   * Initializes the HOG descriptor.
   */
  Detection();
  /**
   * Detects humans in images using HOG and the OpenCV SVM default people detector.
   * @param image
   * @return
   */
  std::vector<cv::Rect> detect(const cv::Mat& image);
 private:
  cv::HOGDescriptor hog;
};

#endif /* INCLUDE_DETECTION_HPP_ */
