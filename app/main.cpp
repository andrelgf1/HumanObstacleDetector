/**
 * @file main.cpp
 * @brief Script to demo human obstacle detection.
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Andre Gomes, Pablo Sanhueza, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>
#include <vector>

#include "data.hpp"
#include "detection.hpp"
#include "locator.hpp"
#include "program_options.hpp"

int main(int argc, const char* argv[]) {
  /// parse the command line parameters
  ProgramOptions options = ProgramOptions();
  options.parse(argc, argv);

  Detection detector = Detection();

  Locator locator = Locator();

  /// get the directory containing positive test images
  std::string testPath = options.getValue("positive-test-images-path");
  std::vector<cv::Mat> testImages = Data::loadImages(testPath);

  /// test images with humans
  for (auto testImage : testImages) {
    /// detect humans in image
    std::vector<cv::Rect> detections = detector.detect(testImage);

    /// if there were detections, get the bounding box and location
    if (detections.size() > 0) {
      for (auto detection : detections) {
        /// draw the detected bounding box and show the image
        cv::rectangle(testImage, detection, cv::Scalar(0, 255, 0), 3);
        cv::imshow("Images", testImage);

        /// get the real world position from the detection
        locator.setPixelData(detection);
        locator.worldPos();
        locator.printPositions();
      }

      /// display the image for 1 second
      cv::waitKey(1000);
    }
  }
}
