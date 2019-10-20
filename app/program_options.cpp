/**
 * @file program_options.cpp
 * @brief This class allows for command line arguments for file paths.
 * @author Pablo Sanhueza
 * @author Ryan Cunningham
 * @author Andre Gomes
 * @copyright 2019 Pablo Sanhueza, Ryan Cunningham, Andre Gomes
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#include "program_options.hpp"

#include <iostream>
#include <string>

namespace po = boost::program_options;

ProgramOptions::ProgramOptions()
    : description(po::options_description("Human Obstacle Detector")) {
  /// add program options
  description.add_options()("help,h", "Help Message")(
      "positive-test-images-path,p", po::value<std::string>()->required(),
      "Path to directory containing positive test images")(
      "negative-test-images-path,n", po::value<std::string>()->required(),
      "Path to directory containing negative test images");
}

void ProgramOptions::parse(int argc, const char* argv[]) {
  /// get and store the parsed options
  po::store(po::command_line_parser(argc, argv).options(description).run(),
            optionValues);

  /// if no options provided, stop program and print options
  if (optionValues.size() == 0) {
    print();
    throw std::invalid_argument("No options provided");
  }

  /// if help option provided, stop program and print options
  if (optionValues.count("help")) {
    print();
    exit(0);
  }
}

std::string ProgramOptions::getValue(const std::string& optionName) {
  /// if the option is not provided, throw an exception and print the options
  if (!optionValues.count(optionName)) {
    print();
    throw std::invalid_argument("Invalid option: " + optionName);
  }

  /// get the option value
  return optionValues[optionName].as<std::string>();
}

void ProgramOptions::print() {
  /// print to stdout
  description.print(std::cout);
}
