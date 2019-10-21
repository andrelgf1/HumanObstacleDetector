/**
 * @file data.hpp
 * @brief Loads data files (images).
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#ifndef INCLUDE_DATA_HPP_
#define INCLUDE_DATA_HPP_

#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

/**
 * @brief Handles image data loading.
 */
class Data {
 public:
  /**
   * Load an image.
   * @param filePath path to image
   * @return image
   */
  static cv::Mat loadImage(const std::string& filePath);
  /**
   * Load all images in a directory.
   * @param filesPath directory containing images
   * @return vector of images
   */
  static std::vector<cv::Mat> loadImages(const std::string& filesDir);
};

#endif /* INCLUDE_DATA_HPP_ */
