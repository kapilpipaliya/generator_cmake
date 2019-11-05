#ifndef MYGENERATOR_H
#define MYGENERATOR_H
#include <string>
class MyGenerator {
 public:
  MyGenerator();
  void generateFile(std::string filename);
  void createDirectory(const std::string &filename);
  static std::string find_section_in_file(const std::string &filename,
                                          const std::string section_name);
  static std::string find_section_in_string(const std::string &str,
                                            const std::string &section_name);
  static std::string find_section_in_string(
      const std::string &str, const std::string &section_name_start,
      const std::string &section_name_end);
  static std::string read_all(const std::string &filename);
  static std::string getOutputPath(const std::string &outputdir,
                                   const std::string &className);

  static long countMatchInRegex(std::string s, std::string re);
  std::string drogonPath;
  std::string cppTimePath;
  std::string cppServicePath;
};

#endif  // MYGENERATOR_H
