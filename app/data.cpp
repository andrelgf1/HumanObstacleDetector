/**
 * @file data.cpp
 * @brief Loads data files (images).
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "data.hpp"

#include <string>
#include <vector>

cv::Mat Data::loadImage(const std::string& filePath) {
  return cv::imread(filePath);
}

std::vector<cv::Mat> Data::loadImages(const std::string& filesDir) {
  /// get all file names in directory
  std::vector<cv::String> fileNames;
  cv::glob(filesDir, fileNames);

  /// read each image and add to vector
  std::vector<cv::Mat> images;
  for (auto fileName : fileNames) {
    cv::Mat image = cv::imread(fileName);

    images.push_back(image);
  }

  return images;
}
