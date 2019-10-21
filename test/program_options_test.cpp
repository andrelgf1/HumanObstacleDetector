/**
 * @file program_options_test.cpp
 * @brief Unit Test for ProgramOptions Class
 * @author Andre Gomes
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @copyright 2019 Andre Gomes, Pablo Sanhueza, Ryan Cunningham
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "program_options.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(ProgramOptionsTest, testNoOptions) {
  ProgramOptions options = ProgramOptions();

  try {
    /// first option is program name
    const char* argv[] = { "hi" };
    int argc = 1;

    /// if this doesn't throw an exception then the test will fail
    options.parse(argc, argv);
    FAIL();
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ("No options provided", e.what());
  }
}

TEST(ProgramOptionsTest, testGetValueNotProvided) {
  ProgramOptions options = ProgramOptions();

  /// first option is program name
  const char* argv[] = { "", "--positive-test-images-path", "" };
  int argc = 3;

  options.parse(argc, argv);

  /// if this doesn't throw an exception then the test will fail
  try {
    options.getValue("negative-test-images-path");
    FAIL();
  } catch (const std::invalid_argument& e) {
    EXPECT_STREQ("Invalid option: negative-test-images-path", e.what());
  }
}

TEST(ProgramOptionsTest, testGetValueProvided) {
  ProgramOptions options = ProgramOptions();

  /// first option is program name
  const char* argv[] = { "", "--positive-test-images-path", "" };
  int argc = 3;

  options.parse(argc, argv);

  /// if this throws an exception then the test will fail
  options.getValue("positive-test-images-path");
}
