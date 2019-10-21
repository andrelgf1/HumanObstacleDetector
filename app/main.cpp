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
        /// get the real world position from the detection
        locator.setPixelData(detection);
        cv::Mat location = locator.worldPos();
        locator.printPositions();
        std::cout << location << std::endl;

        /// draw the detected bounding box
        cv::rectangle(testImage, detection, cv::Scalar(0, 255, 0), 3);

        /// get a list of x, y, and z coordinates as strings
        std::stringstream locationText;
        locationText << location;
        std::vector<std::string> locationTextParts;
        std::string locationTextPart;
        while (std::getline(locationText, locationTextPart, ',')) {
          locationTextParts.push_back(locationTextPart);
        }

        /// print the coordinates in the bounding box
        cv::putText(testImage, locationTextParts[0],
                    cv::Point(detection.x, detection.y + 30),
                    cv::FONT_HERSHEY_SIMPLEX, 0.9, cv::Scalar(0, 255, 0), 2);
        cv::putText(testImage, locationTextParts[1],
                    cv::Point(detection.x, detection.y + 60),
                    cv::FONT_HERSHEY_SIMPLEX, 0.9, cv::Scalar(0, 255, 0), 2);
        cv::putText(testImage, locationTextParts[2],
                    cv::Point(detection.x, detection.y + 90),
                    cv::FONT_HERSHEY_SIMPLEX, 0.9, cv::Scalar(0, 255, 0), 2);

        /// show the image
        cv::imshow("Images", testImage);
      }

      /// display the image for 1 second
      cv::waitKey(4000);
    }
  }
}
