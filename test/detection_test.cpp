/**
 * @file detection_test.cpp
 * @brief Unit Test for Detection Class.
 * @author Andre Gomes
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @copyright 2019 Andre Gomes, Pablo Sanhueza, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "detection.hpp"

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

#include "data.hpp"

TEST(DetectionTest, testNoHumanInImage) {
  Detection detector = Detection();

  // load the negative test images
  std::string imagesPath = "../test/images/negative/";
  std::vector<cv::Mat> images = Data::loadImages(imagesPath);

  // verify each image detects 0 humans
  size_t expected_eq = 0;
  for (auto image : images) {
    EXPECT_EQ(expected_eq, detector.detect(image).size());
  }
}

TEST(DetectionTest, testHumanInImage) {
  Detection detector = Detection();

  // load the negative test images
  std::string imagesPath = "../test/images/positive/";
  std::vector<cv::Mat> images = Data::loadImages(imagesPath);

  // verify each image detects at least 1 human
  size_t expected_lt = 0;
  for (auto image : images) {
    EXPECT_LT(expected_lt, detector.detect(image).size());
  }
}

TEST(DetectionTest, testMulitpleHumansInImage) {
  Detection detector = Detection();

  // load the positive test image that has more than one human
  std::string imagePath = "../test/images/positive/person_014.bmp";
  cv::Mat image = Data::loadImage(imagePath);

  // verify the image has more than 1 human
  size_t expected_lt = 1;
  EXPECT_LT(expected_lt, detector.detect(image).size());
}
