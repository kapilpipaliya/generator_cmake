
#include "./DGraphSchema.h"
//#include <drogon/DrTemplateBase.h>
//#include <drogon/utils/Utilities.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "pystring/pystring.hpp"
DGraphSchema::DGraphSchema(const std::vector<std::string> &controllers, const std::string &arguments) : controllers(controllers), arguments(arguments) {}
DGraphSchema::~DGraphSchema() {}
std::string DGraphSchema::generate()
{
  if (controllers.size() < 1) { std::cout << "Invalid parameters!" << std::endl; }
  for (auto className : controllers)
  {
    auto output_dir = getOutputPath(cppTimePath, className);
    std::regex regex("::");
    std::string fileName = std::regex_replace(className, regex, std::string("_"));
    std::string headFileName = output_dir + fileName + "Dgraph.h";
    std::string sourceFilename = output_dir + fileName + "Dgraph.cpp";
    createDirectory(headFileName);
    auto content1 = read_all(headFileName);
    auto content2 = read_all(sourceFilename);
    {
      // overwrite without confirmation:
      /*
      std::ifstream iHeadFile(headFileName.c_str(), std::ifstream::in);
      std::ifstream iSourceFile(sourceFilename.c_str(), std::ifstream::in);

      if (iHeadFile || iSourceFile) {
        std::cout << "The file you want to create already exists, "
                     "overwrite it(y/n)?"
                  << std::endl;
        auto in = getchar();
        (void)getchar();  // get the return key
        if (in != 'Y' && in != 'y') {
          std::cout << "Abort!" << std::endl;
          exit(0);
        }
      }
      */
    }
    std::ofstream oHeadFile(headFileName.c_str(), std::ofstream::out);
    std::ofstream oSourceFile(sourceFilename.c_str(), std::ofstream::out);
    if (!oHeadFile || !oSourceFile)
    {
      perror("");
      exit(1);
    }
    std::cout << "create a DGraph Schema:" << className << std::endl;
    createFilterHeaderFile(oHeadFile, className, fileName, content1, arguments);
    createFilterSourceFile(oSourceFile, className, fileName, content2, arguments);
  }
  return "created a service: ";
}
void DGraphSchema::createFilterHeaderFile(std::ofstream &file, const std::string &className, const std::string &fileName, const std::string &content, const std::string &arguments)
{
  file << "#pragma once\n";
  file << "#include \"time/dgraphservicebase.h\"\n";
  std::string class_name = className;
  std::string namepace_path = "/";
  auto pos = class_name.find("::");
  size_t namespaceCount = 0;
  file << "namespace timeservice\n{\n";
  while (pos != std::string::npos)
  {
    ++namespaceCount;
    auto namespaceName = class_name.substr(0, pos);
    class_name = class_name.substr(pos + 2);
    file << "namespace " << namespaceName << "\n";
    namepace_path.append(namespaceName).append("/");
    file << "{\n";
    pos = class_name.find("::");
  }
  class_name += "DGraph";
  file << "class " << class_name << ": public DGraphServiceBase\n";
  file << "{\n";
  file << "  public:\n";
  file << "    " << class_name << "();\n";
  file << "  void run();\n";
  file << "  private:\n";
  auto find_alter = find_section_in_string(arguments, "# alter");
  if (!find_alter.empty()) { file << "  void alter();\n"; }
  auto find_query = find_section_in_string(arguments, "# query");
  if (!find_query.empty()) { file << "  void query();\n"; }
  auto find_mutation = find_section_in_string(arguments, "# mutation");
  if (!find_mutation.empty()) { file << "  void mutation();\n"; }
  file << "  // manual_part\n";
  auto find = find_section_in_string(content, "// manual_part");
  file << find;
  file << "  // manual_part_end\n";
  file << "};\n";
  if (namespaceCount > 0)
  {
    do {
      if (namespaceCount > 0) { --namespaceCount; }
      file << "}\n";
    } while (namespaceCount > 0);
  }
  file << "}\n";
}
void DGraphSchema::createFilterSourceFile(std::ofstream &file, const std::string &className, const std::string &fileName, const std::string &content, const std::string &arguments)
{
  file << "#include \"./" << fileName << "Dgraph.h\"\n";
  auto class_name = "timeservice::" + className;
  class_name += "DGraph";
  std::vector<std::string> v;
  pystring::split(className, v, "::");
  file << class_name << "::" + v.at(v.size() - 1) + "DGraph()\n";
  file << "{}\n";
  auto find_alter = find_section_in_string(arguments, "# alter");
  if (!find_alter.empty())
  {
    file << "void " << class_name << "::alter()\n";
    file << "{\n";
    file << "  // manual_part_alter\n";
    auto find = find_section_in_string(content, "// manual_part_alter");
    file << find;
    file << "  // manual_part_alter_end\n";
    file << "}\n";
  }
  auto find_query = find_section_in_string(arguments, "# query");
  if (!find_query.empty())
  {
    file << "void " << class_name << "::query()\n";
    file << "{\n";
    file << "  // manual_part_query\n";
    auto find = find_section_in_string(content, "// manual_part_query");
    file << find;
    file << "  // manual_part_query_end\n";
    file << "}\n";
  }
  auto find_mutation = find_section_in_string(arguments, "# mutation");
  if (!find_mutation.empty())
  {
    file << "void " << class_name << "::mutation()\n";
    file << "{\n";
    file << "  // manual_part_mutation\n";
    auto find = find_section_in_string(content, "// manual_part_mutation");
    file << find;
    file << "  // manual_part_mutation_end\n";
    file << "}\n";
  }
  file << "void " << class_name << "::run()\n";
  file << "{\n";
  file << "  // manual_part_run\n";
  auto find = find_section_in_string(content, "// manual_part_run");
  file << find;
  file << "  // manual_part_run_end\n";
  file << "}\n";
  file << "  // manual_part\n";
  auto find2 = find_section_in_string(content, "// manual_part");
  file << find2;
  file << "  // manual_part_end\n";
}
