/**
 * @file detection.hpp
 * @brief Detects humans in images using HOGDescriptor and SVM.
 * @author Pablo Sanhueza
 * @author Andre Gomes
 * @author Ryan Cunningham
 * @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#ifndef INCLUDE_DETECTION_HPP_
#define INCLUDE_DETECTION_HPP_

#include <vector>

#include <opencv2/opencv.hpp>

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
