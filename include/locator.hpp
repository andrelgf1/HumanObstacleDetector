/** @author Pablo Sanhueza
 *  @author Andre Gomes
 *  @author Ryan Cunningham
 *
 *  @file locator.hpp
 *
 *  @brief End result of class is to return the position of the object desired. Class will receive dimensions and starting pixel
 *  position of a bounding box, and from there determine the world coordinate position depending on the camera.
 *  Here we assume the intrinsic and extrinsic parameters of the camera.
 *
 *  @copyright 2019 Pablo Sanhueza, Andre Gomes, Ryan Cunningham
 */

#ifndef INCLUDE_LOCATOR_HPP_
#define INCLUDE_LOCATOR_HPP_

#include <opencv2/opencv.hpp>
#include <vector>

class Locator {
 public:
  /// World Coordinates in cv::Mat datatype
   cv::Mat worldCoord;

   /**
    * @brief Default constructor for locator class. This is for demo purposes. The non-default constructor should be used to set camera parameters in cv::Mat format
    * @param none
    * @return none
    */
   Locator ();

   /**
    * @brief Constructor to set camera parameters. All parameters should be in matrix form (cv::Mat).
    * @param rotationM, translationVec, intrinsicM These are the parameters in which to get accurate 3D position.
    * @return none
    */
   Locator(cv::Mat rotationM, cv::Mat translationVec, cv::Mat intrinsicM);

   /**
    * @brief Receives pixel data as type cv::Rect, and sets it to the private attribute pixelPoint. It later uses the private method pixelVector()
    * to extract important information of data given, and creates a vector of type cv::Mat.
    * @param pixelData pixel data which is given as bounding box information
    * @return none
    */
   void setPixelData(cv::Rect &pixelData);


   /**
    * @brief Gets pixelData
    * @param none
    * @return none
    */
   cv::Rect getPixelData();


   /**
    * @brief Calculations to obtain Real World Coordinates. Highly important to detect distance of object.
    * @param none
    * @return worldCoord
    */
   cv::Mat worldPos();


   /**
    * @brief Prints the Real World Coordinates
    * @param none
    * @return none
    */
   void printPositions();


   /**
    * @brief Getter method to return rotation matrix. Mostly used for unit testing.
    * @param none
    * @return _rotationM Rotation matrix as cv::Mat
    */
   cv::Mat getRotationMatrix();


   /**
    * @brief Getter method to return translation vector. Mostly used for unit testing.
    * @param none
    * @return _transVec Trasnlation vector as cv::Mat
    */
   cv::Mat getTranslationVector();


   /**
    * @brief Getter method to return intrinsic matrix. Mostly used for unit testing.
    * @param none
    * @return _intrinsicM Intrinsic Matrix as cv::Mat
    */
   cv::Mat getInstrinsicMatrix();

 private:

   /// Rotation Matrix of Camera. This is part of the extrinsic matrix to calculate world coordinates.
   cv::Mat _rotationM;

   /// Translation vector. Also part of extrinsic parameters to calculate world coordinates.
   cv::Mat _transVec;

   /// Intrinsic parameters of camera. This includes fx, fy, cx, and cy.
   cv::Mat _intrinsicM;

   // Pixel Data to obtain pixel coordinates.
   cv::Rect pixelPoint;

   // Pixel Coordinates as a 1x3 vector.
   cv::Mat pixelCoord;


   /**
    * @brief Converts Pixel data given as cv::Rec into a 1x3 vector. Here we calculate the midpoint of the bounding box
    * and use this as the pixel coordinates. For example, [128, 340, 1]. The 1 at the end of the vector is for correct matrix calculations.
    * @param none
    * @return none
    */
   void pixelVector();


   /**
    * @brief Checks Matrix sizes
    * @param matrix, size The matrix is matrix to be checked with a specific size.
    * @return none
    */
   void checkMatrixSize(cv::Mat matrix, cv::Size size);

};


#endif /* INCLUDE_LOCATOR_HPP_ */
