/**
 * @file locator_test.cpp
 * @brief Unit Tests for Locator
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Andre Gomes, Pablo Sanhueza, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include <gtest/gtest.h>

#include <vector>

#include <opencv2/opencv.hpp>

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

  /// Test values to ensure default constructor is initialized to correct
  /// values.
  cv::Mat rotationTest = (cv::Mat_< float > (3, 3)
      << 0.07579, -0.02684, -0.78892, 0.0, 0.15731, -0.61428, 0, 0, 1);
  cv::Mat transTest = (cv::Mat_< float > (1, 3) << 0, 0, 1);
  cv::Mat intrinsicTest = (cv::Mat_< float > (3, 3)
      << 633.319, 0.0, 494.641, 0.0, 635.66, 390.479, 0.0, 0.0, 1.0);

  cv::Mat diffTest1 = rotationMatrix != rotationTest;
  cv::Mat diffTest2 = transVector != transTest;
  cv::Mat diffTest3 = intrinsicMatrix != intrinsicTest;

  /// Boolean check to determine if test can pass. This is used since it
  /// EXPECT_EQ() doesn't like dealing with cv::Mat.
  EXPECT_TRUE(cv::countNonZero(diffTest1) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest2) == 0);
  EXPECT_TRUE(cv::countNonZero(diffTest3) == 0);
}

/**
 * Test Constructor.
 */
TEST(LocatorTest, testLocatorConstructor) {
  /// Create locator object
  cv::Mat rotation = (cv::Mat_< float > (3, 3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);
  cv::Mat transVec = (cv::Mat_< float > (1, 3) << 1, 1, 1);
  cv::Mat intrinsic = (cv::Mat_< float > (3, 3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);

  Locator pos(rotation, transVec, intrinsic);

  /// Test values to ensure default constructor is initialized to correct
  /// values.
  cv::Mat diffTest1 = rotation != pos.getRotationMatrix();
  cv::Mat diffTest2 = transVec != pos.getTranslationVector();
  cv::Mat diffTest3 = intrinsic != pos.getInstrinsicMatrix();

  /// Boolean check to determine if test can pass. This is used since it
  /// EXPECT_EQ() doesn't like dealing with cv::Mat.
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

  /// Test Coordinate results computed by beforehand using formula ->
  /// [X, Y, Z] = (([u, v, 1] * Intrin_Matrix_Inv) - [tx, ty, tz] ) *
  /// Rot_Matrix_Inv
  cv::Mat testCoord = (cv::Mat_< float > (1, 3) << 0, 0, 1);

  /// Sets pixel data for testing
  pos.setPixelData(rect);
  pos.worldPos();

  /// Takes difference of all elements in matrix and compares them
  cv::Mat diff = testCoord != pos.worldCoord;

  /// Boolean check to determine if test can pass. This is used since it
  /// EXPECT_EQ() doesn't like dealing with cv::Mat.
  EXPECT_TRUE(cv::countNonZero(diff) == 0);

}
