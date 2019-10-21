/**
 * @file detection.cpp
 * @brief Detects humans in images using HOGDescriptor and SVM.
 * @author Pablo Sanhueza
 * @author Andre Gomes
 * @author Ryan Cunningham
 * @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "detection.hpp"

#include <vector>

#include <opencv2/opencv.hpp>

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
