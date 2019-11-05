#ifndef _DGRAPHSCHEMA_H
#define _DGRAPHSCHEMA_H
#include <string>
#include <vector>

#include "./mygenerator.h"

class DGraphSchema : public MyGenerator {
 public:
  DGraphSchema(const std::vector<std::string> &controllers,
               const std::string &arguments);

  ~DGraphSchema();

  std::string generate();

 private:
  const std::vector<std::string> &controllers;
  const std::string &arguments;

  static void createFilterHeaderFile(std::ofstream &file,
                                     const std::string &className,
                                     const std::string &fileName,
                                     const std::string &content,
                                     const std::string &arguments);
  static void createFilterSourceFile(std::ofstream &file,
                                     const std::string &className,
                                     const std::string &fileName,
                                     const std::string &content,
                                     const std::string &arguments);
};
#endif
