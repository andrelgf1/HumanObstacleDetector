#ifndef INCLUDE_PROGRAM_OPTIONS_HPP_
#define INCLUDE_PROGRAM_OPTIONS_HPP_

#include <boost/program_options.hpp>

class ProgramOptions {
 public:
  ProgramOptions();
  void parse(int argc, char* argv[]);
  std::string getValue(const std::string& optionName);
 private:
  boost::program_options::options_description description;
  boost::program_options::variables_map optionValues;
  void print();
};

#endif /* INCLUDE_PROGRAM_OPTIONS_HPP_ */
