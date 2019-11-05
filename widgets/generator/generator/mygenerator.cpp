#include "./mygenerator.h"

#include <experimental/filesystem>
#include <fstream>
#include <iostream>
#include <regex>

#include "thirdparty/pystring/pystring.h"
MyGenerator::MyGenerator() {
  cppTimePath = "/home/kapili3/jdragon/service/time/";
  cppServicePath = "/home/kapili3/jdragon/service";
  drogonPath = "/home/kapili3/jdragon/";
}

void MyGenerator::generateFile(std::string tmpl_file) {
  // not useful test:
  find_section_in_file(tmpl_file, "--generate controller");
  std::string headFileName = tmpl_file + ".txt";
  createDirectory(headFileName);
  std::ofstream oHeadFile(headFileName.c_str(), std::ofstream::out);
  oHeadFile << "hi how are you";
}

void MyGenerator::createDirectory(const std::string &filename) {
  std::experimental::filesystem::path p{filename};
  std::string parentDir = p.parent_path();
  if (!std::experimental::filesystem::exists(parentDir)) {
    std::experimental::filesystem::create_directories(parentDir);
  }
}

std::string MyGenerator::find_section_in_file(const std::string &filename,
                                              const std::string section_name) {
  // read file:
  std::string lines = read_all(filename);
  return find_section_in_string(lines, section_name);
}

std::string MyGenerator::find_section_in_string(
    const std::string &str, const std::string &section_name) {
  return find_section_in_string(str, section_name, section_name + +"_end");
}

std::string MyGenerator::find_section_in_string(
    const std::string &str, const std::string &section_name_start,
    const std::string &section_name_end) {
  std::regex regex(
      section_name_start + R"(\n([\W\w\n]*?).*)" + section_name_end,
      std::regex_constants::ECMAScript | std::regex_constants::icase |
          std::regex_constants::extended);
  std::smatch match;
  if (std::regex_search(str, match, regex)) {
    //    for (size_t i = 0; i < controller_match.size(); ++i)
    //      std::cout << i << ": " << controller_match[i] << '\n';
    return match[1];
  }
  return "";
}

std::string MyGenerator::read_all(const std::string &filename) {
  std::ifstream istrm(filename, std::ios::in);
  istrm.seekg(0, std::ios::beg);
  return {std::istreambuf_iterator<char>{istrm},
          std::istreambuf_iterator<char>{}};
}

std::string MyGenerator::getOutputPath(const std::string &outputdir,
                                       const std::string &className) {
  std::vector<std::string> spiltv;
  pystring::split(className, spiltv, "::");
  std::string result{outputdir};
  for (unsigned long i = 0; i < spiltv.size(); ++i) {
    result += pystring::lower(spiltv[i]) + "/";
  }
  return result;
}
// https://stackoverflow.com/questions/8283735/count-number-of-matches
long MyGenerator::countMatchInRegex(std::string s, std::string re) {
  std::regex words_regex(re);
  auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
  auto words_end = std::sregex_iterator();

  return std::distance(words_begin, words_end);
}
