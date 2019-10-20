#include "data.hpp"

#include <string>
#include <vector>

cv::Mat Data::loadImage(const std::string& filePath) {
  cv::Mat zeros = cv::Mat::zeros(1,1, CV_64F);
  return zeros;
}

std::vector<cv::Mat> Data::loadImages(const std::string& filesDir) {
  cv::Mat zeros = cv::Mat::zeros(1,1, CV_64F);
  std::vector<cv::Mat> unUsed = {zeros};
  return unUsed;
}
