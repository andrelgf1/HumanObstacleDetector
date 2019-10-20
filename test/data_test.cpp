/**
 * @file data_test.cpp
 * @brief Unit Test for Data Class
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Pablo Sanhuez, Ryan Cunningham, Andre Gomes
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "data.hpp"

#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(DataTest, testLoadImages) {
  // load the positive testing images
  std::string imagesPath = "../test/images/positive/";
  std::vector<cv::Mat> images = Data::loadImages(imagesPath);

  // verify that 4 images are loaded
  size_t expected_eq = 4;
  EXPECT_EQ(expected_eq, images.size());
}
