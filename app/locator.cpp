/**
 * @file locator.cpp
 * @brief End result of class is to return the position of the object desired. Class will receive dimensions and starting pixel
 * position of a bounding box, and from there determine the world coordinate position depending on the camera.
 * Here we assume the intrinsic and extrinsic parameters of the camera.
 * @author Pablo Sanhueza
 * @author Andre Gomes
 * @author Ryan Cunningham
 * @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "locator.hpp"

#include <iostream>
#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

Locator::Locator() {
  /// rotation matrix is conformed of [r1 r2 translation].
  /// r3 isn't necessary because it is a redundant cross product of the first
  /// 2 columns
  _rotationM = (cv::Mat_< float > (3, 3)
      << 0.07579, -0.02684, -0.78892, 0.0, 0.15731, -0.61428, 0, 0, 1);
  _transVec = (cv::Mat_< float > (1, 3) << 0, 0, 1);
  _intrinsicM = (cv::Mat_< float > (3, 3)
      << 633.319, 0.0, 494.641, 0.0, 635.66, 390.479, 0.0, 0.0, 1.0);
}

Locator::Locator(cv::Mat rotationM, cv::Mat translationVec, cv::Mat intrinsicM):
  _rotationM(rotationM),
  _transVec(translationVec),
  _intrinsicM(intrinsicM) {
  /// Check size of matrix
  checkMatrixSize(rotationM, cv::Size(3, 3));
  checkMatrixSize(translationVec, cv::Size(3, 1));
  checkMatrixSize(intrinsicM, cv::Size(3, 3));
}

void Locator::checkMatrixSize(cv::Mat matrix, cv::Size size) {
  if (matrix.size().width != size.width
      && matrix.size().height != size.height) {
    throw std::invalid_argument("Invalid Shape of Vector "
        "(Matrix shape (3x3) and Vector shape is (1x3)");
  }
}

cv::Mat Locator::getRotationMatrix() {
  return _rotationM;
}
cv::Mat Locator::getTranslationVector() {
  return _transVec;
}
cv::Mat Locator::getInstrinsicMatrix() {
  return _intrinsicM;
}


void Locator::pixelVector() {
  /// Uses the public attribute of cv::Rec object to obtain width and height
  /// of bounding box.
  int midX = pixelPoint.width / 2;
  int midY = pixelPoint.height;

  /// Gets pixel coordinate and converts to a 1x3 vector.
  pixelCoord = (cv::Mat_<float>(1, 3) << pixelPoint.x + midX,
      pixelPoint.y + midY, 1);
}

void Locator::setPixelData(cv::Rect &pixelData) {
  /// Sets pixelData to attribute pixelPoint
  pixelPoint = pixelData;
  pixelVector();
}

cv::Rect Locator::getPixelData() {
  return pixelPoint;
}

cv::Mat Locator::worldPos() {
  /// Calculates real world coordinate with intrinsic and extrinsic camera
  /// parameters.
  /// worldCoord = (((pixelCoord * _intrinsicM.inv()) - _transVec ) *
  /// _rotationM.inv()) / 1000;

  cv::Mat homography = _intrinsicM*_rotationM;
  worldCoord = pixelCoord * homography.inv();
  return worldCoord;
}

void Locator::printPositions() {
  /// Prints position of object detected (human in this case).
  std::cout << "Position of Object in meters [x,y,z]: " << worldCoord
      << std::endl;
}
