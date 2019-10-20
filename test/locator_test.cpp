/**
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @file locator_test.cpp
 * @brief Unit Tests for Locator
 * @copyright 2019 Pablo Sanhueza, Ryan Cunningham, Andre Gomes
 */

#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include "locator.hpp"

/**
 * Tests Default Constructor.
 */
TEST(LocatorTest, testDefaultLocator) {
  /// Create locator object
  Locator pos;
  cv::Mat rotationMatrix = pos.getRotationMatrix();
  cv::Mat transVector = pos.getTranslationVector();
  cv::Mat intrinsicMatrix = pos.getInstrinsicMatrix();

  /// Test values to ensure default constructor is initialized to correct values.
  cv::Mat rotationTest = (cv::Mat_< float > (3,3) << -0.75825, 0.3173, -0.56954, 0.65194, 0.36295, -0.66576, -0.0045332, -0.87612, -0.48207);
  cv::Mat transTest = (cv::Mat_< float > (1,3) << -18.2, -1738.4, 9274.8);
  cv::Mat intrinsicTest = (cv::Mat_< float > (3,3) << 633.319, 0.0, 494.641, 0.0, 635.66, 390.479, 0.0, 0.0, 1.0);

  cv::Mat diffTest1 = rotationMatrix != rotationTest;
  cv::Mat diffTest2 = transVector != transTest;
  cv::Mat diffTest3 = intrinsicMatrix != intrinsicTest;

  /// Boolean check to determine if test can pass. This is used since it EXPECT_EQ() doesn't like dealing with cv::Mat.
  EXPECT_TRUE(cv::countNonZero(diffTest1) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest2) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest3) == 0);

}


/**
 * Test Constructor.
 */
TEST(LocatorTest, testLocatorConstructor) {
  /// Create locator object
  cv::Mat rotation = (cv::Mat_< float > (3,3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);
  cv::Mat transVec = (cv::Mat_< float > (1,3) << 1, 1, 1);
  cv::Mat intrinsic = (cv::Mat_< float > (3,3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);

  Locator pos(rotation, transVec, intrinsic);

  /// Test values to ensure default constructor is initialized to correct values.
  cv::Mat diffTest1 = rotation != pos.getRotationMatrix();
  cv::Mat diffTest2 = transVec != pos.getTranslationVector();
  cv::Mat diffTest3 = intrinsic != pos.getInstrinsicMatrix();

  /// Boolean check to determine if test can pass. This is used since it EXPECT_EQ() doesn't like dealing with cv::Mat.
  EXPECT_TRUE(cv::countNonZero(diffTest1) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest2) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest3) == 0);

}


/**
 * Tests setPixelData() method from Locator Class.
 */
TEST(LocatorTest, testSetPixelData) {
  /// Create locator object
  Locator pos;
  /// Valid arguments to create rectangle
  int x = 0;
  int y = 0;
  int width = 10;
  int height = 20;

  /// Create rectangle...
  cv::Rect rect(x, y, width, height);

  /// Sets pixel data for testing
  pos.setPixelData(rect);


  EXPECT_EQ(rect, pos.getPixelData());

}

/**
 * Tests worldPos() method from Locator Class.
 */
TEST(LocatorTest, testWorldPos) {
  /// Create locator object
  Locator pos;
  /// Valid arguments to create rectangle
  int x = 0;
  int y = 0;
  int width = 0;
  int height = 0;

  /// Create rectangle...
  cv::Rect rect(x, y, width, height);

  /// Test Coordinate results computed by beforehand using formula -> [X, Y, Z] = (([u, v, 1] * Intrin_Matrix_Inv) - [tx, ty, tz] ) * Rot_Matrix_Inv
  cv::Mat testCoord = (cv::Mat_< float > (1,3) << 5.8195467, 6.8169351, 2.9474826);

  /// Sets pixel data for testing
  pos.setPixelData(rect);
  pos.worldPos();

  /// Takes difference of all elements in matrix and compares them
  cv::Mat diff = testCoord != pos.worldCoord;

  /// Boolean check to determine if test can pass. This is used since it EXPECT_EQ() doesn't like dealing with cv::Mat.
  EXPECT_TRUE(cv::countNonZero(diff) == 0);

}
