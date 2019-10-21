/**
 * @file main.cpp
 * @brief Script to demo human obstacle detection.
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Andre Gomes, Pablo Sanhueza, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include <iostream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <opencv2/opencv.hpp>

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

  std::vector<cv::Mat> testImages;

  try {
    /// get the directory containing positive test images
    std::string testPath = options.getValue("positive-test-images-path");
    std::vector<cv::Mat> positiveImages = Data::loadImages(testPath);
    testImages.insert(testImages.end(),
                      positiveImages.begin(), positiveImages.end());
  } catch (std::invalid_argument& e) {
    /// do nothing if the argument wasn't provided
  }

  try {
    /// get the directory containing negative test images
    std::string testPath = options.getValue("negative-test-images-path");
    std::vector<cv::Mat> negativeImages = Data::loadImages(testPath);
    testImages.insert(testImages.end(),
                      negativeImages.begin(), negativeImages.end());
  } catch (std::invalid_argument& e) {
    /// do nothing if the argument wasn't provided
  }

  int imageNumber = 1;
  /// test images for human detection
  for (auto testImage : testImages) {
    std::cout << "Image: " << imageNumber++ << std::endl;

    /// detect humans in image
    std::vector<cv::Rect> detections = detector.detect(testImage);

    /// if there were no detection, print a message saying so
    if (detections.size() == 0) {
      std::cout << "No humans detected!" << std::endl;
    } else {
      /// if there were detections, get the bounding box and location
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
