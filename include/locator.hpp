#ifndef INCLUDE_LOCATOR_HPP_
#define INCLUDE_LOCATOR_HPP_

#include <opencv2/opencv.hpp>
#include <vector>

class Locator {
 public:
   cv::Mat worldCoord;

   Locator ();

   Locator(cv::Mat rotationM, cv::Mat translationVec, cv::Mat intrinsicM);
   void setPixelData(cv::Rect &pixelData);
   cv::Rect getPixelData();
   void worldPos();
   void printPositions();
   cv::Mat getRotationMatrix();
   cv::Mat getTranslationVector();
   cv::Mat getInstrinsicMatrix();

 private:
   cv::Mat _rotationM;
   cv::Mat _transVec;
   cv::Mat _intrinsicM;
   cv::Rect pixelPoint;
   cv::Mat pixelCoord;

   void pixelVector();
   void checkMatrixSize(cv::Mat matrix, cv::Size size);

};


#endif /* INCLUDE_LOCATOR_HPP_ */
