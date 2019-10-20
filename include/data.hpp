#ifndef INCLUDE_DATA_HPP_
#define INCLUDE_DATA_HPP_

#include <opencv2/opencv.hpp>

class Data {
 public:

  static cv::Mat loadImage(const std::string& filePath);

  static std::vector<cv::Mat> loadImages(const std::string& filesDir);
};

#endif /* INCLUDE_DATA_HPP_ */
