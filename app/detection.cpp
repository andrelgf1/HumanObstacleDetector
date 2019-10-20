/**
 * @file detection.cpp
 * @brief
 * @author
 * @copyright 2019
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "detection.hpp"

#include <opencv2/opencv.hpp>

#include <vector>

Detection::Detection() {
  // set the default people detector SVM to the HOG detector
  hog.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());
}

std::vector<cv::Rect> Detection::detect(const cv::Mat& image) {
  // detect humans and get the bounding boxes for each
  std::vector<cv::Rect> detections;
  hog.detectMultiScale(image, detections);

  return detections;
}
