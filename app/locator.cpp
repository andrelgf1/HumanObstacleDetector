#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include "locator.hpp"


Locator::Locator(){

}

Locator::Locator(cv::Mat rotationM, cv::Mat translationVec, cv::Mat intrinsicM):
 _rotationM(rotationM),
_transVec(translationVec),
_intrinsicM(intrinsicM) {

}

void Locator::checkMatrixSize(cv::Mat matrix, cv::Size size){

}

cv::Mat Locator::getRotationMatrix(){
  return _rotationM;
}
cv::Mat Locator::getTranslationVector(){
  return _transVec;
}
cv::Mat Locator::getInstrinsicMatrix(){
  return _intrinsicM;
}


void Locator::pixelVector() {

}

void Locator::setPixelData(cv::Rect &pixelData) {

}

cv::Rect Locator::getPixelData() {
  return pixelPoint;
}


void Locator::worldPos() {

}

void Locator::printPositions() {

}
