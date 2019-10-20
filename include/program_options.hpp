/**
 * @file program_options.hpp
 * @brief Class allows for command line arguments for setting path.
 * @author Ryan Cunningham
 * @author Pablo Sanhueza
 * @author Andre Gomes
 * @copyright 2019 Ryan Cunningham, Pablo Sanhueza, Andre Gomes
 * Distributed under the BSD License (license terms found in LICENSE or at https://www.freebsd.org/copyright/freebsd-license.html)
 */

#ifndef INCLUDE_PROGRAM_OPTIONS_HPP_
#define INCLUDE_PROGRAM_OPTIONS_HPP_

#include <boost/program_options.hpp>

/**
 * Defines available program options and retrieves option values.
 */
class ProgramOptions {
 public:
  ProgramOptions();

  /**
   * Parse command line arguments as options.
   * @param argc the number of arguments
   * @param argv the list of arguments
   */
  void parse(int argc, const char* argv[]);

  /**
   * Gets the value for an options
   * @param optionName the name of the option
   * @return the option value
   */
  std::string getValue(const std::string& optionName);

 private:
  boost::program_options::options_description description;
  boost::program_options::variables_map optionValues;

  /**
   * Prints the options description to stdout.
   */
  void print();
};

#endif /* INCLUDE_PROGRAM_OPTIONS_HPP_ */

