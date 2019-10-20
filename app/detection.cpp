#include "detection.hpp"

#include <opencv2/opencv.hpp>

#include <vector>

Detection::Detection() {

}

std::vector<cv::Rect> Detection::detect(const cv::Mat& image) {
  cv::Rect nothing;
  std::vector<cv::Rect> empty = {nothing};

  return empty;
}
